
def find_pairs(s: str) -> int:
    pairs: int = 0
    mem = s[0]
    for i in s[1:]:
        if i == mem:
            pairs += 1

        mem = i

    return pairs
