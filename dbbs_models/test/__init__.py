def quick_test(*models, duration=300, temperature=32, v_init=-65):
    from patch import p

    p.time
    p.celsius = temperature
    p.v_init = v_init
    recorders = [model.record() for model in models]
    p.finitialize(v_init)
    p.continuerun(duration)

    return list(p.time), [
        {"Vm": list(vm), "model": model.__class__.__name__}
        for model, vm in zip(models, recorders)
    ]


def quick_plot(*args, **kwargs):
    time, model_results = quick_test(*args, **kwargs)
    from plotly import graph_objs as go

    go.Figure(
        list(
            go.Scatter(x=time, y=res["Vm"], name=res["model"]) for res in model_results
        )
    ).show()
