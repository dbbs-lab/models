from .validation_models import *

def quick_test(model, duration=300, temperature=32, v_init=-65):
    from patch import p

    p.time
    p.celsius = temperature
    p.v_init = v_init
    model.record_soma()
    p.finitialize(v_init)
    p.continuerun(duration)
    from plotly import graph_objs as go

    go.Figure(go.Scatter(x=list(p.time), y=list(model.Vm), name=model.__class__.__name__)).show()
