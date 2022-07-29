
# newton's method
# https://en.wikipedia.org/wiki/Newton%27s_method

def newton(x: float):
    x_next = 5
    x_now = 0

    # iteratively improve approximation until desired precision is reached
    while abs(x_now - x_next) > 1e-8:
        x_now = x_next
        x_next = x_now - (3 ** x_now - x) / (1.09861228867 * 3 ** x_now)

    return x_next


if __name__ == '__main__':
    print("{:.4f}".format(newton(float(input()))))
