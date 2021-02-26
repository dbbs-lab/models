from .validation_models import *


def quick_test(*models, duration=300, temperature=32, v_init=-65):
    from patch import p

    p.time
    p.celsius = temperature
    p.v_init = v_init
    for model in models:
        model.record_soma()
    p.finitialize(v_init)
    p.continuerun(duration)

    return list(p.time), [
        {"Vm": list(model.Vm), "model": model.__class__.__name__} for model in models
    ]


def quick_plot(*args, **kwargs):
    time, model_results = quick_test(*args, **kwargs)
    from plotly import graph_objs as go

    go.Figure(
        list(
            go.Scatter(x=time, y=res["Vm"], name=res["model"]) for res in model_results
        )
    ).show()


def orphan_section_scan(model):
    pass
