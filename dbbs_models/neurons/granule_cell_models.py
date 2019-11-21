#Made by Stefano "Bremen" Masoli
# Modified & updated by Elisa Marenzi

import numpy as np
from neuron import h
from ..synapses import Synapse
from .base import NeuronModel, Section
from math import floor

class GranuleCell(NeuronModel):
    @staticmethod
    def builder(model):
        model.fiber_section_length = 7          # µm
        model.ascending_axon_length = 126       # µm
        model.parallel_fiber_length = 2000      # µm
        model.build_soma()
        model.build_dendrites()
        model.build_hillock()
        model.build_ascending_axon()
        model.build_parallel_fiber()

    morphologies = [builder]

    section_types = {
        "soma": {
            "mechanisms": ['Leak', 'Kv3_4', 'Kv4_3', 'Kir2_3', 'GRC_CA', 'Kv1_1', 'Kv1_5', 'Kv2_2_0010', 'cdp5_CR'],
            "attributes": {
                "Ra": 100, "cm": 2,
                "e_Leak": -60, "ek": -88, "eca": 137.5,
                "gmax_Leak": 0.00029038073716,
                "gkbar_Kv3_4": 0.00076192450951999995,
                "gkbar_Kv4_3": 0.0028149683906099998,
                "gkbar_Kir2_3": 0.00074725514701999996,
                "gcabar_GRC_CA": 0.00060938071783999998,
                "gbar_Kv1_1":  0.0056973826455499997,
                "gKur_Kv1_5":  0.00083407556713999999,
                "gKv2_2bar_Kv2_2_0010": 1.203410852e-05
            }
        },
        "dendrites": {
            "mechanisms": ['Leak', 'GRC_CA', 'Kca1_1', 'Kv1_1', 'cdp5_CR'],
            "attributes": {
                "Ra": 100, "cm": 2.5,
                "e_Leak":  -60, "ek": -88, "eca": 137.5,
                "gmax_Leak": 0.00025029700736999997,
                "gcabar_GRC_CA": 0.0050012800845900002,
                "gbar_Kca1_1": 0.010018074546510001,
                "gbar_Kv1_1": 0.00381819207934
            }
        },
        "axon": {
            "mechanisms": [], "attributes": {}
        },
        "ascending_axon": {
            "mechanisms": ['GRC_NA', 'Kv3_4', 'Leak', 'GRC_CA', 'cdp5_CR'],
            "attributes": {
                "Ra": 100, "cm": 1,
                "ena": 87.39, "ek": -88, "e_Leak":  -60, "eca": 137.5,
                "gnabar_GRC_NA": 0.026301636815019999,
                "gkbar_Kv3_4": 0.00237386061632,
                "gmax_Leak":  9.3640921249999996e-05,
                "gcabar_GRC_CA": 0.00068197420273000001,
            }
        },
        "parallel_fiber": {
            "mechanisms": ['GRC_NA', 'Kv3_4', 'Leak', 'GRC_CA', 'cdp5_CR'],
            "attributes": {
            "L": 7, "diam": 0.15, "Ra": 100, "cm": 1,
            "ena": 87.39, "ek": -88, "e_Leak":  -60, "eca": 137.5,
            "gnabar_GRC_NA": 0.017718484492610001,
            "gkbar_Kv3_4": 0.0081756804703699993,
            "gmax_Leak": 3.5301616000000001e-07,
            "gcabar_GRC_CA": 0.00020856833529999999
            }
        },
        "axon_initial_segment": {
            "mechanisms": ['GRC_NA_FHF', 'Kv3_4', 'Leak', 'GRC_CA', 'GRC_KM', 'cdp5_CR'],
            "attributes": {
                "Ra": 100, "cm": 1,
                "ena": 87.39, "ek": -88, "eca": 137.5, "e_Leak":  -60,
                "gnabar_GRC_NA_FHF": 1.28725006737226,
                "gkbar_Kv3_4": 0.0064959534065400001,
                "gmax_Leak": 0.00029276697557000002,
                "gcabar_GRC_CA":  0.00031198539471999999,
                "gkbar_GRC_KM":  0.00056671971737000002
            }
        },
        "axon_hillock": {
            "mechanisms": ['Leak', 'GRC_NA_FHF', 'Kv3_4', 'GRC_CA', 'cdp5_CR'],
            "attributes": {
                "Ra": 100, "cm": 2,
                "e_Leak":  -60, "ena": 87.39, "ek": -88, "eca": 137.5,
                "gmax_Leak": 0.00036958189720000001,
                "gnabar_GRC_NA_FHF": 0.0092880585146199995,
                "gkbar_Kv3_4": 0.020373463109149999,
                "gcabar_GRC_CA": 0.00057726155447
            }
        }
    }

    def build_soma(self):
        self.soma = [Section.create(name="soma")]
        self.soma[0].set_dimensions(length=5.62232, diameter=5.8)
        self.soma[0].set_segments(1)
        self.soma[0].add_3d([self.position, self.position + [0., 5.62232, 0.]])

    def build_dendrites(self):
        self.dend = [Section.create(name='dend_'+str(x)) for x in range(4)]
        for dendrite in self.dend:
            dendrite.set_dimensions(length=15, diameter=0.75)
            dendrite.add_3d([self.position, self.position - [0., dendrite.L, 0.]])
            dendrite.connect(self.soma[0],0)

    def build_hillock(self):
        hillock = Section.create(name="axon_hillock")
        hillock.set_dimensions(length=1,diameter=1.5)
        hillock.set_segments(1)
        hillock.add_3d([self.position + [ 0., 5.62232, 0.], self.position + [0., 6.62232, 0.]])
        hillock.label = "axon_hillock"
        hillock.connect(self.soma[0], 0)

        ais = Section.create(name="axon_initial_segment")
        ais.label = "axon_initial_segment"
        ais.set_dimensions(length=10,diameter=0.7)
        ais.set_segments(1)
        ais.add_3d([self.position + [ 0., 6.62232, 0.], self.position + [0., 16.62232, 0.]])
        ais.connect(hillock, 1)

        self.axon = [hillock, ais]

    def build_ascending_axon(self):
        section_length = self.fiber_section_length
        n = int(self.ascending_axon_length / section_length)
        self.ascending_axon = [Section.create(name='ascending_axon_'+str(x)) for x in range(n)]
        y = 16.62232
        for section in self.ascending_axon:
            section.label = "ascending_axon"
            section.set_dimensions(length=self.fiber_section_length, diameter=0.3)
            section.add_3d([
                self.position + [0., y, 0.],
                self.position + [0., y + section_length, 0.]
            ])
            y += section_length
        # Store the last used y position as the start for the parallel fiber
        self.y_pf = y
        # Append ascending axon to axon
        self.axon.extend(self.ascending_axon)

    def build_parallel_fiber(self):
        section_length = self.fiber_section_length
        n = int(self.parallel_fiber_length / section_length)
        self.parallel_fiber = [Section.create(name='parellel_fiber_'+str(x)) for x in range(n)]
        # Use the last AA y as Y for the PF
        y = self.y_pf
        center = self.position[2]
        for id, section in enumerate(self.parallel_fiber):
            section.label = "parallel_fiber"
            section.set_dimensions(length=self.fiber_section_length, diameter=0.3)
            sign = 1 - (id % 2) * 2
            z = floor(id / 2) * section_length
            section.add_3d([
                self.position + [0., y, center + sign * z],
                self.position + [0., y, center + sign * (z + section_length)]
            ])
            if id < 2:
                section.connect(self.ascending_axon[-1])
            else:
                section.connect(self.parallel_fiber[id - 2])
            z += section_length
        self.axon.extend(self.parallel_fiber)
