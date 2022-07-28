import time
import math
from random import randint
import factor


def generate_random_set(x: int, max_size: int):
    return_set = []
    for _ in range(x):
        return_set.append(randint(2, int(max_size)))
    return return_set


def alg1(x: int):
    return not x & 1


def alg2(x: int):
    return not x % 2


def alg3(x: int):
    while x >= 2:
        x -= 2
    return not x


def alg4(x: int):
    y = (-1) ** x
    return y == 1


def alg5(x: int):
    return x % 10 in (0, 2, 4, 6, 8)


def alg6(x: int):
    return math.sin(x * math.pi / 2) == 0


def alg7(x: int):
    return math.gcd(x, 2) == 2


def alg8(x: int):
    return ((2 * x) // math.gcd(2, x) if x else 0) == x


def alg9(x: int):
    return (x | 1) == x + 1


def alg11(x: int):
    return 2 in factor.fac(x)


def alg12(x: int):
    num = 7
    while x:
        num = (num * 7) % 10
        x -= 1

    return num in (1, 9)


algorithms = [
    (alg1, 'Bitwise AND'),
    (alg2, 'Modulus'),
    # (alg3, 'Repeated Subtraction'),
    # (alg4, 'Power of -1'),
    # (alg5, 'Last digit check'),
    # (alg6, 'Sin check'),
    # (alg7, 'GCD'),
    # (alg8, 'LCM'),
    (alg9, 'Bitwise OR'),
    # (alg11, 'Prime factorization'),
    # (alg12, 'Power of 7')
]


def test(test_cases, test_case_max_size):
    test_set = generate_random_set(test_cases, test_case_max_size)

    total_start_time = time.time_ns()

    print(f'Testing with {test_cases} test cases.')
    print(f'Maximum integer size {test_case_max_size}\n')

    for algorithm, algorithm_name in algorithms:
        print(f'{algorithm_name}: ', end='')
        start_time = time.time_ns()
        for test_case in test_set:
            algorithm(test_case)
        end_time = time.time_ns()
        print(format((end_time - start_time) / test_cases) + 'ns')

    print(f'\nFinished in {(time.time_ns() - total_start_time) / 1e9}s\n')


if __name__ == '__main__':
    tests = [
        (10000000, 1e10),
    ]

    for t in tests:
        test(*t)
