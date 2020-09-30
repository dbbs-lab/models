#!/usr/bin/env python3

import ndsb, os

pickles = ndsb.thaw()
beam = ndsb.artificer()
beam.fire(os.getenv("NDSB_VAULT_URL"), os.getenv("NDSB_VAULT_KEY"), debug=True)
