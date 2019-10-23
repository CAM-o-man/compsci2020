from leap_year import is_leap_year
from discounts import discount_checker
from oddchecker import is_odd
from big_or_small import comparer
from addsubmult import add_sub_mult

comparer()
add_sub_mult()
print(is_odd(-11))
print(is_odd(18))
print(is_odd(17))
print(is_odd(100))
print(is_odd(99))
print(is_odd(-100))
print(is_odd(32767))
print(is_odd(-32768))
print(discount_checker(3000))
print(is_leap_year(int(input("Please enter a year: "))))
