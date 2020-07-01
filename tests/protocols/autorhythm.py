from ._helpers import *
from patch import p

def run_protocol(cell):
    disable_cvode()
    init_simulator(tstop=100)

    _vm = cell.record_soma()
    _time = p.time

    p.finitialize()
    p.run()

    return ezfel(
        T=list(_time),
        V=list(_vm)
    )
