import unittest, types
import dbbs_protocols.granule_cell as granule_protocols
import dbbs_models.neurons

class TestGranule(unittest.TestCase):

    @classmethod
    def setupClass(cls):
        cls.instance = dbbs_models.neurons.GranuleCell()
        cls.main_current_time, cls.main_current_voltage = granule_protocols.main_current()
        cls.spontaneous_time, cls.spontaneous_voltage = granule_protocols.spontaneous()

    def test_main_current(self):
        pass

    def test_spontaneous_frequency(self):
        pass
