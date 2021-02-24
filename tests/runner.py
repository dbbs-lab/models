import os, sys, subprocess, json, pickle, codecs
from protocols._helpers import efel_dict, boundary


def run_protocol(cell_name, protocol_name, **kwargs):
    """
    Execute a test with the name of the cell model, protocol and parameters by invoking
    the `run` script and reading the tail end of the output. That output is evaluated as a
    Python statement and interpreted as a dictionary. The dictionary is supposed to
    contain `stim_start`, `stim_end`, `T` and `V` keys so that those can be used to
    extract efel features.
    """
    try:
        out = subprocess.check_output(
            [
                sys.executable,
                os.path.join(os.path.dirname(__file__), "run"),
                cell_name,
                protocol_name,
                *["{}={}".format(k, repr(v)) for k, v in kwargs.items()],
            ]
        )
    except subprocess.CalledProcessError as e:
        raise RuntimeError(e.output)
    else:
        return _parse_output(out)


def run_multicell(protocol_name, cell_list, **kwargs):
    """
    Execute a test with the name of the cell model, protocol and parameters by invoking
    the `run` script and reading the tail end of the output. That output is evaluated as a
    Python statement and interpreted as a dictionary. The dictionary is supposed to
    contain `stim_start`, `stim_end`, `T` and `V` keys so that those can be used to
    extract efel features.
    """
    kwargs["cell_list"] = cell_list
    try:
        out = subprocess.check_output(
            [
                sys.executable,
                os.path.join(os.path.dirname(__file__), "run"),
                "__scheme__multicell",
                protocol_name,
                json.dumps(kwargs),
            ]
        )
    except subprocess.CalledProcessError as e:
        raise RuntimeError(e.output)
    else:
        return _parse_output(out)


def run_paracell(protocol_name, cell_list, **kwargs):
    """
    Execute a test with the name of the cell model, protocol and parameters by invoking
    the `run` script and reading the tail end of the output. That output is evaluated as a
    Python statement and interpreted as a dictionary. The dictionary is supposed to
    contain `stim_start`, `stim_end`, `T` and `V` keys so that those can be used to
    extract efel features.
    """
    kwargs["cell_list"] = cell_list
    try:
        out = subprocess.check_output(
            [
                sys.executable,
                os.path.join(os.path.dirname(__file__), "run"),
                "__scheme__paracell",
                protocol_name,
                json.dumps(kwargs),
            ]
        )
    except subprocess.CalledProcessError as e:
        raise RuntimeError(e.output)
    else:
        return _parse_output(out)


def _parse_output(out):
    b = bytes(boundary, "utf-8")
    c = out.count(b)
    if c != 2:
        raise RuntimeError(
            f"Communication error with subprocess, received {c} boundary signals, expected 2."
        )
    b64str = out.split(b)[1]
    bytestream = codecs.decode(b64str, "base64")
    return pickle.loads(bytestream)
