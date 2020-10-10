#!/usr/bin/env python3

import ndsb, os, sys, pathlib

sys.path.insert(1, str(pathlib.Path(os.getcwd()) / "tests"))
import protocols
pickles = ndsb.thaw()
try:
    beam = ndsb.artificer(pickles)
    response = beam.fire(os.getenv("NDSB_VAULT_URL"), os.getenv("NDSB_VAULT_KEY"))
    beam_id = response["id"]

beam_path = pathlib.Path(os.getenv("NDSB_VAULT_URL")).parent
trace_path = beam_path / f"emit/{beam_id}/0/trace.html"
