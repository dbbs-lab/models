from patch import p
import efel

def init_simulator(dt=0.025, celsius=32, tstop=1000, v_init=-70):
    for k, v in vars().items():
        setattr(p, k, v)

def disable_cvode():
    time_step = p.CVode()
    time_step.active(0)

class efel_dict(dict):
    def __getattr__(self, k):
        return efel.getFeatureValues([self], [k])[0][k]

def ezfel(T, V, **kwargs):
    kwargs["stim_start"] = [kwargs["stim_start"]] if "stim_start" in kwargs else [T[0]]
    kwargs["stim_end"] = [kwargs["stim_end"]] if "stim_end" in kwargs else [T[-1]]
    kwargs["T"] = T
    kwargs["V"] = V
    return efel_dict(kwargs)
