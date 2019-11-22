def greater_sigma(l: list) -> int:
    s: int = 0
    counter: int = 0
    mem: int = l[0]
    if len(l) <= 0:
        return -1
    for i, x in enumerate(l):
        if x >= mem:
            s += x
            counter += 1
        elif counter == 0 and i == len(l) - 1:
            return -1
        else:
            pass

    return s