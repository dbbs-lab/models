import os, sys
from neuron import h
from .exceptions import ModelClassError
h.load_file('stdlib.hoc')
h.load_file('import3d.hoc')

class DbbsModel:

    def __init__(self, morphology_id=0):
        # Check if morphologies were specified
        if not hasattr(self.__class__, "morphologies"):
            raise ModelClassError("All DbbsModel classes should specify an array of morphology files")
        # Import the morphologies if they haven't been imported yet
        if not hasattr(self.__class__, "imported_morphologies"):
            self.__class__.import_morphologies()

        # Use the imported morphologies to instantiate this cell.
        self.__class__.imported_morphologies[morphology_id].instantiate(self)
        # Alias `dend` to the full name
        self.dendrites = self.dend
        self.sections = self.dend + self.axon + self.soma

        # Do labelling of sections into special sections
        self.apply_labels()

        print(dir(self))

        # Initialize the labelled sections
        for section in self.sections:
            self.init_section(section)

        # Call boot method so that child classes can easily do stuff after init.
        self.boot()

    @classmethod
    def import_morphologies(cls):
        cls.imported_morphologies = []
        for morphology in cls.morphologies:
            file = os.path.join(os.path.dirname(__file__), "../morphologies", morphology)
            loader = h.Import3d_Neurolucida3()
            loader.input(file)
            imported_morphology = h.Import3d_GUI(loader, 0)
            cls.imported_morphologies.append(imported_morphology)

    def apply_labels(self):
        self.soma[0].__dict__["dbbs_label"] = "soma"
        for section in self.dendrites:
            section.__dict__["dbbs_label"] = "dendrites"
        for section in self.axon:
            section.__dict__["dbbs_label"] = "axon"
        # Apply special labels
        if hasattr(self.__class__, "labels"):
            for label, category in self.__class__.labels.items():
                targets = self.__dict__[category["from"]]
                for id, target in enumerate(targets):
                    if category["id"](id):
                        target.__dict__["dbbs_label"] = label

    def init_section(self, section):
        print("init section")
        section.nseg = 1 + (2 * int(section.L / 40))
        definition = self.__class__.section_types[section.dbbs_label]
        for mechanism in definition["mechanisms"]:
            section.insert(mechanism)
        for attribute, value in definition["attributes"].items():
            section.__dict__[attribute] = value
        section.push()
        h.pop_section()

    def boot(self):
        pass
