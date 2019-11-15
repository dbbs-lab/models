from neuron import h
from .base import NeuronModel

class GolgiCell(NeuronModel):
    morphologies = ['pair-140514-C2-1_split_1.asc']

    section_types = {
        "soma": {
            "mechanisms": ['Leak', 'Nav1_6', 'Kv1_1', 'Kv3_4', 'Kv4_3', 'Kca1_1', 'Kca2_2', 'Cav2_2', 'Cav3_1', 'cdp5StCmod'],
            "attributes": {
                "Ra": 122, "cm": 1, "e_Leak": -59, "ena": 60, "ek": -80, "eca": 137,
                "gmax_Leak": 0.0001,
                "gbar_Nav1_6": 0.21484733189661,
                "gbar_Kv1_1": 0.0077852492295,
                "gkbar_Kv3_4": 0.09443147623427,
                "gkbar_Kv4_3": 0.00396041300408,
                "gbar_Kca1_1": 0.02487482973906,
                "gkbar_Kca2_2": 0.01237853918928,
                "gcanbar_Cav2_2": 0.00026807889475,
                "pcabar_Cav3_1": 5.80137823E-06,
                "TotalPump_cdp5StCmod": 3e-9,
            }
        },
        "dendrites": {
            "mechanisms": [], "attributes": {}
        },
        "basal_dendrites": {
            "mechanisms": ['Leak','Nav1_6','Kv1_1','Kca1_1','Kca2_2','Cav2_2','cdp5StCmod'],
            "attributes": {
                "Ra": 122, "cm": 3, "e_Leak": -59, "ena": 60, "ek": -80, "eca": 137,
                "gmax_Leak": 0.00003,
                "gbar_Nav1_6": 0.00596389701963,
                "gbar_Kv1_1": 0.00300075070483,
                "gbar_Kca1_1": 0.01992292703235,
                "gkbar_Kca2_2": 0.01067448459892,
                "gcanbar_Cav2_2": 0.00098761689603,
                "TotalPump_cdp5StCmod": 0.7e-9,
            }
        },
        "apical_dendrites": {
            "mechanisms": ['Leak', 'Nav1_6', 'Kv1_1', 'Kca1_1', 'Kca2_2', 'Cav2_3', 'Cav3_1', 'cdp5StCmod'],
            "attributes":  {
                "Ra": 122, "cm": 3, "e_Leak": -59, "ena": 60, "ek": -80, "eca": 137,
                "gmax_Leak": 0.00003,
                "gbar_Nav1_6": 0.0032004946448,
                "gbar_Kv1_1": 0.00366791747215,
                "gbar_Kca1_1": 0.0207352478961,
                "gkbar_Kca2_2": 0.00597385039361,
                "gcabar_Cav2_3": 7.181872437E-05,
                "pcabar_Cav3_1": 7.03521203E-06,
                "TotalPump_cdp5StCmod": 2e-9,
            }
        },
        "axon": {
            "mechanisms": ['Leak', 'Kv1_1', 'Nav1_6', 'Kv3_4', 'cdp5StCmod'],
            "attributes": {
                "Ra": 122, "cm": 1, "e_Leak": -59, "ena": 60, "ek": -80, "eca": 137,
                "gmax_Leak": 0.00001,
                "gbar_Kv1_1": 0.004,
                "gbar_Nav1_6": 9.670147548E-05,
                "gkbar_Kv3_4": 0.00633480317392,
                "TotalPump_cdp5StCmod": 1e-9,
            }
        },
        "axon_initial_segment": {
            "mechanisms": ['Leak', 'HCN1', 'HCN2', 'Nav1_6', 'Kv3_4', 'GRC_KM', 'cdp5StCmod'],
            "attributes": {
                "Ra": 122, "cm": 1, "e_Leak": -59, "ena": 60, "eca": 137,
                "gmax_Leak": 0.00003,
                "gbar_HCN1": 0.00020635332351,
                "gbar_HCN2": 0.0002816526031,
                "gbar_Nav1_6": 0.39006484091705,
                "gkbar_Kv3_4": 0.29455503229075,
                "gkbar_GRC_KM": 0.00030327654923,
                "TotalPump_cdp5StCmod": 1e-9,
            }
        }
    }

    labels = {
        "basal_dendrites": {
            "from": "dendrites",
            "id": lambda id: id >= 0 and id <= 3 or id >= 16 and id <= 17 or id >= 33 and id <= 41 or id == 84 or id >= 105 and id <= 150
        },
        "apical_dendrites": {
            "from": "dendrites",
            "id": lambda id: id >= 4 and id <= 15 or id >= 18 and id <= 32 or id >= 42 and id <= 83 or id >= 85 and id <= 104
        },
        "axon_initial_segment": {
            "from": "axon",
            "id": lambda id: id == 0
        }
    }
