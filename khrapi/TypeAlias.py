
from .Type import Type

class TypeAlias(Type):
    def __init__(self, identifier):
        super(TypeAlias, self).__init__(identifier)
        self.type = None