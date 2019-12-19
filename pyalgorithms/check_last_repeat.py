def final_repeat(l: list) -> bool:
    mem: int = l[-1]
    for x in l:
        if x is not mem:
            pass
        else:
            return True
    return False
