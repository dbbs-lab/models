import glia as g

class Synapse:

    def __init__(self, cell, section, point_process_name, attributes = {}, variant=None):
        self._cell = cell
        self._section = section
        self._point_process_name = point_process_name
        self._point_process_glia_name = g.resolve(point_process_name, pkg="dbbs_mod_collection", variant=variant)
        self._point_process = g.insert(section, point_process_name, pkg="dbbs_mod_collection", variant=variant)
        for key, value in attributes.items():
            setattr(self._point_process, key, value)

    def __neuron__(self):
        return self._point_process.__neuron__()
