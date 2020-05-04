__version__ = "0.4.0"
import os, sys

if not os.getenv("SETUPTOOLS_INSTALL"):

    from .granule_cell_models import GranuleCell
    from .stellate_cell_models import StellateCell
    from .basket_cell_models import BasketCell
    from .golgi_cell_models import GolgiCell
    from .purkinje_cell_models import PurkinjeCell
    import arborize

    arborize.add_directory(os.path.abspath(os.path.join(os.path.dirname(__file__), "morphologies")))
