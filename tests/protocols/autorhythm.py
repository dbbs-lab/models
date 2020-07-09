from ._helpers import *
from patch import p

def run_protocol(cell, duration=100):
    disable_cvode()
    init_simulator(tstop=duration)

    _vm = cell.record_soma()
    _time = p.time

    p.finitialize()
    p.run()

    return ezfel(
        T=list(_time),
        V=list(_vm)
    )
