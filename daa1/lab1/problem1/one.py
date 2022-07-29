

def two_pass(z: int, a: [int]):
    outer_index = 0
    length = len(a)

    while outer_index < length:
        inner_index = outer_index + 1
        x = a[outer_index]
        while inner_index < length:
            if x + a[inner_index] == z:
                return x, a[inner_index]
            inner_index += 1
        outer_index += 1


if __name__ == '__main__':
    input_size = int(input())
    number = int(input())
    input_list = []
    for _ in range(input_size):
        input_list.append(int(input()))

    (lambda x: [print(a) for a in x] if x else print('*'))(two_pass(number, input_list))
