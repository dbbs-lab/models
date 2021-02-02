from ._helpers import *
from ._artifacts import VoltageTrace
from patch import p

def run_protocol(cell, amplitude=0.01):
    disable_cvode()
    init_simulator(tstop=200)

    stim = p.IClamp(0.5, sec=cell.soma[0].__neuron__())

    stim.delay = 0
    stim.dur = 200
    stim.amp = amplitude  # 10pA, or 16 or 22pA

    _vm = cell.record_soma()
    _time = p.time

    p.finitialize()
    p.run()

    # Create a build artifact
    VoltageTrace(cell, "Current injection", _time, _vm, amplitude=amplitude)

    return ezfel(
        T=list(_time),
        V=list(_vm),
        stim_start=stim.delay,
        stim_end=stim.delay + stim.dur
    )
