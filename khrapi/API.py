
# from .Version import Version;
# from .Extension import Extension;

class API(object):
    def __init__(self, identifier):
        self.identifier = identifier
        self.versions = []
        self.extensions = []
        self.types = []
        self.functions = []
        self.constants = []
        self.dependencies = []

    def constantByIdentifier(self, identifier):
        return next((c for c in self.constants if c.identifier == identifier), None)

    def functionByIdentifier(self, identifier):
        return next((f for f in self.functions if c.identifier == identifier), None)