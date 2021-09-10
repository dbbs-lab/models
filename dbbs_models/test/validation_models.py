import numpy as np
from patch import p
from arborize import NeuronModel
from math import floor


class SimpleCell(NeuronModel):
    @staticmethod
    def builder(model):
        soma = p.Section()
        soma.diam = 0.125
        soma.L = 5.0
        soma.add_3d([[0.0, 0.0, 0.0], [5.0, 0.0, 0.0]])
        model.soma.append(soma)

    morphologies = [builder]

    synapse_types = {
        "AMPA": {
            "point_process": ("AMPA", "granule_cell_deterministic"),
            "attributes": {
                "tau_facil": 5,
                "tau_rec": 8,
                "tau_1": 1,
                "gmax": 1200,
                "U": 0.43,
            },
        },
        "NMDA": {
            "point_process": ("NMDA", "granule_cell_deterministic"),
            "attributes": {
                "tau_facil": 5,
                "tau_rec": 8,
                "tau_1": 1,
                "gmax": 18800,
                "U": 0.43,
            },
        },
        "GABA": {"point_process": "GABA", "attributes": {"U": 0.35}},
    }

    section_types = {
        "soma": {
            "mechanisms": [
                "Leak",
                "Kv3_4",
                "Kv4_3",
                "Kir2_3",
                "Ca",
                "Kv1_1",
                "Kv1_5",
                "Kv2_2",
                ("cdp5", "CR"),
            ],
            "attributes": {
                "Ra": 100,
                "cm": 2,
                ("e", "Leak"): -60,
                "ek": -88,
                "eca": 137.5,
                ("gmax", "Leak"): 0.00029038073716,
                ("gkbar", "Kv3_4"): 0.00076192450951999995,
                ("gkbar", "Kv4_3"): 0.0028149683906099998,
                ("gkbar", "Kir2_3"): 0.00074725514701999996,
                ("gcabar", "Ca"): 0.00060938071783999998,
                ("gbar", "Kv1_1"): 0.0056973826455499997,
                ("gKur", "Kv1_5"): 0.00083407556713999999,
                ("gKv2_2bar", "Kv2_2"): 1.203410852e-05,
            },
        }
    }
