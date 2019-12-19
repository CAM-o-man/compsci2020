"""
Name: Connor McDermid
Lab: Python 11
Extra: CSV Files
"""

import csv

csvfile = open("data.csv", newline='')

reader = csv.reader(csvfile, delimiter=',', quotechar='"')

index = 0
for row in reader:
    print(row)
    index += 1
    if index >= 10:
        break
