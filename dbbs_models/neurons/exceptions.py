class DbbsModelError(Exception):
    pass

class ModelClassError(DbbsModelError):
    pass

class MorphologyBuilderError(DbbsModelError):
    pass

class ConnectionError(DbbsModelError):
    pass

class AmbiguousSynapseError(ConnectionError):
    pass

class SynapseNotPresentError(ConnectionError):
    pass

class SynapseNotDefinedError(ConnectionError):
    pass

class MechanismAttributeError(ModelClassError):
    pass
