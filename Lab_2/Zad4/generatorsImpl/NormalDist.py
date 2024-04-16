from Lab_2.Zad4.GeneratorStrategy import GeneratorStrategy
import random



class NormalDist(GeneratorStrategy):
    def __init__(self):
        super().__init__()
        self.__mean = None
        self.__variance = None
        self.__number_of_elements = None

    def set_parameters(self, mean, variance, number_of_elements):
        self.__mean = mean
        self.__variance = variance
        self.__number_of_elements = number_of_elements
        return self

    def generate_integers(self):
        integers = [round(random.normalvariate(self.__mean, self.__variance)) for _ in
                    range(self.__number_of_elements)]
        return sorted(integers)
