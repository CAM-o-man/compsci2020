from check_last_repeat import final_repeat
from find_repeats import findrepeats
from find_smallest import findsmallest
from greater_summer import greater_sigma
from last_but_not_least import greater_than_last
from list_repeat import ifrepeat
from list_summer import sigma
from lists_down import ifdown


def run():
    print(final_repeat([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10]))
    print(findrepeats([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    print(findsmallest([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    print(greater_sigma([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    print(greater_than_last([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    print(ifrepeat([0, 1, 2, 3, 4, 5, 5, 5, 5, 6, 7, 8, 9, 10]))
    print(sigma([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))
    print(ifdown([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]))


if __name__ == '__main__':
    run()
