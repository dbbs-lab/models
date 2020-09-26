from arborize import NeuronModel
from arborize.builders import rotate
from patch import p
import math

class PurkinjeCell(NeuronModel):
    @staticmethod
    def builder(model):
        model.build_AIS()
        model.set_segments()

    morphologies = [('soma_10c.asc', rotate([-1, 0, 0], [0, 1, 0]), builder)]

    synapse_types = {
        "AMPA_PF": {
            "point_process": 'AMPA',
            "attributes": {
                "tau_facil": 54, "tau_rec": 35.1, "tau_1": 6, "gmax": 1200, "U": 0.13
            }
        },
        "GABA": {
            "point_process": 'GABA',
            "attributes": {
                "tau_facil": 4, "tau_rec": 15, "tau_1": 1, "Erev": -70, "gmax": 2600, "U": 0.35
            }
        }
    }

    section_types = {
        "soma": {
            "synapses": ["GABA"],
            "mechanisms": ['Leak', 'Nav1_6', 'Kv1_1', 'Kv3_4', 'Kir2_3', 'Cav2_1', 'Cav3_1', 'Cav3_2', 'Cav3_3' , 'Kca1_1', 'Kca2_2', 'Kca3_1', 'HCN1', ('cdp5', 'CAM')],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -88, "eh":-34.4, "eca":  137.52625 ,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 1E-3,
                ("gbar", "Nav1_6"): 0.19835422387652,
                ("gbar", "Kv1_1"): 0.00185494695569,
                ("gkbar", "Kv3_4"): 0.05684366437809,
                ("gkbar", "Kir2_3"): 0.00002100544604,
                ("pcabar", "Cav2_1"): 0.00015301236890,
                ("pcabar", "Cav3_1"): 0.00000419659246,
                ("gcabar", "Cav3_2"): 0.00067268089296,
                ("pcabar", "Cav3_3"): 0.00015401124325,
                ("gbar", "Kca1_1"): 0.00877088561313,
                ("gkbar", "Kca2_2"): 0.00085748826176,
                ("gkbar", "Kca3_1"): 0.00978230722317,
                ("gbar", "HCN1"): 0.00192222696826,
                ("TotalPump", "cdp5"): 2e-8,
            }
        },
        "dendrites": {
            "synapses": ['AMPA_PF', 'GABA'],
            "mechanisms": ['Leak','Kv1_1','Kv1_5','Kv3_3','Kv4_3','Cav2_1','Cav3_3', 'Kca1_1', 'HCN1', ('cdp5', 'CAM')],
            "attributes": {
                "cm": lambda d: (11.510294 * math.exp( - 1.376463 * d) + 2.120503),
                "Ra": 122, "ena": 60, "ek": -88, "eh":-34.4, "eca": 137.52625,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gbar", "Kv1_1"): 0.00105296938319,
                ("gKur", "Kv1_5"): 0.00018237109331,
                ("gbar", "Kv3_3"): 0.01192448545734,
                ("gkbar", "Kv4_3"): 0.00082020749325,
                ("pcabar", "Cav2_1"): 0.001594103024736,
                ("pcabar", "Cav3_3"): 0.00013000262047,
                ("gbar", "Kca1_1"): 0.03803999223084,
                ("gbar", "HCN1"): 0.00000249811225,
                ("TotalPump", "cdp5"): 5e-8,
            }
        },
        "basal_dendrites": {
            "synapses": ['AMPA_PF'],
            "mechanisms": ['Leak', 'Kir2_3', 'Cav3_1', 'Cav3_2', 'Kca2_2', 'Kca3_1'],
            "attributes":  {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -88, "eca": 137.52625,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gkbar", "Kir2_3"): 0.00001135399111,
                ("pcabar", "Cav3_1"): 0.00000400668190,
                ("gcabar", "Cav3_2"): 0.00194175819441,
                ("gkbar", "Kca2_2"): 0.00078534639818,
                ("gkbar", "Kca3_1"): 0.00330481139341,
            }
        },
        "sodium_dendrites": {
            "mechanisms": ['Nav1_6'],
            "attributes":  {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -88, "eca": 137.52625,
                ("gbar", "Nav1_6"): 0.01568012827236,
            }
        },
        "AIS": {
            "mechanisms": ['Leak', 'Nav1_6', 'Kv3_4', 'Cav2_1', 'Cav3_1', ('cdp5', 'CAM')],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -88, "eca": 137.52625,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gbar", "Nav1_6"): 0.76520432560779,
                ("gkbar", "Kv3_4"): 0.01470016164534,
                ("pcabar", "Cav2_1"): 0.00028786836482,
                ("pcabar", "Cav3_1"): 0.00000643429659,
                ("TotalPump", "cdp5"): 2e-8,
            }
        },
        "axon": {
            "mechanisms": [],
            "attributes": {}
        },
        "AIS_K": {
            "mechanisms": ['Leak', 'Kv1_1'],
            "attributes": {
                "Ra": 122, "cm": 1, "ek": -88,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gbar", "Kv1_1"): 0.01011038066089,
            }
        },
        "axonmyelin": {
            "mechanisms": ['pas'],
            "attributes": {
                "Ra": 122, "cm": 1.87e-11,
                ("e", "pas"): -61,
                ("g", "pas"): 5.60e-9,
            }
        },
        "nodes": {
            "mechanisms": ['Leak', 'Nav1_6', 'Kv3_4', 'Cav2_1', 'Cav3_1', ('cdp5', 'CAM')],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -88, "eca": 137.52625,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gbar", "Nav1_6"): 0.02749309338198,
                ("gkbar", "Kv3_4"): 0.02227585026371,
                ("pcabar", "Cav2_1"): 0.00012353396215,
                ("pcabar", "Cav3_1"): 0.00001508814156,
                ("TotalPump", "cdp5"): 5e-7,
            }
        },
    }

    labels = {
        "basal_dendrites": {
            "from": "dendrites",
            "diam": lambda diam: diam >= 1.6
        },
        "sodium_dendrites": {
            "from": "dendrites",
            "diam": lambda diam: diam >= 3.3
        }
    }

    def build_AIS(self):
        ais = p.Section(name="AIS")
        ais.labels = ["AIS"]
        ais.set_dimensions(length=17,diameter=0.97)
        ais.set_segments(1)
        ais.connect(self.soma[0], 0)

        ais_k = p.Section(name="AIS_K")
        ais_k.labels = ["AIS_K"]
        ais_k.set_dimensions(length=4,diameter=0.97)
        ais_k.set_segments(1)
        ais_k.connect(ais, 1)

        myelin_0 = p.Section(name="axonmyelin")
        myelin_0.labels = ["axonmyelin"]
        myelin_0.set_dimensions(length=100,diameter=0.73)
        myelin_0.set_segments(5)
        myelin_0.connect(ais_k, 1)

        node_0 = p.Section(name="node_0")
        node_0.labels = ["nodes"]
        node_0.set_dimensions(length=4,diameter=0.73)
        node_0.set_segments(1)
        node_0.connect(myelin_0, 1)

        myelin_1 = p.Section(name="axonmyelin_1")
        myelin_1.labels = ["axonmyelin"]
        myelin_1.set_dimensions(length=100,diameter=0.73)
        myelin_1.set_segments(5)
        myelin_1.connect(node_0, 1)

        node_1 = p.Section(name="node_1")
        node_1.labels = ["nodes"]
        node_1.set_dimensions(length=4,diameter=0.73)
        node_1.set_segments(1)
        node_1.connect(myelin_1, 1)

        myelin_2 = p.Section(name="axonmyelin_2")
        myelin_2.labels = ["axonmyelin"]
        myelin_2.set_dimensions(length=100,diameter=0.73)
        myelin_2.set_segments(5)
        myelin_2.connect(node_1, 1)

        node_2 = p.Section(name="node_2")
        node_2.labels = ["nodes"]
        node_2.set_dimensions(length=4,diameter=0.73)
        node_2.set_segments(1)
        node_2.connect(myelin_2, 1)

        myelin_3 = p.Section(name="axonmyelin_3")
        myelin_3.labels = ["axonmyelin"]
        myelin_3.set_dimensions(length=100,diameter=0.73)
        myelin_3.set_segments(5)
        myelin_3.connect(node_2, 1)

        self.axon = [ais, ais_k, myelin_0, node_0, myelin_1, node_1, myelin_2, node_2, myelin_3]

    def set_segments(self):
        """
            All models optimized with BluePyOpt have nseg set in this way when they are
            being optimized: 2 extra segments per 40µm length of the section.
        """
        for s in self.axon + self.dend + self.soma:
            s.nseg = 1 + (2 * int(s.L/ 40))
