def ifrepeat(l: list) -> bool:
    tester: set = set(l)
    return True if len(tester) is len(l) else False  # I do love idiomatic languages like this


if __name__ == '__main__':
    print(ifrepeat([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
