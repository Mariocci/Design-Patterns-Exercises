from Lab_2.Zad4.GeneratorStrategy import GeneratorStrategy

class IntervalStep(GeneratorStrategy):
    def __init__(self):
        super().__init__()
        self.__lower_bound = None
        self.__upper_bound = None
        self.__step = None

    def set_parameters(self, lower_bound, upper_bound, step):
        self.__lower_bound = lower_bound
        self.__upper_bound = upper_bound
        self.__step = step
        return self

    def generate_integers(self):
        if any(param is None for param in [self.__lower_bound, self.__upper_bound, self.__step]):
            raise ValueError("Parameters not set")

        result = []
        current = self.__lower_bound
        while current <= self.__upper_bound:
            result.append(current)
            current += self.__step
        return sorted(result)