import os, sys
from neuron import h
from .exceptions import ModelClassError
h.load_file('stdlib.hoc')
h.load_file('import3d.hoc')

class DbbsModel:

    def __init__(self, morphology):
        # Check if morphologies were specified
        if not hasattr(self.__class__, "morphologies"):
            raise ModelClassError("All DbbsModel classes should specify an array of morphology files")
        # Import the morphologies if they haven't been imported yet
        if not hasattr(self.__class__, "imported_morphologies"):
            self.__class__.imported_morphologies()

        # Use the imported morphologies to instantiate this cell.
        self.__class__.imported_morphologies[morphology].instantiate(self)
        # Alias `dend` to the full name
        self.dendrites = self.dend

        # Do labelling of sections into special sections
        self.apply_labels()

        # Initialize the sections
        for section in self.sections:
            self.init_section(section)

    @classmethod
    def imported_morphologies(cls):
        cls.imported_morphologies = []
        for morphology in cls.morphologies:
            file = os.path.join(os.path.dirname(__file__), "../morphologies", morphology)
            loader = h.Import3d_Neurolucida3()
            loader.input(file)
            imported_morphology = h.Import3d_GUI(loader, 0)
            cls.imported_morphologies.append(imported_morphology)

    def apply_labels(self):
        self.soma[0].dbbs_label = "soma"
        for section in dendrites:
            section.dbbs_label = "dendrites"
        for section in axon:
            section.dbbs_label = "axon"
        # Apply special labels
        if hasattr(self, "labels"):
            for label, category in self.labels.items():
                targets = self.__dict__[category["from"]]
                for id, target in enumerate(targets):
                    if category["id"](id):
                        target.dbbs_label = label

    def init_section(self, section):
        section.nseg = 1 + (2 * int(section.L / 40))
        definition = self.sections[section.dbbs_label]
        for mechanism in definition["mechanisms"]:
            section.insert(mechanism)
        for attribute, value in definition["attributes"].items():
            section.__dict__[attribute] = value
        section.push()
        h.pop_section()
