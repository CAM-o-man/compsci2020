def greater_than_last(l: list) -> list:
    to_return: list = list()
    mem: int = l[-1]
    for x in l:
        if x < mem:
            to_return.append(x)
            continue
        else:
            pass  # not lower
    return to_return


if __name__ == "__main__":
    print(greater_than_last([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
