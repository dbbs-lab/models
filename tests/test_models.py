import unittest, efel, arborize, nrnsub
import arborize.unittest.protocols as protocols
import arborize.unittest.setups as setups
from patch import p
import dbbs_models
from numpy.random import default_rng
import random

# class TestGranule(arborize.TestCase):
#     setUp = setups.SingleCell(dbbs_models.GranuleCell)
#     test_soma_current = protocols.CurrentClamp(dur=500, skip=100, freq=15.0)


class TestPurkinje(arborize.TestCase):
    setUp = setups.SingleCell(dbbs_models.PurkinjeCellModel)
    test_autorhythm = protocols.Autorhythm(dur=500, skip=100, freq=15.0)


class TestBasket(arborize.TestCase):
    setUp = setups.SingleCell(dbbs_models.BasketCellModel)
    test_autorhythm = protocols.Autorhythm(dur=500, skip=100, freq=15.0)


class TestGolgi(arborize.TestCase):
    setUp = setups.SingleCell(dbbs_models.GolgiCellModel)
    input_conductance = 54000  # pS
    gaba_conductance = 3200
    autorhythm = 15.0

    test_autorhythm = protocols.Autorhythm(dur=500, skip=100, freq=autorhythm)
    test_input_conductance = protocols.InputConductance(g=input_conductance, places=-3)

    def test_gaba_conductance(self):
        baseline_setup = setups.SingleCell(dbbs_models.GolgiCellModel)
        baseline = protocols.InputConductance(rec_offset=49.15)
        protocol = protocols.InputConductance(
            g=self.gaba_conductance, rec_offset=49.15, places=-2
        )
        baseline_setup.setup(self)
        baseline.prepare(baseline_setup)
        protocol.prepare(self.setup)
        gc = self.setup.subjects["main"]
        syn = gc.create_synapse(gc.basal_dendrites[0], "GABA")
        syn.stimulate(start=250, number=1)
        i_gaba = syn.record()
        protocol.run()
        baseline_results = baseline.results(baseline_setup)
        results = protocol.results(self.setup)
        g_gaba = results.get("main.g") - baseline_results.get("main.g")
        results.set("main.g", g_gaba)
        protocol.asserts(self, results)

    def test_ei_balance(self, n_e=900, n_i=2000, f_e=1, f_i=10, c_e=0, c_i=0):
        setup = self.setup
        setup.init_simulator(tstop=9000)
        gc = setup.subjects["main"]
        dnd = gc.dendrites
        bsd = gc.basal_dendrites
        apd = gc.apical_dendrites
        epf = [
            gc.create_synapse(random.choice(apd), "AMPA_PF")
            for _ in range(int(n_e * 0.85))
        ]
        ea = [
            (
                gc.create_synapse(s := random.choice(bsd), "AMPA_AA"),
                gc.create_synapse(random.choice(bsd), "NMDA"),
            )
            for _ in range(int(n_e * 0.15))
        ]
        i = [gc.create_synapse(random.choice(bsd), "GABA") for _ in range(n_i)]
        t = p.time

        def poisson(rate=1.0, t_start=0, t_stop=1150):
            rng = default_rng()
            t_n = t_start
            while True:
                t_n += rng.exponential(scale=1000 / rate)
                if t_n < t_stop:
                    yield t_n
                else:
                    break

        def corr_poiss_stim(syns, rate, corr, t_start, t_stop):
            shared = list(poisson(t_start=t_start, t_stop=t_stop, rate=rate))
            raster = []
            for syn in syns:
                unique = list(poisson(t_start=t_start, t_stop=t_stop, rate=rate))
                combined = random.choices(
                    shared, k=int(round(len(shared) * corr))
                ) + random.choices(unique, k=int(round(len(unique) * (1 - corr))))
                if not isinstance(syn, tuple):
                    syn = [syn]
                for s in syn:
                    for spike in combined:
                        s.stimulate(number=1, start=spike)
                raster.append(combined)
            return raster

        e_inp = corr_poiss_stim(epf, f_e, c_e, 3000, 9000) + corr_poiss_stim(
            ea, f_e, c_e, 3000, 9000
        )
        i_inp = corr_poiss_stim(i, f_i, c_i, 6000, 9000)

        p.finitialize()
        p.run()

        import plotly.graph_objs as go
        from plotly.subplots import make_subplots

        fig = make_subplots(rows=3, cols=1, shared_xaxes=True)
        fig.add_trace(go.Scatter(x=list(p.time), y=list(gc.Vm)), row=3, col=1)
        for i, train in enumerate(e_inp):
            fig.add_trace(
                go.Scatter(
                    x=train,
                    y=[i] * len(train),
                    mode="markers",
                    marker=dict(size=2, symbol="square", color="red"),
                ),
                row=1,
                col=1,
            )
        for i, train in enumerate(i_inp):
            fig.add_trace(
                go.Scatter(
                    x=train,
                    y=[i] * len(train),
                    mode="markers",
                    marker=dict(size=2, symbol="square", color="blue"),
                ),
                row=2,
                col=1,
            )

        from arborize.unittest._helpers import ezfel

        fq = ezfel(T=list(p.time), signal=list(gc.Vm)).Spikecount[0]
        fig.update_layout(title_text=f"Golgi cell E/I ({fq}Hz)")
        fig.show()

    # def test_single_gaba_conductance(self):
    #     synapses = [
    #         {
    #             "type": "GABA",
    #             "location": lambda cell, i: random.choice(cell.basal_dendrites),
    #             "stimulation": [
    #                 {"start": 250, "number": 1, "interval": 0, "noise": False}
    #             ],
    #         }
    #     ]
    #     results = run_protocol(
    #         "GolgiCell",
    #         "voltage_clamp_with_synapses",
    #         voltage=-80,
    #         holding=-70,
    #         synapses=dill.dumps(synapses),
    #     )
    #     current = results.get("current")
    #     gaba = results.get("GABA.currents")
    #     i = current.x
    #     t = current.t
    #     dv = -0.01
    #     peak = 10053
    #     di = i[peak] * 10e-9 - i[7866] * 10e-9
    #     g = di / dv
    #     gmax_gaba = g - self.input_conductance
    #     self.assertAlmostEqual(self.gaba_conductance, g, 3)
    #
    # def test_serial_halfgap_resting(self):
    #     results = run_multicell(
    #         "network",
    #         [
    #             ("GolgiCell", "sender"),
    #             ("GolgiCell", "receiver"),
    #         ],
    #         connections=[
    #             ("gap_s", "sender", "receiver", "dendrites[0]", "dendrites[0]")
    #         ],
    #         recorders={
    #             "Currents": [
    #                 ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"]
    #             ]
    #         },
    #         duration=300,
    #     )
    #
    # def test_serial_halfgap_response(self):
    #     results = run_multicell(
    #         "network",
    #         [
    #             ("GolgiCell", "sender"),
    #             ("GolgiCell", "receiver"),
    #         ],
    #         connections=[
    #             ("gap_s", "sender", "receiver", "dendrites[0]", "dendrites[0]")
    #         ],
    #         stimuli=[["sender", "AMPA_AA", "dendrites[0]", 100, 10, 10]],
    #         recorders={
    #             "Currents": [
    #                 ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"]
    #             ]
    #         },
    #         duration=300,
    #     )
    #
    # def test_serial_fullgap_response(self):
    #     results = run_multicell(
    #         "network",
    #         [
    #             ("GolgiCell", "sender"),
    #             ("GolgiCell", "receiver"),
    #         ],
    #         connections=[
    #             ("gap_s", "sender", "receiver", "dendrites[0]", "dendrites[0]"),
    #             ("gap_s", "receiver", "sender", "dendrites[0]", "dendrites[0]"),
    #         ],
    #         stimuli=[["sender", "AMPA_AA", "dendrites[0]", 100, 10, 10]],
    #         recorders={
    #             "Currents": [
    #                 ["sender", "dendrites[0].synapses[0]._point_process._ref_i"],
    #                 ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"],
    #             ]
    #         },
    #         duration=1000,
    #     )
    #
    # def test_parallel_halfgap_resting(self):
    #     results = run_paracell(
    #         "network",
    #         [
    #             ("GolgiCell", "sender"),
    #             ("GolgiCell", "receiver"),
    #         ],
    #         connections=[("gap", "sender", "receiver", "dendrites[0]", "dendrites[0]")],
    #         recorders={
    #             "Currents": [
    #                 ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"]
    #             ]
    #         },
    #         duration=300,
    #     )
    #
    # def test_parallel_halfgap_response(self):
    #     results = run_paracell(
    #         "network",
    #         [
    #             ("GolgiCell", "sender"),
    #             ("GolgiCell", "receiver"),
    #         ],
    #         connections=[("gap", "sender", "receiver", "dendrites[0]", "dendrites[0]")],
    #         stimuli=[["sender", "AMPA_AA", "dendrites[0]", 100, 10, 10]],
    #         recorders={
    #             "Currents": [
    #                 ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"]
    #             ]
    #         },
    #         duration=300,
    #     )
    #
    # def test_parallel_fullgap_response(self):
    #     results = run_paracell(
    #         "network",
    #         [
    #             ("GolgiCell", "sender"),
    #             ("GolgiCell", "receiver"),
    #         ],
    #         connections=[
    #             ("gap", "sender", "receiver", "dendrites[0]", "dendrites[0]"),
    #             ("gap", "receiver", "sender", "dendrites[0]", "dendrites[0]"),
    #         ],
    #         stimuli=[["sender", "AMPA_AA", "dendrites[0]", 100, 10, 10]],
    #         recorders={
    #             "Currents": [
    #                 ["sender", "dendrites[0].synapses[0]._point_process._ref_i"],
    #                 ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"],
    #             ]
    #         },
    #         duration=1000,
    #     )
