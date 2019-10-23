def oddcounter(x: int) -> int:
	digits: int = 0
	for i in enumerate(str(x), start=0):
		if not int(str(x)[i]) % 2 == 0:
			digits += 1
	return digits


def evencounter(x: int) -> int:
	digits: int = 0
	for i in enumerate(str(x), start=0):
		if int(str(x)[i]) % 2 == 0:
			digits += 1
	return digits
