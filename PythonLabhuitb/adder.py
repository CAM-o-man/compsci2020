from typing import Any, Tuple


def sigma(x: int) -> int:
	result = 0
	for i in enumerate(str(x), start=0):
		result += int(str(x)[i[0]])
	return result
