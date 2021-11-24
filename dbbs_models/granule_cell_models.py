import numpy as np
from patch import p
from ._shared import DbbsNeuronModel
from math import floor
from arborize import compose_types


class GranuleCell(DbbsNeuronModel):
    @staticmethod
    def builder(model):
        model.fiber_section_length = 20  # µm (parallel fiber section length)
        model.fiber_segment_length = 7
        model.ascending_axon_length = 126  # µm
        model.parallel_fiber_length = 2000  # µm
        model.build_soma()
        model.build_dendrites()
        model.build_hillock()
        model.build_ascending_axon()
        model.build_parallel_fiber()

    #morphologies = [builder]
    morphologies = ["granule_cell.swc"]

    synapse_types = {
        "AMPA": {
            "point_process": ("AMPA", "granule"),
            "attributes": {
                "tau_facil": 5,
                "tau_rec": 8,
                "tau_1": 1,
                "gmax": 1400,
                "U": 0.43,
            },
        },
        "NMDA": {
            "point_process": ("NMDA", "granule"),
            "attributes": {
                "tau_facil": 5,
                "tau_rec": 8,
                "tau_1": 1,
                "gmax": 23500,
                "U": 0.43,
            },
        },
        "GABA": {"point_process": ("GABA", "granule"), "attributes": {"U": 0.35}},
    }

    section_types = {
        "soma": {
            "cable": {"Ra": 100, "cm": 2},
            "ions": {"k": {"e": -80.993}, "ca": {"e": 137.5}},
            "mechanisms": {
                "Leak": {"e": -60, "gmax": 0.00029038073716},
                "Kv3_4": {"gkbar": 0.00076192450952},
                "Kv4_3": {"gkbar": 0.00281496839061},
                "Kir2_3": {"gkbar": 0.00074725514702},
                "Ca": {"gcabar": 0.00060938071784},
                "Kv1_1": {"gbar": 0.00569738264555},
                "Kv1_5": {"gKur": 0.00083407556714},
                "Kv2_2": {"gKv2_2bar": 1.203410852e-05},
                ("cdp5", "CR"): {},
            },
        },
        "dendrites": {
            "cable": {"Ra": 100, "cm": 2.5},
            "ions": {"k": {"e": -80.993}, "ca": {"e": 137.5}},
            "mechanisms": {
                "Leak": {"e": -60, "gmax": 0.00025029700737},
                ("Leak", "GABA"): {},
                "Ca": {"gcabar": 0.00500128008459},
                "Kca1_1": {"gbar": 0.01001807454651},
                "Kv1_1": {"gbar": 0.00381819207934},
                ("cdp5", "CR"): {},
            },
        },
        "axon": {"cable": {}, "ions": {}, "mechanisms": {}},
        "ascending_axon": {
            "cable": {"Ra": 100, "cm": 1},
            "ions": {"na": {"e": 87.39}, "k": {"e": -80.993}, "ca": {"e": 137.5}},
            "mechanisms": {
                ("Na", "granule_cell"): {"gnabar": 0.02630163681502},
                "Kv3_4": {"gkbar": 0.00237386061632},
                "Leak": {"e": -60, "gmax": 9.364092125e-05},
                "Ca": {"gcabar": 0.00068197420273},
                ("cdp5", "CR"): {},
            },
        },
        "parallel_fiber": {
            "cable": {"Ra": 100, "cm": 1},
            "ions": {"na": {"e": 87.39}, "k": {"e": -80.993}, "ca": {"e": 137.5}},
            "mechanisms": {
                ("Na", "granule_cell"): {"gnabar": 0.01771848449261},
                "Kv3_4": {"gkbar": 0.00817568047037},
                "Leak": {"e": -60, "gmax": 3.5301616e-07},
                "Ca": {"gcabar": 0.0002085683353},
                ("cdp5", "CR"): {},
            },
        },
        "axon_initial_segment": compose_types(
            "ascending_axon",
            {
                "cable": {"Ra": 100, "cm": 1},
                "ions": {"na": {"e": 87.39}, "k": {"e": -80.993}, "ca": {"e": 137.5}},
                "mechanisms": {
                    ("Na", "granule_cell_FHF"): {"gnabar": 1.28725006737226},
                    "Kv3_4": {"gkbar": 0.00649595340654},
                    "Leak": {"e": -60, "gmax": 0.00029276697557},
                    "Ca": {"gcabar": 0.00031198539472},
                    "Km": {"gkbar": 0.00056671971737},
                    ("cdp5", "CR"): {},
                },
            },
        ),
        "axon_hillock": compose_types(
            "ascending_axon",
            {
                "cable": {"Ra": 100, "cm": 2},
                "ions": {"na": {"e": 87.39}, "k": {"e": -80.993}, "ca": {"e": 137.5}},
                "mechanisms": {
                    "Leak": {"e": -60, "gmax": 0.0003695818972},
                    ("Na", "granule_cell_FHF"): {"gnabar": 0.00928805851462},
                    "Kv3_4": {"gkbar": 0.02037346310915},
                    "Ca": {"gcabar": 0.00057726155447},
                    ("cdp5", "CR"): {},
                },
            },
        ),
    }

    def build_soma(self):
        soma = p.Section()
        soma.set_dimensions(length=5.62232, diameter=5.8)
        soma.set_segments(1)
        soma.add_3d([self.position, self.position + [0.0, 5.62232, 0.0]])
        soma.labels = ["soma"]
        self.sections.append(soma)

    def build_dendrites(self):
        dends = []
        for i in range(4):
            dendrite = p.Section()
            dends.append(dendrite)
            dendrite_position = self.position.copy()
            # Shift the dendrites a little bit for voxelization
            dendrite_position[0] += (i - 1.5) * 2
            dendrite.set_dimensions(length=15, diameter=0.75)
            points = []
            for j in range(10):
                pt = dendrite_position.copy()
                pt[1] -= dendrite.L * j / 10
                points.append(pt)
            dendrite.add_3d([[p[0], p[1], p[2]] for p in points])
            dendrite.connect(self.soma[0], 0)
            dendrite.labels = ["dendrites"]
        self.sections.extend(dends)


    def build_hillock(self):
        hillock = p.Section()
        hillock.set_dimensions(length=1, diameter=1.5)
        hillock.set_segments(1)
        hillock.add_3d(
            [self.position + [0.0, 5.62232, 0.0], self.position + [0.0, 6.62232, 0.0]]
        )
        hillock.labels = ["axon", "axon_hillock"]
        hillock.connect(self.soma[0], 0)
        self.sections.append(hillock)

        ais = p.Section(name="axon_initial_segment")
        ais.labels = ["axon", "axon_initial_segment"]
        ais.set_dimensions(length=10, diameter=0.7)
        ais.set_segments(1)
        ais.add_3d(
            [self.position + [0.0, 6.62232, 0.0], self.position + [0.0, 16.62232, 0.0]]
        )
        ais.connect(hillock, 1)
        self.sections.append(ais)


    def build_ascending_axon(self):
        seg_length = self.fiber_segment_length
        n = int(self.ascending_axon_length / seg_length)

        ascending_axon = p.Section()
        ascending_axon.labels = ["ascending_axon"]
        ascending_axon.nseg = int(n)
        ascending_axon.L = self.ascending_axon_length
        ascending_axon.diam = 0.3
        previous_section = self.axon_initial_segment[-1]
        self.axon.append(ascending_axon)
        ascending_axon.connect(previous_section)
        ascending_axon.labels = ["axon", "ascending_axon"]
        self.sections.append(ascending_axon)

        y = 16.62232

        # Extract a set of intermediate points between start and end of ascending_axon to improve voxelization in scaffold
        fraction = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]

        points = [
            self.position + [0.0, (y + f * self.ascending_axon_length), 0.0]
            for f in fraction
        ]

        ascending_axon.add_3d(points)

        # Store the last used y position as the start for the parallel fiber
        self.y_pf = y + (seg_length * n)

    def build_parallel_fiber(self):
        section_length = self.fiber_section_length
        n = int(self.parallel_fiber_length / section_length)
        pf_sections = [
            p.Section(name="parellel_fiber_" + str(x)) for x in range(n)
        ]
        # Use the last AA y as Y for the PF
        y = self.y_pf
        center = self.position[2]
        for id, section in enumerate(pf_sections):
            section.labels = ["axon", "parallel_fiber"]
            section.set_dimensions(length=section_length, diameter=0.3)
            sign = 1 - (id % 2) * 2
            z = floor(id / 2) * section_length
            section.add_3d(
                [
                    self.position + [0.0, y, center + sign * z],
                    self.position + [0.0, y, center + sign * (z + section_length)],
                ]
            )
            if id < 2:
                section.connect(self.ascending_axon[-1])
            else:
                section.connect(pf_sections[id - 2])
            z += section_length
        self.sections.extend(pf_sections)

    labels = {
        "soma": {"arbor": "(tag 1)"},
        "axon": {"arbor": "(tag 2)"},
        "dend": {"arbor": "(tag 3)"},
        "ascending_axon": {"arbor": "(branch 1)"},
        "axon_hillock": {
            "arbor": '(distal-interval (proximal (region "ascending_axon")) 1)'
        },
        "axon_initial_segment": {
            "arbor": '(difference (distal-interval (proximal (region "ascending_axon")) 11) (region "axon_hillock"))'
        },
        "parallel_fiber": {
            "arbor": '(difference (region "axon") (region "ascending_axon"))'
        },
    }
