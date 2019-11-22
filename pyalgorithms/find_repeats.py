def findrepeats(toparse: list) -> int:
    mem = None
    currhertz: int = 0
    for ele in toparse:
        if (x := toparse.count(ele) > currhertz):
            currhertz = x
            mem = ele
        else:
            pass

    return mem


if __name__ == '__main__':
    print(findrepeats([1, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10]))
