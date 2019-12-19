from math import pi
from enum import Enum
from typing import Union, Optional


class Shape(Enum):
    """
    Use to define the type of shape you want to calculate a value of.
    """
    rect = 0
    tri = 1
    trap = 2
    circle = 3
    cone = 4


class Calc:

    @staticmethod
    def calc_area(base: Union[int, tuple], height: Optional[int], shape: Shape) -> int:
        """
        :type base: int
        :type height: int
        :type shape: Shape
        :param base: base of the shape
        :param height: height of the shape
        :param shape: Shape specifier
        :return: the area
        """
        def trap_area(base, height):
            return ((base[0] + base[1]) / 2) * height

        def rect_area(base, height):
            return base * height

        def tri_area(base, height):
            return (base / 2) * height

        def circle_area(radius, unimportant):
            """
            Calculate the area of a circle
            :param radius: The radius of the circle
            :param unimportant: The value passed to this is unnecessary, and will be ignored.
            :return: The area of the circle
            """
            return pi * (base ** 2)

        identifier = {
            Shape.rect: rect_area,
            Shape.tri: tri_area,
            Shape.trap: trap_area,
            Shape.circle: circle_area
        }

        func = identifier.get(shape)
        return func(base, height)

    @staticmethod
    def calc_volume(length: Union[int, tuple], width: Optional[int], height: Optional[int], shape: Shape) -> int:
        """
        :type length: int
        :type width: int
        :type height: int
        :type shape: Shape
        :param length:
        :param width:
        :param height:
        :param shape: The Shape specifier for the shape
        :return: The volume of the Shape specified in Argument 4
        """
        def rect_vol(length, width, height):
            """
            Get the volume of a cube
            :type length: int
            :type width: int
            :type height: int
            :param length: length
            :param width: width
            :param height: height
            :return: volume
            """
            return length * width * height

        def tri_vol(length, width, height):
            """
            Get the volume of a triangular prism
            :param length: l
            :param width: w
            :param height: h
            :return: 1/2 * lwh
            """
            return self.calc_area(length, width, Shape.tri) * height  # It exists, might as well use it.

        def trap_vol(base, width, height):
            return self.calc_area(base, width, Shape.trap) * height

        def circle_vol(radius, na, height):
            """
            Get the volume of a sphere
            (yes, I know the function isn't called sphere_vol, but it's purely internal)
            :param radius: The only important value
            :param na: N/A
            :param na2: N/A
            :type radius: int
            :type height: int
            :return: Volume
            """

            return (4 / 3) * pi * (radius ** 3)

        def cone_vol(radius, na, height):
            return pi * ((radius ** 2) * (height / 3))

        identifier = {
            Shape.rect: rect_vol,
            Shape.tri: tri_vol,
            Shape.trap: trap_vol,
            Shape.circle: circle_vol,
            Shape.cone: cone_vol
        }
        func = identifier.get(shape)
        return func(length, width, height)

    @staticmethod
    def calc_slope(p1: tuple, p2: tuple) -> float:
        """
        Calculate the slope of a line when passes 2 points on the line
        :type p1: tuple
        :type p2: tuple
        :param p1: The first point, passed as a tuple
        :param p2: The second point, passed as a tuple
        :return: The slope of the line, in decimal form
        """
        top = p1[1] - p2[1]
        bottom = p1[0] - p2[1]
        return top / bottom

    def __init__(self):
        pass
