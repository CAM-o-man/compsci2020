def counter(x: int) -> int:
	digits: int = 0
	for i in enumerate(str(x), start=0):
		digits = i[0]
	return digits
