from ._shared import DbbsNeuronModel
from arborize import compose_types
from patch import p
import math


def _lbl_pdi(region, d):
    return f'(distal-interval (proximal (region "{region}")) {d})'


def _lbl_select(region, f, t):
    return f"(difference {_lbl_pdi(region, t)} {_lbl_pdi(region, f)})"


class PurkinjeCell(DbbsNeuronModel):
    @staticmethod
    def builder(model):
        model.build_AIS()
        model.set_segments()

    morphologies = ["purkinje_cell.swc"]

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
                ("cdp5", "CAM"): {"TotalPump": 2e-08},
            },
            "synapses": ["GABA"],
        },
        "dendrites": {
            "cable": {
                # Formula for cm varied from 2 to 6, aprroximated with 4.5
                "cm": 5.577701084442752,
                # "cm": lambda d: (11.510294 * math.exp(-1.376463 * d) + 2.120503),
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
                ("cdp5", "CAM"): {"TotalPump": 5e-08},
            },
            "synapses": ["AMPA_PF"],
        },
        "basal_dendrites": compose_types(
            "dendrites",
            {
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
        ),
        "sodium_dendrites": compose_types(
            "dendrites",
            {
                "cable": {"Ra": 122, "cm": 1},
                "ions": {"na": {"e": 60}, "k": {"e": -88}, "ca": {"e": 137.52625}},
                "mechanisms": {
                    "Leak": {"e": -61, "gmax": 0.0003},
                    "Kir2_3": {"gkbar": 1.135399111e-05},
                    "Cav3_1": {"pcabar": 4.0066819e-06},
                    "Cav3_2": {"gcabar": 0.00194175819441},
                    "Kca2_2": {"gkbar": 0.00078534639818},
                    "Kca3_1": {"gkbar": 0.00330481139341},
                    "Nav1_6": {"gbar": 0.01568012827236},
                },
            },
        ),
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
                ("cdp5", "CAM"): {"TotalPump": 2e-08},
            },
        },
        "axon": {"cable": {}, "ions": {}, "mechanisms": {}},
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
                ("cdp5", "CAM"): {"TotalPump": 5e-07},
            },
        },
    }

    labels = {
        "soma": {"arbor": "(tag 1)"},
        "axon": {"arbor": "(tag 2)"},
        "dend": {"arbor": "(tag 3)"},
        "basal_dendrites": {
            "from": "dendrites",
            "diam": lambda diam: diam >= 1.6,
            "arbor": '(difference (radius-ge (region "dend") 0.8) (region "sodium_dendrites"))',
        },
        "sodium_dendrites": {
            "from": "dendrites",
            "diam": lambda diam: diam >= 3.3,
            "arbor": '(radius-ge (region "dend") 1.65)',
        },
        "aa_targets": {
            "from": "dendrites",
            "diam": lambda diam: diam <= 0.75,
            "arbor": '(radius-le (region "dend") 0.375)',
        },
        "pf_targets": {
            "from": "dendrites",
            "diam": lambda diam: diam > 0.75 and diam <= 1.6,
            "arbor": '(intersect (radius-gt (region "dend") 0.375) (radius-le (region "dend") 0.8))',
        },
        "sc_targets": {
            "from": "dendrites",
            "diam": lambda diam: diam > 0.3 and diam <= 1.6,
            "arbor": '(intersect (radius-gt (region "dend") 0.15) (radius-le (region "dend") 0.8))',
        },
        "AIS": {"arbor": '(distal-interval (proximal (region "axon")) 17)'},
        "AIS_K": {
            "arbor": '(difference (distal-interval (proximal (region "axon")) 21) (region"AIS"))'
        },
        "axonmyelin": {
            "arbor": "(join {})".format(
                " ".join(
                    # Select axonal intervals in micrometers
                    _lbl_select("axon", 21 + i * 104, 21 + i * 104 + 100)
                    for i in range(4)
                )
            )
        },
        "nodes": {
            "arbor": "(join {})".format(
                " ".join(
                    # Select axonal intervals in micrometers
                    _lbl_select("axon", 21 + i * 104 + 100, 21 + (i + 1) * 104)
                    for i in range(4)
                )
            )
        },
    }

    tag_translations = {
        16: ["axon", "AIS"],
        17: ["axon", "AIS_K"],
        18: ["axon", "axonmyelin"],
        19: ["axon", "nodes"],
        20: ["dendrites", "basal_dendrites"],
        21: ["dendrites", "pf_targets", "sc_targets"],
        22: ["dendrites", "aa_targets", "sc_targets"],
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
