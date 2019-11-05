def ssid_checker(ssid: str) -> str:
    if ssid[3] != "-":
        return "bad"

    if ssid[6] != "-":
        return "bad"

    if ssid.__len__() != 11:
        return "bad"

    return ssid[-4:]