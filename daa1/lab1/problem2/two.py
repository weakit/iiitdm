
# inverse hyperbolic tangent approximation for log
# https://en.wikipedia.org/wiki/Logarithm#Inverse_hyperbolic_tangent

def ln_atanh(x: float):
    x_next = 0
    x_now = -1
    i = 0

    # iteratively improve approximation until desired precision is reached
    while abs(x_now - x_next) > 1e-8:
        x_now = x_next
        new_term = (1 / (2 * i + 1)) * ((x - 1) / (x + 1)) ** (2 * i + 1)
        x_next = x_now + new_term
        i += 1

    print(i)
    return 2 * x_next


def l3(x: float):
    return ln_atanh(x) / 1.09861228867


if __name__ == '__main__':
    print("{:.4f}".format(l3(float(input()))))

