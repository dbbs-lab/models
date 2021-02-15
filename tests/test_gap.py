import pickle
import plotly.graph_objs as go
from plotly.subplots import make_subplots
f = open("artifacts.pickle", "rb")
a = pickle.load(f)
fig = make_subplots(rows=len(a[0].kwargs["recorders"]) + 1, cols=1)
for i, (cat, recs) in enumerate(a[0].kwargs["recorders"].items()):
  for r in recs:
    fig.add_trace(go.Scatter(x=a[0].t, y=r), row=2+i, col=1)
[fig.add_trace(go.Scatter(x=a[0].t, y=a[0].vs[i], name=a[0].cell_names[i]), row=1, col=1) for i in range(2)]
fig.show()
