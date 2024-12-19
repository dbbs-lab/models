from arborize import define_model

BasketCellModel = define_model(
    {
        "synapse_types": {
            "AMPA": {
                "mechanism": "AMPA",
                "parameters": {
                    "tau_facil": 54,
                    "tau_rec": 35.1,
                    "tau_1": 6,
                    "gmax": 1200,
                    "U": 0.4,
                },
            },
            "NMDA": {
                "mechanism": ("NMDA", "stellate"),
                "parameters": {
                    "tau_facil": 5,
                    "tau_rec": 8,
                    "tau_1": 1,
                    "gmax": 5000,
                    "U": 0.15,
                },
            },
            "GABA": {
                "mechanism": "GABA",
                "paremeters": {
                    "tau_facil": 0,
                    "tau_rec": 38.7,
                    "tau_1": 1,
                    "gmax": 3200,
                    "U": 0.42,
                    "Erev": -65,
                },
            },
        },
        "cable_types": {
            "soma": {
                "cable": {"Ra": 122, "cm": 1},
                "ions": {
                    "na": {"rev_pot": 60},
                    "k": {"rev_pot": -80},
                    "ca": {"rev_pot": 137.5},
                    "h": {"rev_pot": -34},
                },
                "mechanisms": {
                    "Leak": {"e": -50, "gmax": 1e-06},
                    "Nav1_1": {"gbar": 0.4},
                    "Cav3_2": {"gcabar": 0.0001},
                    "Cav12": {"gcabar": 0.0007},
                    "Cav13": {"gcabar": 5e-06},
                    "Kir2_3": {"gkbar": 0.0001},
                    "Kv3_4": {"gkbar": 0.005},
                    "Kv4_3": {"gkbar": 0.001},
                    "Kca3_1": {"gbar": 0.001},
                    "HCN1": {"gbar": 0.001},
                    "cdp5": {"TotalPump": 1e-09},
                },
            },
            "dendrites": {
                "cable": {"Ra": 122, "cm": 1},
                "ions": {"k": {"rev_pot": -80}},
                "mechanisms": {
                    "Leak": {"e": -50, "gmax": 1e-06},
                    "Cav3_2": {"gcabar": 0.00001},
                    "Cav12": {"gcabar": 0.002},
                    "Cav13": {"gcabar": 5e-06},
                    "Kv4_3": {"gkbar": 0.00987201764943},
                    "Kca2_2": {"gbar": 0.002},
                    "cdp5": {"TotalPump": 1e-09},
                },
            },
            "axon": {
                "cable": {"Ra": 122, "cm": 1},
                "ions": {
                    "na": {"rev_pot": 60},
                    "k": {"rev_pot": -80},
                    "h": {"rev_pot": -34},
                },
                "mechanisms": {
                    "Leak": {"e": -50, "gmax": 1e-06},
                    "Kv1_1": {"gbar": 0.00004},
                    "Nav1_6": {"gbar": 0.03},
                    "Kv3_4": {"gkbar": 0.008},
                    "HCN1": {"gbar": 0.0003},
                    "Kca1_1": {"gkbar": 0.005},
                    "Cav2_1": {"gkbar": 0.00008},
                    "cdp5": {},
                },
            },
            "axon_initial_segment": {
                "cable": {"Ra": 122, "cm": 1},
                "ions": {
                    "na": {"rev_pot": 60},
                    "k": {"rev_pot": -80},
                    "h": {"rev_pot": -34},
                },
                "mechanisms": {
                    "Leak": {"e": -50, "gmax": 1e-06},
                    "HCN1": {"gbar": 0.001},
                    "Nav1_6": {"gbar": 1},
                    "Kv1_1": {"gbar": 0.02333516534870},
                    "Kv3_4": {"gkbar": 0.008},
                    "Kca1_1": {"gkbar": 0.009},
                    "Cav2_1": {"gkbar": 0.009},
                    "cdp5": {},
                },
            },
        },
    },
    use_defaults=True,
)

BasketCellModel.swc_tags = {
    6: ["axon", "axon_initial_segment"],
}
