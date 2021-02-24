from patch import p
import efel


boundary = "000(|||)000"


def get_cell_name(cell, unique=False):
    if hasattr(cell, "name"):
        return cell.name
    elif unique:
        return str(cell)
    else:
        return cell.__class__.__module__ + "." + cell.__class__.__name__


def init_simulator(dt=0.025, celsius=32, tstop=1000, v_init=-70):
    for k, v in vars().items():
        setattr(p, k, v)


def disable_cvode():
    time_step = p.CVode()
    time_step.active(0)


_skip_keys = ["__getstate__", "__setstate__"]


class efel_dict(dict):
    def __getattr__(self, k):
        if k in _skip_keys:
            super().__getattribute__(k)
        return efel.getFeatureValues([self], [k])[0][k]


def ezfel(T, signal, **kwargs):
    kwargs["stim_start"] = [kwargs["stim_start"]] if "stim_start" in kwargs else [T[0]]
    kwargs["stim_end"] = [kwargs["stim_end"]] if "stim_end" in kwargs else [T[-1]]
    kwargs["T"] = T
    kwargs["V"] = signal
    kwargs["signal"] = signal
    d = efel_dict(kwargs)
    d.t = T
    d.x = signal
    return d


class Results:
    def __init__(self, primary=None):
        self._results = {}
        if primary is not None:
            self.set(primary)

    def set(self, result, name="primary"):
        self._results[name] = result

    def get(self, name="primary"):
        return self._results.get(name, None)

    def set_cell_result(self, cell, result, name="primary"):
        self.set(result, name=get_cell_name(cell, unique=True) + "." + name)
