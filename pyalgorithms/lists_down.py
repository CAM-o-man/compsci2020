def ifdown(l: list) -> bool:
    mem: int = l[0]
    for x in l:
        if x < mem and x != l[0]:  # trap needed to prevent failure immediately
            pass
        elif x == l[0]:
            pass
        elif x >= mem:
            return False

        mem = x
    return True


if __name__ == '__main__':
    print(ifdown([9, 8, 7, 6, 5, 4, 3, 2, 1, 0]))
