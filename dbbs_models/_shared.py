import functools
import arborize
import glia
import sys
import os

_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), "morphologies"))


class DbbsNeuronModel(arborize.NeuronModel, abstract=True):
    glia_package = "dbbs_mod_collection"
    morphology_directory = _dir

    @classmethod
    def make_catalogue(cls):
        import arbor

        cat = arbor.default_catalogue()
        cat.extend(glia.catalogue("dbbs"), "")
        return cat
