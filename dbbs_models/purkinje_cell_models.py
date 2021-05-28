from ._shared import DbbsNeuronModel
from arborize.builders import rotate
from patch import p
import math


class PurkinjeCell(DbbsNeuronModel):
    @staticmethod
    def builder(model):
        model.build_AIS()
        model.set_segments()

    morphologies = [("soma_10c.asc", rotate([-1, 0, 0], [0, 1, 0]), builder)]

    synapse_types = {
        "AMPA": {
            "point_process": "AMPA",
            "attributes": {
                "tau_facil": 54,
                "tau_rec": 35.1,
                "tau_1": 6,
                "gmax": 1200,
                "U": 0.13,
            },
        },
        "GABA": {
            "point_process": "GABA",
            "attributes": {
                "tau_facil": 4,
                "tau_rec": 15,
                "tau_1": 1,
                "Erev": -70,
                "gmax": 2600,
                "U": 0.35,
            },
        },
    }

    section_types = {
        "soma": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {
                "na": {"e": 60},
                "k": {"e": -88},
                "h": {"e": -34.4},
                "ca": {"e": 137.52625},
            },
            "mechanisms": {
                "Leak": {"e": -61, "gmax": 0.001},
                "Nav1_6": {"gbar": 0.19835422387652},
                "Kv1_1": {"gbar": 0.00185494695569},
                "Kv3_4": {"gkbar": 0.05684366437809},
                "Kir2_3": {"gkbar": 2.100544604e-05},
                "Cav2_1": {"pcabar": 0.0001530123689},
                "Cav3_1": {"pcabar": 4.19659246e-06},
                "Cav3_2": {"gcabar": 0.00067268089296},
                "Cav3_3": {"pcabar": 0.00015401124325},
                "Kca1_1": {"gbar": 0.00877088561313},
                "Kca2_2": {"gkbar": 0.00085748826176},
                "Kca3_1": {"gkbar": 0.00978230722317},
                "HCN1": {"gbar": 0.00192222696826},
                ("cdp5", "CAM"): {},
                "cdp5": {"TotalPump": 2e-08},
            },
            "synapses": ["GABA"],
        },
        "dendrites": {
            "cable": {
                "cm": lambda d: (11.510294 * math.exp(-1.376463 * d) + 2.120503),
                "Ra": 122,
            },
            "ions": {
                "na": {"e": 60},
                "k": {"e": -88},
                "h": {"e": -34.4},
                "ca": {"e": 137.52625},
            },
            "mechanisms": {
                "Leak": {"e": -61, "gmax": 0.0003},
                "Kv1_1": {"gbar": 0.00105296938319},
                "Kv1_5": {"gKur": 0.00018237109331},
                "Kv3_3": {"gbar": 0.01192448545734},
                "Kv4_3": {"gkbar": 0.00082020749325},
                "Cav2_1": {"pcabar": 0.001594103024736},
                "Cav3_3": {"pcabar": 0.00013000262047},
                "Kca1_1": {"gbar": 0.03803999223084},
                "HCN1": {"gbar": 2.49811225e-06},
                ("cdp5", "CAM"): {},
                "cdp5": {"TotalPump": 5e-08},
            },
        },
        "axon": {"cable": {}, "ions": {}, "mechanisms": {}},
        "ascending_axon": {
            "cable": {},
            "ions": {},
            "mechanisms": {
                ("Na", "granule_cell"): {},
                "Kv3_4": {},
                "Leak": {},
                "Ca": {},
                ("cdp5", "CR"): {},
                "Na": {},
            },
        },
        "parallel_fiber": {
            "cable": {},
            "ions": {},
            "mechanisms": {
                ("Na", "granule_cell"): {},
                "Kv3_4": {},
                "Leak": {},
                "Ca": {},
                ("cdp5", "CR"): {},
                "Na": {},
            },
        },
        "axon_initial_segment": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {"na": {"e": 60}, "k": {"e": -80}, "ca": {"e": 137}},
            "mechanisms": {
                "Leak": {"e": -55, "gmax": 3e-05},
                ("HCN1", "golgi"): {},
                "HCN2": {"gbar": 0.00030643090764},
                "Nav1_6": {"gbar": 0.17233663543619},
                "Ca": {"gcabar": 0.00595046001148},
                "Kca1_1": {"gbar": 0.10008178886943},
                "Km": {"gkbar": 0.00024381226198},
                ("cdp5", "CAM_GoC"): {},
                "HCN1": {"gbar": 0.0003371456442},
                "cdp5": {"TotalPump": 1e-08},
            },
        },
        "axon_hillock": {
            "cable": {},
            "ions": {},
            "mechanisms": {
                "Leak": {},
                ("Na", "granule_cell_FHF"): {},
                "Kv3_4": {},
                "Ca": {},
                ("cdp5", "CR"): {},
                "Na": {},
            },
        },
        "proximal_dendrites": {
            "cable": {"Ra": 110, "cm": 1.5},
            "ions": {"k": {"e": -84}, "ca": {"e": 137.5}},
            "mechanisms": {
                "Leak": {"e": -48, "gmax": 8e-06},
                "Cav3_2": {"gcabar": 0.00070661092763},
                "Cav3_3": {"pcabar": 1.526216781e-05},
                "Kv1_1": {"gbar": 0.0090681056165},
                "Kv4_3": {"gkbar": 0.0026420471354},
                "Kca1_1": {"gbar": 0.00499205404769},
                "Kca2_2": {"gkbar": 3.26194117e-06},
                "Cav2_1": {"pcabar": 0.0008},
                "cdp5": {"TotalPump": 1e-09},
            },
            "synapses": ["AMPA", "NMDA"],
        },
        "distal_dendrites": {
            "cable": {"Ra": 110, "cm": 1.5},
            "ions": {"k": {"e": -84}, "ca": {"e": 137.5}},
            "mechanisms": {
                "Leak": {"e": -48, "gmax": 8e-06},
                "Kv1_1": {"gbar": 0.00237825442906},
                "Kca1_1": {"gbar": 0.00226329455766},
                "Kca2_2": {"gkbar": 1.079984416e-05},
                "Cav2_1": {"pcabar": 0.00025},
                "cdp5": {"TotalPump": 1e-09},
            },
            "synapses": ["AMPA", "NMDA"],
        },
        "basal_dendrites": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {"na": {"e": 60}, "k": {"e": -88}, "ca": {"e": 137.52625}},
            "mechanisms": {
                "Leak": {"e": -61, "gmax": 0.0003},
                "Kir2_3": {"gkbar": 1.135399111e-05},
                "Cav3_1": {"pcabar": 4.0066819e-06},
                "Cav3_2": {"gcabar": 0.00194175819441},
                "Kca2_2": {"gkbar": 0.00078534639818},
                "Kca3_1": {"gkbar": 0.00330481139341},
            },
        },
        "apical_dendrites": {
            "cable": {"Ra": 122, "cm": 2.5},
            "ions": {"na": {"e": 60}, "k": {"e": -80}, "ca": {"e": 137}},
            "mechanisms": {
                "Leak": {"e": -55, "gmax": 3e-05},
                "Nav1_6": {"gbar": 0.00499506303209},
                "Kca1_1": {"gbar": 0.01016375552607},
                "Kca2_2": {"gkbar": 0.00247172479141},
                "Cav2_3": {"gcabar": 0.00128859564935},
                "Cav3_1": {"pcabar": 3.690771983e-05},
                ("cdp5", "CAM_GoC"): {},
                "cdp5": {"TotalPump": 5e-09},
            },
            "synapses": ["AMPA_PF"],
        },
        "sodium_dendrites": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {"na": {"e": 60}, "k": {"e": -88}, "ca": {"e": 137.52625}},
            "mechanisms": {"Nav1_6": {"gbar": 0.01568012827236}},
        },
        "aa_targets": {"cable": {}, "ions": {}, "mechanisms": {}, "synapses": ["AMPA"]},
        "pf_targets": {"cable": {}, "ions": {}, "mechanisms": {}, "synapses": ["AMPA"]},
        "sc_targets": {"cable": {}, "ions": {}, "mechanisms": {}, "synapses": ["GABA"]},
        "AIS": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {"na": {"e": 60}, "k": {"e": -88}, "ca": {"e": 137.52625}},
            "mechanisms": {
                "Leak": {"e": -61, "gmax": 0.0003},
                "Nav1_6": {"gbar": 0.76520432560779},
                "Kv3_4": {"gkbar": 0.01470016164534},
                "Cav2_1": {"pcabar": 0.00028786836482},
                "Cav3_1": {"pcabar": 6.43429659e-06},
                ("cdp5", "CAM"): {},
                "cdp5": {"TotalPump": 2e-08},
            },
        },
        "AIS_K": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {"k": {"e": -88}},
            "mechanisms": {
                "Leak": {"e": -61, "gmax": 0.0003},
                "Kv1_1": {"gbar": 0.01011038066089},
            },
        },
        "axonmyelin": {
            "cable": {"Ra": 122, "cm": 1.87e-11},
            "ions": {},
            "mechanisms": {"pas": {"e": -61, "g": 5.6e-09}},
        },
        "nodes": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {"na": {"e": 60}, "k": {"e": -88}, "ca": {"e": 137.52625}},
            "mechanisms": {
                "Leak": {"e": -61, "gmax": 0.0003},
                "Nav1_6": {"gbar": 0.02749309338198},
                "Kv3_4": {"gkbar": 0.02227585026371},
                "Cav2_1": {"pcabar": 0.00012353396215},
                "Cav3_1": {"pcabar": 1.508814156e-05},
                ("cdp5", "CAM"): {},
                "cdp5": {"TotalPump": 5e-07},
            },
        },
    }

    labels = {
        "basal_dendrites": {"from": "dendrites", "diam": lambda diam: diam >= 1.6},
        "sodium_dendrites": {"from": "dendrites", "diam": lambda diam: diam >= 3.3},
        "aa_targets": {"from": "dendrites", "diam": lambda diam: diam <= 0.75},
        "pf_targets": {
            "from": "dendrites",
            "diam": lambda diam: diam > 0.75 and diam <= 1.6,
        },
        "sc_targets": {
            "from": "dendrites",
            "diam": lambda diam: diam > 0.3 and diam <= 1.6,
        },
    }

    def build_AIS(self):
        ais = p.Section(name="AIS")
        ais.labels = ["AIS"]
        ais.set_dimensions(length=17, diameter=0.97)
        ais.set_segments(1)
        ais.connect(self.soma[0], 0)

        ais_k = p.Section(name="AIS_K")
        ais_k.labels = ["AIS_K"]
        ais_k.set_dimensions(length=4, diameter=0.97)
        ais_k.set_segments(1)
        ais_k.connect(ais, 1)

        myelin_0 = p.Section(name="axonmyelin")
        myelin_0.labels = ["axonmyelin"]
        myelin_0.set_dimensions(length=100, diameter=0.73)
        myelin_0.set_segments(5)
        myelin_0.connect(ais_k, 1)

        node_0 = p.Section(name="node_0")
        node_0.labels = ["nodes"]
        node_0.set_dimensions(length=4, diameter=0.73)
        node_0.set_segments(1)
        node_0.connect(myelin_0, 1)

        myelin_1 = p.Section(name="axonmyelin_1")
        myelin_1.labels = ["axonmyelin"]
        myelin_1.set_dimensions(length=100, diameter=0.73)
        myelin_1.set_segments(5)
        myelin_1.connect(node_0, 1)

        node_1 = p.Section(name="node_1")
        node_1.labels = ["nodes"]
        node_1.set_dimensions(length=4, diameter=0.73)
        node_1.set_segments(1)
        node_1.connect(myelin_1, 1)

        myelin_2 = p.Section(name="axonmyelin_2")
        myelin_2.labels = ["axonmyelin"]
        myelin_2.set_dimensions(length=100, diameter=0.73)
        myelin_2.set_segments(5)
        myelin_2.connect(node_1, 1)

        node_2 = p.Section(name="node_2")
        node_2.labels = ["nodes"]
        node_2.set_dimensions(length=4, diameter=0.73)
        node_2.set_segments(1)
        node_2.connect(myelin_2, 1)

        myelin_3 = p.Section(name="axonmyelin_3")
        myelin_3.labels = ["axonmyelin"]
        myelin_3.set_dimensions(length=100, diameter=0.73)
        myelin_3.set_segments(5)
        myelin_3.connect(node_2, 1)

        self.axon = [
            ais,
            ais_k,
            myelin_0,
            node_0,
            myelin_1,
            node_1,
            myelin_2,
            node_2,
            myelin_3,
        ]

    def set_segments(self):
        """
        All models optimized with BluePyOpt have nseg set in this way when they are
        being optimized: 2 extra segments per 40µm length of the section.
        """
        for s in self.axon + self.dend + self.soma:
            s.nseg = 1 + (2 * int(s.L / 40))
