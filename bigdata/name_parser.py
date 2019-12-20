"""
Name: Connor McDermid
Lab: Python 11
Extra: CSV Files
"""
from typing import Union


def run(request: int) -> Union[tuple, str]:
    import csv

    csvfile = open("data.csv", newline='')

    reader = csv.reader(csvfile, delimiter=',', quotechar='"')

    index = 0

    if request == 0:
        for idx, row in enumerate(reader):
            if idx == 1:
                return row[1]
    elif request == 1:
        usr: int = int(input("Male[1] or Female[2]? "))
        if usr == 1:
            for row in reader:
                if row[3] != "boy":
                    continue
                return row[1]
        elif usr == 2:
            for row in reader:
                if row[3] != "girl":
                    continue
                return row[1]

    elif request == 2:
        next(reader)
        for row in reader:
            if float(row[2]) == 0.000127:
                return row[1]

    elif request == 3:
        usr: str = input("Which name would you like to grep for? ")
        for row in reader:
            if row[1] != usr:
                continue
            csvfile.seek(0)  # Resets the CSV read value to 0
            return "{}\n{}".format(next(reader), row)

    elif request == 4:
        exit(0)

    else:
        return "Request code {} was not a valid request.".format(request)
