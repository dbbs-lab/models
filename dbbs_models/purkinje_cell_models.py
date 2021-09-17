from ._shared import DbbsNeuronModel
from arborize import compose_types


def _lbl_pdi(region, d):
    return f'(distal-interval (proximal (region "{region}")) {d})'


def _lbl_select(region, f, t):
    return f"(difference {_lbl_pdi(region, t)} {_lbl_pdi(region, f)})"


class PurkinjeCell(DbbsNeuronModel):
    morphologies = ["PurkinjeCell.swc"]

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
                "k": {"e": -80.993},
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
                # "cm": lambda d: (11.510294 * math.exp(-1.376463 * d) + 2.120503),
                # Formula for cm varied from 2 to 6, aprroximated with avg
                "cm": 5.577701084442752,
                "Ra": 122,
            },
            "ions": {
                "na": {"e": 60},
                "k": {"e": -80.993},
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
                "ions": {"na": {"e": 60}, "k": {"e": -80.993}, "ca": {"e": 137.52625}},
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
                "ions": {"na": {"e": 60}, "k": {"e": -80.993}, "ca": {"e": 137.52625}},
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
            "ions": {"na": {"e": 60}, "k": {"e": -80.993}, "ca": {"e": 137.52625}},
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
            "ions": {"k": {"e": -80.993}},
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
            "ions": {"na": {"e": 60}, "k": {"e": -80.993}, "ca": {"e": 137.52625}},
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
        "basal_dendrites": {
            "arbor": '(difference (radius-ge (region "dendrites") 0.8) (region "sodium_dendrites"))',
        },
        "sodium_dendrites": {
            "arbor": '(radius-ge (region "dendrites") 1.65)',
        },
        "aa_targets": {
            "arbor": '(radius-le (region "dendrites") 0.375)',
        },
        "pf_targets": {
            "arbor": '(intersect (radius-gt (region "dendrites") 0.375) (radius-le (region "dendrites") 0.8))',
        },
        "sc_targets": {
            "arbor": '(intersect (radius-gt (region "dendrites") 0.15) (radius-le (region "dendrites") 0.8))',
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

    tags = {
        16: ["axon", "AIS"],
        17: ["axon", "AIS_K"],
        18: ["axon", "axonmyelin"],
        19: ["axon", "nodes"],
        20: ["dendrites", "basal_dendrites"],
        21: ["dendrites", "pf_targets", "sc_targets"],
        22: ["dendrites", "aa_targets", "sc_targets"],
    }
