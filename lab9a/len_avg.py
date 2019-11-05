def find_average_len(strs: tuple) -> float:
    lengths: list = list()
    for string in strs:
        lengths.append(string.__len__())

    return sum(lengths) / lengths.__len__()
