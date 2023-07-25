__version__ = "4.0.0a0"

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
    from bsb.morphologies import Morphology

    return neuron_build(
        bsb_schematic(
            Morphology.from_swc(
                Path(__file__).parent / "morphologies" / morphology_file,
                tags=getattr(definition, "swc_tags", None),
            ),
            definition,
        )
    )
