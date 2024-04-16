from Lab_2.Zad4.GeneratorStrategy import GeneratorStrategy
from Lab_2.Zad4.PercentileStrategy import PercentileStrategy


class DistributionTester:
    def __init__(self):
        self.__generator = None
        self.__percentile = None

    def setGeneratorStrategy(self, generator_strategy: GeneratorStrategy):
        self.__generator = generator_strategy

    def setPercentileStrategy(self, percentile_strategy: PercentileStrategy):
        self.__percentile = percentile_strategy

    def generate_integers(self):
        return self.__generator.generate_integers()

    def calculate_percentile(self, percentile):
        return self.__percentile.calculate_percentile(percentile)

    def test(self):
        if self.__generator is None or self.__percentile is None:
            print("Generator strategy or percentile strategy not set.")
            return

        integers = self.generate_integers()
        self.__percentile.set_data(integers)
        integer_string = ', '.join(map(str, integers))
        print("Integers:", integer_string)

        for i in range(10, 91, 10):
            percentile_value = self.calculate_percentile(i)
            print(f"{i}. percentile:", percentile_value)