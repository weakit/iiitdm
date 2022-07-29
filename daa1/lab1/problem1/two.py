

def different_two_pass(z: int, a: [int]):
    for x in a:
        if z - x in a:
            return x, z - x


if __name__ == '__main__':
    input_size = int(input())
    number = int(input())
    input_list = []
    for _ in range(input_size):
        input_list.append(int(input()))

    (lambda x: [print(a) for a in x] if x else print('*'))(different_two_pass(number, input_list))
