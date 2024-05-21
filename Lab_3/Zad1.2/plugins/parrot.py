class parrot:

    def __init__(self, name):
        self._greet = "Sto mu gromova!"
        self._menu = "brazilske orahe"
        self._name = name

    def name(self):
        return self._name

    def greet(self):
        return self._greet

    def menu(self):
        return self._menu
