from ._helpers import *
from ._artifacts import VoltageTracesOverlay
from patch import p


def run_protocol(
    *cells,
    connections=None,
    recorders=None,
    stimuli=None,
    duration=100,
    sim_name="Network"
):
    disable_cvode()
    init_simulator(tstop=duration)

    _vms = [cell.record_soma() for cell in cells]
    _time = p.time

    if recorders is None:
        recorders = {}

    p.finitialize()
    p.run()

    e = [ezfel(T=list(_time), V=list(vm)) for vm in _vms]

    # Create a build artifact
    rec = {cat: [list(r) for r in recs] for cat, recs in recorders.items()}
    VoltageTracesOverlay(
        cells,
        sim_name,
        _time,
        _vms,
        duration=duration,
        connections=connections,
        recorders=rec,
    )

    return e
