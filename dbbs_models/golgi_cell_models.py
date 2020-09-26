from arborize import NeuronModel
from arborize.builders import rotate

class GolgiCell(NeuronModel):
    morphologies = [('pair-140514-C2-1_split_1.asc', rotate([0., 1., 0.], [1., 0., 0.]))]

    synapse_types = {
        "AMPA_PF": {
            "point_process": 'AMPA',
            "attributes": {
                "tau_facil": 54, "tau_rec": 35.1, "tau_1": 30, "gmax": 1200, "U": 0.4
            }
        },
        "AMPA_MF": {
            "point_process": ('AMPA', 'granule'),
        },
        "NMDA": {
            "point_process": ('NMDA', 'granule')
        }
    }

    section_types = {
        "soma": {
            "mechanisms": ['Leak', 'Nav1_6', 'Kv1_1', 'Kv3_4', 'Kv4_3', 'Kca1_1', 'Kca3_1', 'Ca', 'Cav3_1', ('cdp5', 'CAM_GoC')],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -80, "eca": 137,
                ("e", "Leak"): -55,
                ("gmax", "Leak"): 0.00003,
                ("gbar", "Nav1_6"): 0.14927733727426,
                ("gbar", "Kv1_1"): 0.00549507510519,
                ("gkbar", "Kv3_4"): 0.14910988921938,
                ("gkbar", "Kv4_3"): 0.00406420380423,
                ("gbar", "Kca1_1"): 0.017643457890359999,
                ("gkbar", "Kca3_1"): 0.10177335775222,
                ("gcabar", "Ca"): 0.0087689418803,
                ("pcabar", "Cav3_1"): 3.407734319e-05,
                ("TotalPump", "cdp5"): 1e-7,
            }
        },
        "dendrites": {
            "mechanisms": [], "attributes": {}
        },
        "basal_dendrites": {
            "synapses": ['AMPA_MF', 'AMPA_PF', 'NMDA'],
            "mechanisms": ['Leak','Nav1_6','Kca1_1','Kca2_2','Ca',('cdp5', 'CAM_GoC')],
            "attributes": {
                "Ra": 122, "cm": 2.5, "ena": 60, "ek": -80, "eca": 137,
                ("e", "Leak"): -55,
                ("gmax", "Leak"): 0.00003,
                ("gbar", "Nav1_6"): 0.0080938853145999991,
                ("gbar", "Kca1_1"): 0.012260527481460001,
                ("gkbar", "Kca2_2"): 0.016506899583850002,
                ("gcabar", "Ca"): 0.0013988561771200001,
                ("TotalPump", "cdp5"): 2e-9,
            }
        },
        "apical_dendrites": {
            "synapses": ['AMPA_MF', 'AMPA_PF'],
            "mechanisms": ['Leak', 'Nav1_6', 'Kca1_1', 'Kca2_2', 'Cav2_3', 'Cav3_1', ('cdp5', 'CAM_GoC')],
            "attributes":  {
                "Ra": 122, "cm": 2.5, "ena": 60, "ek": -80, "eca": 137,
                ("e", "Leak"): -55,
                ("gmax", "Leak"): 0.00003,
                ("gbar", "Nav1_6"): 0.00499506303209,
                ("gbar", "Kca1_1"): 0.01016375552607,
                ("gkbar", "Kca2_2"): 0.0024717247914099998,
                ("gcabar", "Cav2_3"): 0.00128859564935,
                ("pcabar", "Cav3_1"): 3.690771983e-05,
                ("TotalPump", "cdp5"): 5e-9,
            }
        },
        "axon": {
            "mechanisms": ['Leak', 'Nav1_6', 'Kv3_4', ('cdp5', 'CAM_GoC')],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -80, "eca": 137,
                ("e", "Leak"): -55,
                ("gmax", "Leak"): 0.000001,
                ("gbar", "Nav1_6"): 0.0115,
                ("gkbar", "Kv3_4"): 0.0091,
                ("TotalPump", "cdp5"):  1e-8,
            }
        },
        "axon_initial_segment": {
            "mechanisms": ['Leak', ('HCN1', 'golgi'), 'HCN2', 'Nav1_6', "Ca", 'Kca1_1', 'Km', ('cdp5', 'CAM_GoC')],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -80, "eca": 137,
                ("e", "Leak"): -55,
                ("gmax", "Leak"):  0.00003,
                ("gbar", "Nav1_6"): 0.17233663543618999,      
                ("gbar", "Kca1_1"): 0.10008178886943001,
                ("gcabar", "Ca"): 0.0059504600114800004,
                ("gkbar", "Km"): 0.00024381226197999999,
                ("gbar", "HCN1"): 0.0003371456442,
                ("gbar", "HCN2"): 0.00030643090764,
                ("TotalPump", "cdp5"): 1e-8,
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
