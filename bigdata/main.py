"""
Name: Connor McDermid
Lab: Python 11
Extra: `enumerate()`
"""


def run():  # Function wrappers are a good thing
    data = open("input.dat")
    total = 0

    for num, line in enumerate(data):
        if num == 0:
            continue  # Don't want pesky metadata cluttering up my good Christian total

        total += int(line)

    print("The sum of the data is: {}".format(total))


if __name__ == "__main__":
    run()
