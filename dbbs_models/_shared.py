import arborize, os, sys

_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), "morphologies"))

class DbbsNeuronModel(arborize.NeuronModel, abstract=True):
    glia_package = "dbbs_mod_collection"
    morphology_directory = _dir
