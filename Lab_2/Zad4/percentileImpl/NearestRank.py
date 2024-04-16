import math

from Lab_2.Zad4.PercentileStrategy import PercentileStrategy


class NearestRank(PercentileStrategy):
    def __init__(self):
        super().__init__()
        self.__sorted_numbers = None

    def set_data(self, numbers):
        self.__sorted_numbers = sorted(numbers)
        return self

    def calculate_percentile(self, percentile):
        position = math.ceil(percentile * len(self.__sorted_numbers) / 100)
        return self.__sorted_numbers[position - 1]

