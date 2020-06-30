import unittest, efel
from runner import run_protocol
from protocols._helpers import ezfel

class TestGranule(unittest.TestCase):

    def test_soma_current(self):
        results = run_protocol("GranuleCell", "soma_current_injection", amplitude=0.01)
        self.assertEquals(results.Spikecount[0], 9, "Incorrect spike count.")
