from typing import Union


class Numbers:
	@staticmethod
	def sigma(self, x: tuple) -> int:
		sum: int = 0
		for i in x:
			sum += i
		return sum
	
	@staticmethod
	def digit_counter(x: int) -> int:
		digits: int = 0
		for i in enumerate(str(x), start=0):
			digits += 1
		return digits
	
	def to_tuple(self, x: Union[int, float]) -> tuple:
		y = list()
		for i in enumerate(str(x), start=0):
			y.append(int(str(x)[i]))
		t = tuple(y)
		return t
	
	def to_list(self, x: Union[int, float]) -> list:
		y = list()
		for i in enumerate(str(x), start=0):
			y.append(int(str(x)[i]))
		return y
	
	def to_set(self, x: Union[tuple, list]) -> set:
		return set(x)
