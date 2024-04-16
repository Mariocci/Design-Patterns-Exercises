from Lab_2.Zad4.PercentileStrategy import PercentileStrategy


class InterpolatedPercentile(PercentileStrategy):
    def __init__(self):
        super().__init__()
        self.__sorted_numbers = None
        self.__n = None

    def set_data(self, numbers):
        self.__sorted_numbers = sorted(numbers)
        self.__n = len(self.__sorted_numbers)
        return self

    def calculate_percentile(self, percentile):
        position_lower = (percentile * (self.__n - 1) / 100) + 0.5
        i_lower = int(position_lower)
        i_upper = min(i_lower + 1, self.__n - 1)

        v_lower = self.__sorted_numbers[i_lower]
        v_upper = self.__sorted_numbers[i_upper]
        interpolated_value = v_lower + (percentile - ((i_lower - 1) * 100 / self.__n)) * (v_upper - v_lower) / (100 / self.__n)

        return interpolated_value