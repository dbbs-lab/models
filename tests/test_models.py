import unittest, efel, arborize, nrnsub
import arborize.unittest.protocols as protocols

# from runner import run_protocol, run_multicell, run_paracell
import random

#
#
# class TestGranule(unittest.TestCase):
#     def test_soma_current(self):
#         results = run_protocol("GranuleCell", "soma_current_injection", amplitude=0.01)
#         self.assertEqual(results.Spikecount[0], 5, "Incorrect spike count.")
#
#
# class TestPurkinje(unittest.TestCase):
#     def test_autorhythm(self):
#         results = run_protocol("PurkinjeCell", "autorhythm")
#         self.assertEqual(results.Spikecount[0], 3, "Incorrect spike count.")
#
#
# class TestBasket(unittest.TestCase):
#     def test_autorhythm(self):
#         results = run_protocol("BasketCell", "autorhythm", duration=300)
#         self.assertEqual(results.Spikecount[0], 6, "Incorrect spike count.")


class TestGolgi(arborize.TestCase):
    input_conductance = 5.395755181874052e-08
    gaba_conductance = 8.960206676533555e-11

    test_autorhythm = protocols.Autorhythm()

    def test_failure(self):
        self.assertEqual(5, 6, "Incorrect spike count.")

    # def test_autorhythm(self):
    #     results = run_protocol("GolgiCell", "autorhythm", duration=300)
    #     self.assertEqual(results.Spikecount[0], 6, "Incorrect spike count.")
    #
    # def test_input_conductance(self):
    #     results = run_protocol("GolgiCell", "voltage_clamp", voltage=-80, holding=-70)
    #     current = results.get("current")
    #     i = current.x
    #     t = current.t
    #     dv = -0.01
    #     di = i[11964] * 10e-9 - i[7866] * 10e-9
    #     g = di / dv
    #     print(g)
    #     self.assertAlmostEqual(self.input_conductance, g, 3)
    #
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
