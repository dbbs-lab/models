"""
Collection of single cell models for the Arbor and NEURON simulators of the cerebellar
cortex. Maintained by the Department of Brain and Behavioral Sciences of Pavia.
"""

__version__ = "6.0.0"

from .basket_cell_models import BasketCellModel
from .golgi_cell_models import GolgiCellModel
from .granule_cell_models import GranuleCellModel
from .purkinje_cell_models import PurkinjeCellModel
from .stellate_cell_models import StellateCellModel
from .test import quick_plot, quick_test


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

    from arborize import bsb_schematic, neuron_build

    try:
        from bsb import parse_morphology_file
    except ImportError:
        # The builders use the BSB's morphology parser because of
        # https://github.com/BlueBrain/MorphIO/issues/469
        # Once this is fixed we can switch to MorphIO
        raise RuntimeError("To use the `build_*` factories, please `pip install bsb`.")

    return neuron_build(
        bsb_schematic(
            parse_morphology_file(
                Path(__file__).parent / "morphologies" / morphology_file,
                tags=getattr(definition, "swc_tags", None),
            ),
            definition,
        )
    )
