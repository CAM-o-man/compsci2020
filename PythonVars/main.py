from labsevena import Variables
from labsevena import Math
from labsevena import Divider
from labsevenb import Shape
from labsevenb import Calc

"""
Author: Connor McDermid
Lab: 7a
Date: 2019.10.15
Extra: Object Oriented (labsevena.py), import statements.
"""


def __main__():
    """Run the program."""
    first = Variables()
    first.__main__()

    second = Math()
    second.__main__()

    third = Divider()
    third.__main__()

	# Second Lab
	usr = input("Please input the shape you'd like to calculate the area of.")
	identifier = {
		"rectangle": Shape.rect,
		"square": Shape.rect,
		"triangle": Shape.tri,
		"trapezoid": Shape.trap,
		"circle": Shape.circle,
		"cone": Shape.cone
	}

	if identifier.get(usr) == Shape.circle:
		r = input("Please input the radius: ")
		print(Calc.calc_area(int(r), None, Shape.circle))
	else:
		l = input("Please input the length: ")
		w = input("Please input the width: ")
		print(Calc.calc_area(int(l), int(w), identifier.get(usr)))

	usr = input("Please input the shape you'd like to calculate the volume of: ")

	if identifier.get(usr) == Shape.circle:
		r = input("Please input the radius: ")
		print(Calc.calc_volume(int(r), None, None, Shape.circle))
	elif identifier.get(usr) == Shape.trap:
		b1 = input("Please input the length of base 1: ")
		b2 = input("Please input the length of base 2: ")
		w = input("Please input the width of the base: ")
		h = input("Please input the height of the shape: ")
		base = (int(b1), int(b2))
		print(Calc.calc_volume(base, int(w), int(h), Shape.trap))