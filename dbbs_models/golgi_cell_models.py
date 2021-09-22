from ._shared import DbbsNeuronModel
from arborize import compose_types
from arborize.builders import rotate, blue_nseg


class GolgiCell(DbbsNeuronModel):
    morphologies = ["GolgiCell.swc"]

    synapse_types = {
        "AMPA_PF": {
            "point_process": "AMPA",
            "attributes": {
                "tau_facil": 54,
                "tau_rec": 35.1,
                "tau_1": 30,
                "gmax": 1200,
                "U": 0.4,
            },
        },
        "AMPA_AA": {
            "point_process": "AMPA",
            "attributes": {
                "tau_facil": 54,
                "tau_rec": 35.1,
                "tau_1": 30,
                "gmax": 1200,
                "U": 0.4,
            },
        },
        "AMPA_MF": {
            "point_process": ("AMPA", "granule"),
        },
        "NMDA": {
            "point_process": ("NMDA", "stellate"),
            "attributes": {
                "tau_facil": 5,
                "tau_rec": 8,
                "tau_1": 1,
                "gmax": 10000,
                "U": 0.43,
            },
        },
        "GABA": {
            "point_process": "GABA",
            "attributes": {
                "tau_facil": 0,
                "tau_rec": 38.7,
                "tau_1": 1,
                "gmax": 3200,
                "U": 0.42,
                "Erev": -65,
            },
        },
        "gap_s": {"point_process": "gap_junction", "source": "vgap"},
        "gap": {"point_process": ("gap_junction", "parallel"), "source": "vgap"},
    }

    section_types = {
        "soma": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {"na": {"e": 60}, "k": {"e": -80}, "ca": {"e": 140.70872293}},
            "mechanisms": {
                "Leak": {"e": -55, "gmax": 3e-05},
                "Nav1_6": {"gbar": 0.14927733727426},
                "Kv1_1": {"gbar": 0.00549507510519},
                "Kv3_4": {"gkbar": 0.14910988921938},
                "Kv4_3": {"gkbar": 0.00406420380423},
                "Kca1_1": {"gbar": 0.01764345789036},
                "Kca3_1": {"gkbar": 0.10177335775222},
                "Ca": {"gcabar": 0.0087689418803},
                "Cav3_1": {"pcabar": 3.407734319e-05},
                ("cdp5", "CAM_GoC"): {"TotalPump": 1e-07},
            },
        },
        "dendrites": {"cable": {}, "ions": {}, "mechanisms": {}},
        "basal_dendrites": {
            "cable": {"Ra": 122, "cm": 2.5},
            "ions": {"na": {"e": 60}, "k": {"e": -80}, "ca": {"e": 140.70872293}},
            "mechanisms": {
                "Leak": {"e": -55, "gmax": 3e-05},
                "Nav1_6": {"gbar": 0.0080938853146},
                "Kca1_1": {"gbar": 0.01226052748146},
                "Kca2_2": {"gkbar": 0.01650689958385},
                "Ca": {"gcabar": 0.00139885617712},
                ("cdp5", "CAM_GoC"): {"TotalPump": 2e-09},
            },
            "synapses": ["AMPA_AA", "AMPA_MF", "NMDA", "GABA", "gap", "gap_s"],
        },
        "apical_dendrites": {
            "cable": {"Ra": 122, "cm": 2.5},
            "ions": {"na": {"e": 60}, "k": {"e": -80}, "ca": {"e": 140.70872293}},
            "mechanisms": {
                "Leak": {"e": -55, "gmax": 3e-05},
                "Nav1_6": {"gbar": 0.00499506303209},
                "Kca1_1": {"gbar": 0.01016375552607},
                "Kca2_2": {"gkbar": 0.00247172479141},
                "Cav2_3": {"gcabar": 0.00128859564935},
                "Cav3_1": {"pcabar": 3.690771983e-05},
                ("cdp5", "CAM_GoC"): {"TotalPump": 5e-09},
            },
            "synapses": ["AMPA_PF"],
        },
        "axon": {
            "cable": {"Ra": 122, "cm": 1},
            "ions": {"na": {"e": 60}, "k": {"e": -80}, "ca": {"e": 140.70872293}},
            "mechanisms": {
                "Leak": {"e": -55, "gmax": 1e-06},
                "Nav1_6": {"gbar": 0.0115},
                "Kv3_4": {"gkbar": 0.0091},
                ("cdp5", "CAM_GoC"): {"TotalPump": 1e-08},
            },
        },
        "axon_initial_segment": compose_types(
            "axon",
            {
                "cable": {"Ra": 122, "cm": 1},
                "ions": {"na": {"e": 60}, "k": {"e": -80}, "ca": {"e": 140.70872293}},
                "mechanisms": {
                    "Leak": {"e": -55, "gmax": 3e-05},
                    ("HCN1", "golgi"): {"gbar": 0.0003371456442},
                    "HCN2": {"gbar": 0.00030643090764},
                    "Nav1_6": {"gbar": 0.17233663543619},
                    "Ca": {"gcabar": 0.00595046001148},
                    "Kca1_1": {"gbar": 0.10008178886943},
                    "Km": {"gkbar": 0.00024381226198},
                    ("cdp5", "CAM_GoC"): {"TotalPump": 1e-08},
                },
            },
        ),
    }

    tags = {
        16: ["dendrites", "basal_dendrites"],
        17: ["dendrites", "apical_dendrites"],
        18: ["axon", "axon_initial_segment"],
    }
