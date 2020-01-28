from arborize import NeuronModel
from patch import p

class PurkinjeCell(NeuronModel):
    @staticmethod
    def builder(model):
        model.build_AIS()

    morphologies = [('soma_10c.asc', builder)]

    synapse_types = {
        "AMPA_PF": {
            "point_process": ('AMPA', 'golgi_cell_deterministic'),
        }
    }

    section_types = {
        "soma": {
            "mechanisms": ['Leak', 'Nav1_6', 'Kv1_1', 'Kv3_4', 'Kir2_3', 'Cav2_1', 'Cav3_1', 'Cav3_2', 'Cav3_3' , 'Kca1_1', 'Kca2_2', 'Kca3_1', 'HCN1', ('cdp5', 'CAM')],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -84, "eh":-34.4, "eca":  137.52625 ,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 1E-3,
                ("gbar", "Nav1_6"): 0.19618690226085,
                ("gbar", "Kv1_1"): 0.00110415763368,
                ("gkbar", "Kv3_4"): 0.05577804605201,
                ("gkbar", "Kir2_3"): 1.522193625E-05,
                ("pcabar", "Cav2_1"): 0.00015061961222,
                ("pcabar", "Cav3_1"): 6.48282597E-06,
                ("gcabar", "Cav3_2"): 0.00071828406281,
                ("pcabar", "Cav3_3"): 0.00015641655503,
                ("gbar", "Kca1_1"): 0.00926340636416,
                ("gkbar", "Kca2_2"): 0.0008067352175,
                ("gkbar", "Kca3_1"): 0.01154992885293,
                ("gbar", "HCN1"): 0.00168166803803,
                ("TotalPump", "cdp5"): 2e-8,
            }
        },
        "dendrites": {
            "synapses": ['AMPA_PF'],
            "mechanisms": ['Leak','Kv1_1','Kv1_5','Kv3_3','Kv4_3','Cav2_1','Cav3_3', 'Kca1_1','HCN1', ('cdp5', 'CAM')],
            "attributes": {
                "cm": lambda d: (11.510294 * math.exp( - 1.376463 * d) + 2.120503),
                "Ra": 122, "ena": 60, "ek": -88, "eh":-34.4, "eca": 137.52625,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gbar", "Kv1_1"): 0.00132524647813,
                ("gKur", "Kv1_5"): 0.00019456143543,
                ("gbar", "Kv3_3"): 0.01052593082261,
                ("gkbar", "Kv4_3"): 0.0008848451632,
                ("pcabar", "Cav2_1"): 0.00095709772025,
                ("pcabar", "Cav3_3"): 0.0001279244399,
                ("gbar", "Kca1_1"): 0.04100075140464,
                ("gbar", "HCN1"): 2.25814895E-06,
                ("TotalPump", "cdp5"): 5e-8,
            }
        },
        "basal_dendrites": {
            "synapses": ['AMPA_PF'],
            "mechanisms": ['Kir2_3', 'Cav3_1', 'Cav3_2', 'Kca2_2', 'Kca3_1'],
            "attributes":  {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -88, "eca": 137,
                ("e", "Leak"): -61,
                ("gkbar", "Kir2_3"): 1.138398964E-05,
                ("pcabar", "Cav3_1"): 4.19951376E-06,
                ("gcabar", "Cav3_2"): 0.00190242680205,
                ("gkbar", "Kca2_2"): 0.0013078651204,
                ("gkbar", "Kca3_1"): 0.00379262270143,
            }
        },
        "sodium_dendrites": {
            "mechanisms": ['Nav1_6'],
            "attributes":  {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -88, "eca": 137,
                ("gbar", "Nav1_6"): 0.01491080277381,
            }
        },
        "AIS": {
            "mechanisms": ['Leak', 'Nav1_6', 'Kv3_4', 'Cav2_1', 'Cav3_1', ('cdp5', 'CAM')],
            "attributes": {
                "Ra": 122, "cm": 1 + (2 * int(17 / 40)), "ena": 60, "ek": -88, "eca": 137,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gbar", "Nav1_6"): 0.75202621760062,
                ("gkbar", "Kv3_4"): 0.01124635336537,
                ("pcabar", "Cav2_1"): 0.00026512187174,
                ("pcabar", "Cav3_1"): 9.01784953E-06,
                ("TotalPump", "cdp5"): 2e-8,
            }
        },
        "axon_K": {
            "mechanisms": ['Leak', 'Kv1_1'],
            "attributes": {
                "Ra": 122, "cm": 1, "ena": 60, "ek": -80, "eca": 137,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gbar", "Kv1_1"): 0.01024388588529,
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
                "Ra": 122, "cm": 1 + (2 * int(4 / 40)), "ena": 60, "ek": -88, "eca": 137,
                ("e", "Leak"): -61,
                ("gmax", "Leak"): 0.0003,
                ("gbar", "Nav1_6"): 0.02983944220208,
                ("gkbar", "Kv3_4"): 0.0264331412377,
                ("pcabar", "Cav2_1"): 0.00013393329524,
                ("pcabar", "Cav3_1"): 1.920728269E-05,
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
        ais.label = "AIS"
        ais.set_dimensions(length=17,diameter=0.97)
        ais.set_segments(1 + (2 * int(17 / 40)))
        ais.connect(self.soma[0], 0)

        ais_k = p.Section(name="AIS_K")
        ais_k.label = "AIS_K"
        ais_k.set_dimensions(length=4,diameter=0.97)
        ais_k.set_segments(1 + (2 * int(4 / 40)))
        ais_k.connect(ais, 1)

        myelin_0 = p.Section(name="axonmyelin")
        myelin_0.label = "axonmyelin"
        myelin_0.set_dimensions(length=100,diameter=0.73)
        myelin_0.set_segments(1 + (2 * int(100 / 40)))
        myelin_0.connect(ais_k, 1)

        node_0 = p.Section(name="node_0")
        node_0.label = "nodes"
        node_0.set_dimensions(length=4,diameter=0.73)
        node_0.set_segments(1 + (2 * int(4 / 40)))
        node_0.connect(myelin_0, 1)

        myelin_1 = p.Section(name="axonmyelin_1")
        myelin_1.label = "axonmyelin"
        myelin_1.set_dimensions(length=100,diameter=0.73)
        myelin_1.set_segments(1 + (2 * int(100 / 40)))
        myelin_1.connect(node_0, 1)

        node_1 = p.Section(name="node_1")
        node_1.label = "nodes"
        node_1.set_dimensions(length=4,diameter=0.73)
        node_1.set_segments(1 + (2 * int(4 / 40)))
        node_1.connect(myelin_1, 1)

        myelin_2 = p.Section(name="axonmyelin_2")
        myelin_2.label = "axonmyelin"
        myelin_2.set_dimensions(length=100,diameter=0.73)
        myelin_2.set_segments(1 + (2 * int(100 / 40)))
        myelin_2.connect(node_1, 1)

        node_2 = p.Section(name="node_2")
        node_2.label = "nodes"
        node_2.set_dimensions(length=4,diameter=0.73)
        node_2.set_segments(1 + (2 * int(4 / 40)))
        node_2.connect(myelin_2, 1)

        myelin_3 = p.Section(name="axonmyelin_3")
        myelin_3.label = "axonmyelin"
        myelin_3.set_dimensions(length=100,diameter=0.73)
        myelin_3.set_segments(1 + (2 * int(100 / 40)))
        myelin_3.connect(node_2, 1)

        self.axon = [ais, ais_k, myelin_0, node_0, myelin_1, node_1, myelin_2, node_2, myelin_3]
