def if_letter_repeat(s: str) -> bool:
    firstletter = s[0]
    for x in s:
        if x == firstletter:
            return False

    return True
