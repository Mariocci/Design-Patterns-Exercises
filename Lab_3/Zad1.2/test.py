import importlib.util
import os

def test():
    pets = []
    for mymodule in os.listdir('plugins'):
        moduleName, moduleExt = os.path.splitext(mymodule)
        if moduleExt == '.py':
            pet = myfactory(moduleName)('Ljubimac ' + str(len(pets)))
            pets.append(pet)
    for pet in pets:
        printGreeting(pet)
        printMenu(pet)

def myfactory(moduleName):
    module_spec = importlib.util.find_spec('plugins.' + moduleName)
    module = importlib.util.module_from_spec(module_spec)
    module_spec.loader.exec_module(module)
    return getattr(module, moduleName)
def printGreeting(pet):
    print(pet.name(), 'pozdravlja:', pet.greet())

def printMenu(pet):
    print(pet.name(), 'voli', pet.menu())

if __name__ == '__main__':
    test()
