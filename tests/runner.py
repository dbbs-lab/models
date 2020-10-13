import os, sys, subprocess
from protocols._helpers import efel_dict

def run_protocol(cell_name, protocol_name, **kwargs):
    """
    Execute a test with the name of the cell model, protocol and parameters by invoking
    the `run` script and reading the tail end of the output. That output is evaluated as a
    Python statement and interpreted as a dictionary. The dictionary is supposed to
    contain `stim_start`, `stim_end`, `T` and `V` keys so that those can be used to
    extract efel features.
    """
    out = subprocess.check_output([
        sys.executable,
        os.path.join(os.path.dirname(__file__), "run"),
        cell_name,
        protocol_name,
        *["{}={}".format(k, repr(v)) for k,v in kwargs.items()]
    ]).decode("utf-8")
    return efel_dict(eval(out.split("\n")[-1]))
