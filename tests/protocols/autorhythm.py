from ._helpers import *
from ._artifacts import VoltageTrace
from patch import p


def run_protocol(cell, duration=100):
    disable_cvode()
    init_simulator(tstop=duration)

    _vm = cell.record_soma()
    _time = p.time

    p.finitialize()
    p.run()

    e = ezfel(T=list(_time), signal=list(_vm))

    # Create a build artifact
    VoltageTrace(
        cell,
        "Autorhythm",
        _time,
        _vm,
        duration=duration,
        frequency=list(e.inv_second_ISI),
    )

    return e
