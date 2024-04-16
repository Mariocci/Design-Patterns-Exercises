from Lab_2.Zad4.DistributionTester import DistributionTester
from Lab_2.Zad4.generatorsImpl.Fibonacci import Fibonacci
from Lab_2.Zad4.generatorsImpl.IntervalStep import IntervalStep
from Lab_2.Zad4.generatorsImpl.NormalDist import NormalDist
from Lab_2.Zad4.percentileImpl.Interpolated import InterpolatedPercentile
from Lab_2.Zad4.percentileImpl.NearestRank import NearestRank


def main():
    tester_step = DistributionTester()
    tester_fib = DistributionTester()
    tester_normal_dist = DistributionTester()

    tester_step.setGeneratorStrategy(IntervalStep().set_parameters(1, 10, 2))
    tester_fib.setGeneratorStrategy(Fibonacci().set_parameters(5))
    tester_normal_dist.setGeneratorStrategy(NormalDist().set_parameters(0, 3, 5))

    gen_step = tester_step.generate_integers()
    print("Generated step: ")
    print(gen_step)
    gen_fib = tester_fib.generate_integers()
    print("Generated fib: ")
    print(gen_fib)
    gen_normal_dist = tester_normal_dist.generate_integers()
    print("Generated normal dist: ")
    print(gen_normal_dist)

    tester_step.setPercentileStrategy(InterpolatedPercentile().set_data(gen_step))
    percentil_step = tester_step.calculate_percentile(50)
    print("Interpolated 50 percentile for step: ")
    print(percentil_step)
    tester_fib.setPercentileStrategy(InterpolatedPercentile().set_data(gen_fib))
    percentil_fib = tester_fib.calculate_percentile(50)
    print("Interpolated 50 percentile for fib: ")
    print(percentil_fib)
    tester_normal_dist.setPercentileStrategy(InterpolatedPercentile().set_data(gen_normal_dist))
    percentil_normal_dist = tester_normal_dist.calculate_percentile(50)
    print("Interpolated 50 percentile for normal dist: ")
    print(percentil_normal_dist)

    print("Interpolated decils: ")
    print("Step test 10...90:")
    tester_step.test()
    print("Fibonacci test 10...90:")
    tester_fib.test()
    print("Normal dist. test 10...90:")
    tester_normal_dist.test()

    tester_step.setPercentileStrategy(NearestRank().set_data(gen_step))
    percentil_step = tester_step.calculate_percentile(50)
    print("Nearest rank 50 percentile for step: ")
    print(percentil_step)
    tester_fib.setPercentileStrategy(NearestRank().set_data(gen_fib))
    percentil_fib = tester_fib.calculate_percentile(50)
    print("Nearest rank 50 percentile for fib: ")
    print(percentil_fib)
    tester_normal_dist.setPercentileStrategy(NearestRank().set_data(gen_normal_dist))
    percentil_normal_dist = tester_normal_dist.calculate_percentile(50)
    print("Nearest rank 50 percentile for normal dist: ")
    print(percentil_normal_dist)

    print("Nearest rank decils: ")
    print("Step test 10...90:")
    tester_step.test()
    print("Fibonacci test 10...90:")
    tester_fib.test()
    print("Normal dist. test 10...90:")
    tester_normal_dist.test()


if __name__ == "__main__":
    main()
