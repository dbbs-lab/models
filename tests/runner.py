import os, sys, subprocess
from protocols._helpers import efel_dict

def run_protocol(cell_name, protocol_name, **kwargs):
    out = subprocess.check_output([
        sys.executable,
        os.path.join(os.path.dirname(__file__), "run"),
        cell_name,
        protocol_name,
        *["{}={}".format(k, repr(v)) for k,v in kwargs.items()]
    ]).decode("utf-8")
    return efel_dict(eval(out.split("\n")[-1]))
