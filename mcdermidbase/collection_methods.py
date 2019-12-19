from typing import Union, Optional
import random


class Collections:
	
	@staticmethod
	def sort_list(x: list) -> list:
		y = x.sort()
		return y
	
	@staticmethod
	def sort_set(x: set) -> list:
		y = sorted(x)
		return y
	
	@staticmethod
	def sort_dict(x: dict, sort_by: bool) -> dict:
		"""
		
		:param x: The dictionary to sort
		:param sort_by: Set to True to sort by key. Set to False to sort by value.
		:return: The sorted dictionary.
		"""
		sorted_dict: dict = {}
		if sort_by is True:
			for i in sorted(x):
				sorted_dict[sorted(x)[i][0]] = sorted(x)[i][1]
		else:
			for i in sorted(x.items(), key=
							lambda kv: (kv[1], kv[0])):
				sorted_dict[sorted(x)[i][1]] = sorted(x)[i][0]
		
		return sorted_dict
	
	@staticmethod
	def shuffle(x: Union[list, tuple], rand: Optional=random) -> Union[list, tuple]:
		if rand is not None:
			shuffled = random.shuffle(x, rand)
		else:
			shuffled = random.shuffle(x)
		return shuffled
