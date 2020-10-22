from ._shared import DbbsNeuronModel

class BasketCell(DbbsNeuronModel):
    morphologies = ['01bc.asc']

    synapse_types = {
        "AMPA": {
            "point_process": 'AMPA',
            "attributes": {
                "tau_facil": 54, "tau_rec": 35.1, "tau_1": 6, "gmax": 1200, "U": 0.4
            }
        },
        "NMDA": {
            "point_process": ('NMDA', 'stellate'),
            "attributes": {
                "tau_facil": 5, "tau_rec": 8, "tau_1": 1, "gmax": 5000, "U": 0.15
            }
        },
        "GABA": {
            "point_process": 'GABA',
            "attributes": {
                "tau_facil": 0, "tau_rec": 38.7, "tau_1": 1, "gmax": 3200, "U":0.42, "Erev": -65
            }
        },
    }

    section_types = {
        "soma": {
            "mechanisms": ['Leak','Nav1_1','Cav3_2','Cav3_3','CaL13','Kir2_3','Kv3_4','Kca1_1','Cav2_1','HCN1', 'cdp5'],
            "attributes": {
              "Ra": 122, "cm": 1, "ena": 60, "ek": -80, "eca": 137.5, "eh": -34,
              ("e", "Leak"): -60,
              ("gmax", "Leak"): 0.00003,
              ("gbar", "Nav1_1"): 0.10946415489712,
              ("gcabar", "Cav3_2"): 0.0006295539,
              ("pcabar", "Cav3_3"): 0.0007543986,
              ("pcaLbar", "CaL13"): 0.0002593795,
              ("gkbar", "Kir2_3"): 0.0012770833,
              ("gkbar", "Kv3_4"): 0.0277114781,
              ("gbar", "Kca1_1"): 0.0044251081,
              ("pcabar", "Cav2_1"): 0.000846789,
              ("gbar", "HCN1"): 0.0006902196,
              ("TotalPump", "cdp5"): 1e-9,
            }
        },
        "dendrites": {
            "synapses": ["AMPA", "NMDA", "GABA"],
            "mechanisms": ['Leak','Cav2_1','Kca1_1','Kv1_1','cdp5'],
            "attributes": {
                "Ra": 122, "cm": 1, "ek": -80,
                ("e", "Leak"): -60,
                ("gmax", "Leak"): 0.00003,
                ("pcabar", "Cav2_1"): 0.0004965596,
                ("gbar", "Kca1_1"): 0.0020575902,
                ("gbar", "Kv1_1"): 0.0285137286,
                ("TotalPump", "cdp5"): 1e-9,
            }
        },

        "axon": {
            "mechanisms": ['Leak', 'Kv1_1', 'Nav1_6', 'Kv3_4', 'HCN1', 'cdp5'],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -80, "eh": -34,
                ("e", "Leak"): -60,
                ("gmax", "Leak"): 0.00003,
                ("gbar", "Kv1_1"): 0.0069654709,
                ("gbar", "Nav1_6"): 0.0072983226,
                ("gkbar", "Kv3_4"): 0.0151487764,
                ("gbar", "HCN1"): 0.0034633208,
            }
        },
        "axon_initial_segment": {
            "mechanisms": ['Leak', 'HCN1', 'Nav1_6', 'Kv1_1', 'Kv3_4', 'cdp5'],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -80, "eh": -34,
                ("e", "Leak"): -60,
                ("gmax", "Leak"): 0.00003,
                ("gbar", "HCN1"): 0.0048096086,
                ("gbar", "Nav1_6"): 0.5724695612,
                ("gbar", "Kv1_1"): 0.0827297077,
                ("gkbar", "Kv3_4"): 0.0300388404,
            }
        }
    }

    labels = {
        "axon_initial_segment": {
            "from": "axon",
            "id": lambda id: id == 0
        }
    }
