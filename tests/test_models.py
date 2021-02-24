import unittest, efel
from runner import run_protocol, run_multicell, run_paracell
from protocols._helpers import ezfel


class TestGranule(unittest.TestCase):
    def test_soma_current(self):
        results = run_protocol("GranuleCell", "soma_current_injection", amplitude=0.01)
        self.assertEqual(results.Spikecount[0], 5, "Incorrect spike count.")


class TestPurkinje(unittest.TestCase):
    def test_autorhythm(self):
        results = run_protocol("PurkinjeCell", "autorhythm")
        self.assertEqual(results.Spikecount[0], 3, "Incorrect spike count.")


class TestBasket(unittest.TestCase):
    def test_autorhythm(self):
        results = run_protocol("BasketCell", "autorhythm", duration=300)
        self.assertEqual(results.Spikecount[0], 6, "Incorrect spike count.")


class TestGolgi(unittest.TestCase):
    def test_autorhythm(self):
        results = run_protocol("GolgiCell", "autorhythm", duration=300)
        self.assertEqual(results.Spikecount[0], 6, "Incorrect spike count.")

    def test_input_conductance(self):
        results = run_protocol("GolgiCell", "voltage_clamp", voltage=-80, holding=-70)
        current = results.get("current")
        i = current.x
        t = current.t
        dv = -0.01
        di = i[11964] * 10e-9 - i[7866] * 10e-9
        print(dv, di, di / dv)
        import plotly.graph_objs as go

        go.Figure(go.Scatter(x=t, y=i)).show()

    def test_serial_halfgap_resting(self):
        results = run_multicell(
            "network",
            [
                ("GolgiCell", "sender"),
                ("GolgiCell", "receiver"),
            ],
            connections=[
                ("gap_s", "sender", "receiver", "dendrites[0]", "dendrites[0]")
            ],
            recorders={
                "Currents": [
                    ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"]
                ]
            },
            duration=300,
        )

    def test_serial_halfgap_response(self):
        results = run_multicell(
            "network",
            [
                ("GolgiCell", "sender"),
                ("GolgiCell", "receiver"),
            ],
            connections=[
                ("gap_s", "sender", "receiver", "dendrites[0]", "dendrites[0]")
            ],
            stimuli=[["sender", "AMPA_AA", "dendrites[0]", 100, 10, 10]],
            recorders={
                "Currents": [
                    ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"]
                ]
            },
            duration=300,
        )

    def test_serial_fullgap_response(self):
        results = run_multicell(
            "network",
            [
                ("GolgiCell", "sender"),
                ("GolgiCell", "receiver"),
            ],
            connections=[
                ("gap_s", "sender", "receiver", "dendrites[0]", "dendrites[0]"),
                ("gap_s", "receiver", "sender", "dendrites[0]", "dendrites[0]"),
            ],
            stimuli=[["sender", "AMPA_AA", "dendrites[0]", 100, 10, 10]],
            recorders={
                "Currents": [
                    ["sender", "dendrites[0].synapses[0]._point_process._ref_i"],
                    ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"],
                ]
            },
            duration=1000,
        )

    def test_parallel_halfgap_resting(self):
        results = run_paracell(
            "network",
            [
                ("GolgiCell", "sender"),
                ("GolgiCell", "receiver"),
            ],
            connections=[("gap", "sender", "receiver", "dendrites[0]", "dendrites[0]")],
            recorders={
                "Currents": [
                    ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"]
                ]
            },
            duration=300,
        )

    def test_parallel_halfgap_response(self):
        results = run_paracell(
            "network",
            [
                ("GolgiCell", "sender"),
                ("GolgiCell", "receiver"),
            ],
            connections=[("gap", "sender", "receiver", "dendrites[0]", "dendrites[0]")],
            stimuli=[["sender", "AMPA_AA", "dendrites[0]", 100, 10, 10]],
            recorders={
                "Currents": [
                    ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"]
                ]
            },
            duration=300,
        )

    def test_parallel_fullgap_response(self):
        results = run_paracell(
            "network",
            [
                ("GolgiCell", "sender"),
                ("GolgiCell", "receiver"),
            ],
            connections=[
                ("gap", "sender", "receiver", "dendrites[0]", "dendrites[0]"),
                ("gap", "receiver", "sender", "dendrites[0]", "dendrites[0]"),
            ],
            stimuli=[["sender", "AMPA_AA", "dendrites[0]", 100, 10, 10]],
            recorders={
                "Currents": [
                    ["sender", "dendrites[0].synapses[0]._point_process._ref_i"],
                    ["receiver", "dendrites[0].synapses[0]._point_process._ref_i"],
                ]
            },
            duration=1000,
        )
