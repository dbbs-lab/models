import functools
import arborize
import glia
import sys
import os


class DbbsNeuronModel(arborize.NeuronModel):
    glia_package = "dbbs_mod_collection"

    @classmethod
    def make_catalogue(cls):
        import arbor

        cat = arbor.default_catalogue()
        cat.extend(glia.catalogue("dbbs"), "")
        return cat
