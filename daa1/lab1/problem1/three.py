
def cross_product(z: int, a: [int]):
    a2 = [(x, y) for x in a for y in a if x != y]
    a3 = [(x, y, x + y) for x, y in a2]

    results = list(filter(lambda x: x[2] == z, a3))
    return results


if __name__ == '__main__':
    input_size = int(input())
    number = int(input())
    input_list = []
    for _ in range(input_size):
        input_list.append(int(input()))

    (lambda x: [print(a) for a in x[0][:2]] if x else print('*'))(cross_product(number, input_list))


