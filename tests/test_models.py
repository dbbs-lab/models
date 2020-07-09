import unittest, efel
from runner import run_protocol
from protocols._helpers import ezfel

class TestGranule(unittest.TestCase):

    def test_soma_current(self):
        results = run_protocol("GranuleCell", "soma_current_injection", amplitude=0.01)
        self.assertEqual(results.Spikecount[0], 9, "Incorrect spike count.")

class TestPurkinje(unittest.TestCase):

    def test_autorhythm(self):
        results = run_protocol("PurkinjeCell", "autorhythm")
        self.assertEqual(results.Spikecount[0], 3, "Incorrect spike count.")

class TestBasket(unittest.TestCase):

    def test_autorhythm(self):
        results = run_protocol("BasketCell", "autorhythm", duration=300)
        self.assertEqual(results.Spikecount[0], 6, "Incorrect spike count.")
