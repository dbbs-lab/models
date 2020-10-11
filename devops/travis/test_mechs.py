from neuron import h

_dir = {}
builtin_mechs = []
for k in dir(h):
    try:
        m = str(getattr(h, k))
        _dir[k] = m
        if "neuron.DensityMechanism" in m:
            builtin_mechs.append(k)
    except TypeError as e:
        if "mechanism" in str(e):
            builtin_mechs.append(k)
        _dir[k] = str(e)
    except Exception as e:
        _dir[k] = str(e)
