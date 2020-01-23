import numpy as np
from patch import p
from ..synapses import Synapse
from .base import NeuronModel
from math import floor

class StellateCell(NeuronModel):
    morphologies = ['stellate.ASC']

    synapse_types = {
        "AMPA": {
            "point_process": ('AMPA', 'stellate'),
            "attributes": {
                "tau_facil": 10.8, "tau_rec": 35.1, "tau_1": 10, "gmax": 2300, "U": 0.15
            }
        },
        "NMDA": {
            "point_process": ('NMDA', 'stellate'),
            "attributes": {
                "tau_facil": 5, "tau_rec": 8, "tau_1": 1, "gmax": 10000, "U": 0.15
            }
        }
    }

    section_types = {
        "soma": {
            "mechanisms": ['Leak','Nav1_1','Cav3_2','Cav3_3','Kir2_3','Kv1_1','Kv3_4','Kv4_3','Kca1_1','Kca2_2','Cav2_1',('HCN1', 'stellate'),'cdp5'],
            "attributes": {
              "Ra": 110, "cm": 1, "ena": 60, "ek": -84, "eca": 137.5, "eh": -34,
              ("e", "Leak"): -48,
              ("gmax", "Leak"): 0.000008,
              ("gbar", "Nav1_1"): 0.8,
              ("gcabar", "Cav3_2"): 0.00163912063769,
              ("pcabar", "Cav3_3"): 0.00001615552993,
              ("gkbar", "Kir2_3"): 0.00001093425575,
              ("gbar", "Kv1_1"): 0.00107430134923,
              ("gkbar", "Kv3_4"): 0.008,
              ("gkbar", "Kv4_3"): 0.00404228168138,
              ("gbar", "Kca1_1"): 0.00518036298671,
              ("gkbar", "Kca2_2"): 0.00054166094878,
              ("pcabar", "Cav2_1"): 0.00038,
              ("gbar", "HCN1"): 0.00058451678362,
              ("TotalPump", "cdp5"): 7e-9,
            }
        },
        "dendrites": {
            "mechanisms": [], "attributes": {}
        },
        "proximal_dendrites": {
            "synapses": ['AMPA', 'NMDA'],
            "mechanisms": ['Leak', 'Cav3_2', 'Cav3_3', 'Kv1_1','Kv4_3','Kca1_1','Kca2_2','Cav2_1','cdp5'],
            "attributes": {
                "Ra": 110, "cm": 1.5, "ek": -84, "eca": 137.5,
                ("e", "Leak"): -48,
                ("gmax", "Leak"): 0.000008,
                ("gcabar", "Cav3_2"): 0.00070661092763,
                ("pcabar", "Cav3_3"): 0.00001526216781,
                ("gbar", "Kv1_1"): 0.00906810561650,
                ("gkbar", "Kv4_3"): 0.00264204713540,
                ("gbar", "Kca1_1"): 0.00499205404769,
                ("gkbar", "Kca2_2"): 0.00000326194117,
                ("pcabar", "Cav2_1"): 0.0005,
                ("TotalPump", "cdp5"): 1e-9,
            }
        },
        "distal_dendrites": {
            "synapses": ['AMPA', 'NMDA'],
            "mechanisms": ['Leak', 'Kv1_1', 'Kca1_1', 'Kca2_2', 'Cav2_1', 'cdp5'],
            "attributes":  {
                "Ra": 110, "cm": 1.5, "ek": -84, "eca": 137.5,
                ("e", "Leak"): -48,
                ("gmax", "Leak"): 0.000008,
                ("gbar", "Kv1_1"): 0.00237825442906,
                ("gbar", "Kca1_1"): 0.00226329455766,
                ("gkbar", "Kca2_2"): 0.00001079984416,
                ("pcabar", "Cav2_1"): 0.00025,
                ("TotalPump", "cdp5"): 1e-9,
            }
        },
        "axon": {
            "mechanisms": ['Leak', 'Kv1_1', 'Nav1_6', 'Kv3_4', ('HCN1', 'stellate'), 'cdp5'],
            "attributes": {
                "Ra": 110, "cm": 1, "ena": 60, "ek": -84, "eh": -34,
                ("e", "Leak"): -48,
                ("gmax", "Leak"): 0.000008,
                ("gbar", "Kv1_1"): 0.00271359229578,
                ("gbar", "Nav1_6"): 0.00835931586458,
                ("gkbar", "Kv3_4"): 0.01153520393521,
                ("gbar", "HCN1"): 0.00070017344082,
            }
        },
        "axon_initial_segment": {
            "mechanisms": ['Leak', ('HCN1', 'stellate'), 'Nav1_6', 'Kv1_1', 'Kv3_4', 'Km', 'cdp5'],
            "attributes": {
                "Ra": 110, "cm": 1, "ena": 60, "ek": -84, "eh": -34,
                ("e", "Leak"): -48,
                ("gmax", "Leak"): 0.000008,
                ("gbar", "HCN1"): 0.00099184971498,
                ("gbar", "Nav1_6"): 0.4,
                ("gbar", "Kv1_1"): 0.00492841685426,
                ("gkbar", "Kv3_4"):0.03351450571128,
                ("gkbar", "Km"):0.00007960307413,
            }
        }
    }

    labels = {
        "proximal_dendrites": {
            "from": "dendrites",
            "diam": lambda diam: diam >= 0.6
        },
        "distal_dendrites": {
            "from": "dendrites",
            "diam": lambda diam: diam < 0.6
        },
        "axon_initial_segment": {
            "from": "axon",
            "id": lambda id: id == 0
        }
    }
