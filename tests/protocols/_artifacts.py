import ndsb, h5py, plotly.graph_objs as go

class VoltageTrace(ndsb.Data):
    def __init__(self, cell, protocol, t, v, **kwargs):
        self.cell_name = cell.__class__.__module__ + "." + cell.__class__.__name__
        self.protocol = protocol
        self.t = list(t)
        self.v = list(v)
        self.kwargs = kwargs
        self.freeze()

    def pack(self, artifact):
        artifact.json({
            "cell_name": self.cell_name,
            "protocol": {
                "name": self.protocol,
                **self.kwargs
            }
        })
        with artifact.open("trace.html") as f:
            kwargs_str = " (" + ";".join(f"{k}={v}" for k, v in self.kwargs.items()) + ")"
            go.Figure(data=go.Scatter(x=self.t, y=self.v), layout=dict(
                xaxis_title="Time (ms)",
                yaxis_title="Voltage (mV)",
                title_text=self.cell_name + " " + self.protocol + kwargs_str
            )).write_html(f, include_plotlyjs='cdn')
        with artifact.open("trace.hdf5") as f:
            h5 = h5py.File(f)
            h5.create_dataset("data", data=[t, v])
