"""
Collection of single cell models for the Arbor and NEURON simulators of the cerebellar
cortex. Maintained by the Department of Brain and Behavioral Sciences of Pavia.
"""

__version__ = "4.0.0b0"

from .granule_cell_models import GranuleCellModel
from .stellate_cell_models import StellateCellModel
from .basket_cell_models import BasketCellModel
from .golgi_cell_models import GolgiCellModel
from .purkinje_cell_models import PurkinjeCellModel

from .test import quick_test, quick_plot


def build_granule_cell():
    return _build(GranuleCellModel, "GranuleCell.swc")


def build_golgi_cell():
    return _build(GolgiCellModel, "GolgiCell.swc")


def build_purkinje_cell():
    return _build(PurkinjeCellModel, "PurkinjeCell.swc")


def build_basket_cell():
    return _build(BasketCellModel, "BasketCell.swc")


def build_stellate_cell():
    return _build(StellateCellModel, "StellateCell.swc")


def _build(definition, morphology_file):
    from pathlib import Path
    from arborize import neuron_build, bsb_schematic
    try:
        from bsb.morphologies import Morphology
    except ImportError:
        # The builders use the BSB's morphology parser because of
        # https://github.com/BlueBrain/MorphIO/issues/469
        # Once this is fixed we can switch to MorphIO
        raise RuntimeError("To use the `build_*` factories, please `pip install bsb`.")

    return neuron_build(
        bsb_schematic(
            Morphology.from_swc(
                Path(__file__).parent / "morphologies" / morphology_file,
                tags=getattr(definition, "swc_tags", None),
            ),
            definition,
        )
    )
