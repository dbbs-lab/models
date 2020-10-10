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
        kwargs_str = " (" + ";".join(f"{k}={v}" for k, v in self.kwargs.items()) + ")"
        fig = go.Figure(data=go.Scatter(x=self.t, y=self.v), layout=dict(
            xaxis_title="Time (ms)",
            yaxis_title="Voltage (mV)",
            title_text=self.cell_name + " " + self.protocol + kwargs_str
        ))
        with artifact.open("trace.html") as f:
            fig.write_html(f, include_plotlyjs='cdn')
        with artifact.open("trace.png", "wb") as f:
            f.write(fig.to_image(format="png", width=1280, height=720))
        # with artifact.open("trace.hdf5", "w") as f:
        #     h5 = h5py.File(f, "w")
        #     h5.create_dataset("data", data=[self.t, self.v])
