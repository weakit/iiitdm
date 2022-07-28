from math import floor, sqrt


def step(x):
    return 1 + (x << 2) - ((x >> 1) << 1)


def fac(n):
    max_q = int(floor(sqrt(n)))
    d = 1
    q = 2 if n % 2 == 0 else 3
    while q <= max_q and n % q != 0:
        q = step(d)
        d += 1
    return [q] + fac(n // q) if q <= max_q else [n]
