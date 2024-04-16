from Lab_2.Zad4.GeneratorStrategy import GeneratorStrategy

class Fibonacci(GeneratorStrategy):
    def __init__(self):
        super().__init__()
        self.__number_of_elements = None

    def set_parameters(self, number_of_elements):
        self.__number_of_elements = number_of_elements
        return self
    def generate_integers(self):
        if self.__number_of_elements is None:
            raise ValueError("Number of elements not set")

        fibonacci_sequence = [0, 1]

        while len(fibonacci_sequence) < self.__number_of_elements:
            next_fibonacci = fibonacci_sequence[-1] + fibonacci_sequence[-2]
            fibonacci_sequence.append(next_fibonacci)

        return sorted(fibonacci_sequence)