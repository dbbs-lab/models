import ndsb, h5py, plotly.graph_objs as go, os
from ._helpers import get_cell_name


class VoltageTrace(ndsb.Data):
    def __init__(self, cell, protocol, t, v, **kwargs):
        self.cell_name = cell.__class__.__module__ + "." + cell.__class__.__name__
        self.protocol = protocol
        self.t = list(t)
        self.v = list(v)
        self.kwargs = kwargs
        self.freeze()

    def pack(self, artifact):
        artifact.json(
            {
                "cell_name": self.cell_name,
                "protocol": {"name": self.protocol, **self.kwargs},
            }
        )
        kwargs_str = " (" + ";".join(f"{k}={v}" for k, v in self.kwargs.items()) + ")"
        fig = go.Figure(
            data=go.Scatter(x=self.t, y=self.v),
            layout=dict(
                xaxis_title="Time (ms)",
                yaxis_title="Voltage (mV)",
                title_text=self.cell_name + " " + self.protocol + kwargs_str,
            ),
        )
        with artifact.open("trace.html") as f:
            fig.write_html(f, include_plotlyjs="cdn")
        with artifact.open("trace.png", "wb") as f:
            f.write(fig.to_image(format="png", width=1280, height=720))
        with artifact.open("trace.hdf5", "wb+") as f:
            h5 = h5py.File(f, "w")
            h5.create_dataset("data", data=[self.t, self.v])
            h5.close()

    def view(self):
        if not hasattr(self, "artifact") or not hasattr(self.artifact, "remote_path"):
            content = "**`data.artifact.remote_path` not set; Set it before calling `data.view()`. It is required to fetch remote images!**"
        else:
            trace_path = os.path.join(self.artifact.remote_path, "trace.png")
            content = f"![VoltageTrace]({trace_path})"
        return self.to_markdown(content)


class VoltageClampTrace(ndsb.Data):
    def __init__(self, cell, protocol, t, v, i, **kwargs):
        self.cell_name = cell.__class__.__module__ + "." + cell.__class__.__name__
        self.protocol = protocol
        self.t = list(t)
        self.v = list(v)
        self.i = list(i)
        self.kwargs = kwargs
        self.freeze()

    def pack(self, artifact):
        artifact.json(
            {
                "cell_name": self.cell_name,
                "protocol": {"name": self.protocol, **self.kwargs},
            }
        )
        kwargs_str = " (" + ";".join(f"{k}={v}" for k, v in self.kwargs.items()) + ")"
        fig = go.Figure(
            data=go.Scatter(x=self.t, y=self.v),
            layout=dict(
                xaxis_title="Time (ms)",
                yaxis_title="Voltage (mV)",
                title_text=self.cell_name + " " + self.protocol + kwargs_str,
            ),
        )
        with artifact.open("trace.html") as f:
            fig.write_html(f, include_plotlyjs="cdn")
        with artifact.open("trace.png", "wb") as f:
            f.write(fig.to_image(format="png", width=1280, height=720))
        with artifact.open("trace.hdf5", "wb+") as f:
            h5 = h5py.File(f, "w")
            h5.create_dataset("voltage", data=[self.t, self.v])
            h5.create_dataset("current", data=[self.t, self.i])
            h5.close()

    def view(self):
        if not hasattr(self, "artifact") or not hasattr(self.artifact, "remote_path"):
            content = "**`data.artifact.remote_path` not set; Set it before calling `data.view()`. It is required to fetch remote images!**"
        else:
            trace_path = os.path.join(self.artifact.remote_path, "trace.png")
            content = f"![VoltageTrace]({trace_path})"
        return self.to_markdown(content)


class VoltageTracesOverlay(ndsb.Data):
    def __init__(self, cells, protocol, t, vs, **kwargs):
        cell_names = set()
        for cell in cells:
            cell_names.add(get_cell_name(cell))
        self.cell_names = list(cell_names)
        self.protocol = protocol
        self.t = list(t)
        self.vs = list(list(v) for v in vs)
        self.kwargs = kwargs
        self.freeze()

    def pack(self, artifact):
        artifact.json(
            {
                "cell_names": self.cell_names,
                "protocol": {"name": self.protocol, **self.kwargs},
            }
        )
        kwargs_str = " (" + ";".join(f"{k}={v}" for k, v in self.kwargs.items()) + ")"
        fig = go.Figure(
            layout=dict(
                xaxis_title="Time (ms)",
                yaxis_title="Voltage (mV)",
                title_text=self.protocol + kwargs_str,
            )
        )
        for cell, v in zip(cells, vs):
            fig.add_scatter(name=get_cell_name(cell), x=self.t, y=v)
        with artifact.open("trace.html") as f:
            fig.write_html(f, include_plotlyjs="cdn")
        with artifact.open("trace.png", "wb") as f:
            f.write(fig.to_image(format="png", width=1280, height=720))
        with artifact.open("trace.hdf5", "wb+") as f:
            h5 = h5py.File(f, "w")
            for cell, v in zip(cells, vs):
                h5.create_dataset(get_cell_name(cell, unique=True), data=[self.t, v])
            # Close the hdf5 file before the underlying file handle is closed or
            # errors and segfaults occur
            h5.close()

    def view(self):
        if not hasattr(self, "artifact") or not hasattr(self.artifact, "remote_path"):
            content = "**`data.artifact.remote_path` not set; Set it before calling `data.view()`. It is required to fetch remote images!**"
        else:
            trace_path = os.path.join(self.artifact.remote_path, "trace.png")
            content = f"![VoltageTrace]({trace_path})"
        return self.to_markdown(content)
