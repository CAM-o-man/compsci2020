from adder import sigma
from digit_counter import counter


def averager(x: int) -> float:
	return sigma(x) / counter(x)
