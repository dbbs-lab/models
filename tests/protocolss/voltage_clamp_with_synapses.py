from ._helpers import *
from ._artifacts import VoltageClampTrace
from patch import p
import dill


def run_protocol(cell, voltage=-70, holding=-70, synapses=None):
    disable_cvode()
    init_simulator(tstop=400)

    clamp = p.SEClamp(cell.soma[0].__neuron__()(0.5))

    clamp.dur1 = 200
    clamp.dur2 = 100
    clamp.dur3 = 100
    try:
        voltage = iter(voltage)
    except TypeError:
        clamp.amp1 = holding
        clamp.amp2 = voltage
        clamp.amp3 = holding
    else:
        voltage = list(voltage)
        clamp.amp1 = voltage[0]
        clamp.amp2 = voltage[1]
        clamp.amp3 = voltage[2]

    if synapses is None:
        synapses = []
    else:
        synapses = dill.loads(synapses)

    synaptic_currents = {}
    for syn_spec in synapses:
        t = syn_spec.get("type", None)
        n = syn_spec.get("number", 1)
        loc = syn_spec["location"]
        syn = [cell.create_synapse(loc(cell, i), t) for i in range(n)]
        for stim in syn_spec["stimulation"]:
            for s in syn:
                s.stimulate(
                    start=stim["start"],
                    interval=stim["interval"],
                    number=stim["number"],
                    noise=stim["noise"],
                )
        synaptic_currents[t] = [s.record() for s in syn]

    _vm = cell.record_soma()
    _time = p.time
    curr = p.record(clamp._ref_i)

    p.finitialize()
    p.run()

    # Create a build artifact
    VoltageClampTrace(
        cell, "Voltage clamp", _time, _vm, curr, voltage=voltage, holding=holding
    )

    results = Results()
    curr_res = ezfel(
        T=list(_time),
        signal=list(curr),
        stim_start=200,
        stim_end=300,
    )
    vm_res = ezfel(
        T=list(_time),
        signal=list(_vm),
        stim_start=200,
        stim_end=300,
    )
    results.set(curr_res, name="current")
    results.set(vm_res, name="voltage")
    for k, v in synaptic_currents.items():
        results.set(list(list(i) for i in v), name=f"{k}.currents")

    return results
