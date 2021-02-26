from ._helpers import *
from ._artifacts import VoltageTrace
from patch import p


def run_protocol(cell, *synapses, duration=500, start=200, interval=10, number=10):
    disable_cvode()
    init_simulator(tstop=duration)

    _vm = cell.record_soma()
    _time = p.time

    for syn_spec in synapses:
        t = syn_spec["type"]
        n = syn_spec["number"]
        loc = syn_spec["location"]
        syn = [loc(cell.sections, i) for i in range(n)]
        for s in syn:
            s.stimulate(start=start, interval=interval, number=number)

    p.finitialize()
    p.run()

    I = list(list(i) for i in synaptic_currents)

    # Create a build artifact
    SynapticCurrentTrace(
        cell,
        "SynchronousSynapseActivation",
        _time,
        I=I,
        vm=_vm,
        duration=duration,
        spike_interval=interval,
        spike_number=number,
        spike_start=start,
        synapses=synapses,
    )

    return ezfel(T=list(_time), signal=list(_vm), I=I)
