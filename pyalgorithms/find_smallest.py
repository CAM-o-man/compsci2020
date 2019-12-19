def findsmallest(l: list) -> int:
    smallest: int = l[0]
    for x in l:
        if x < smallest:
            smallest = x

    return smallest
