# (c) A+ Computer Science
# www.apluscompsci.com


def is_leap_year(yr: int) -> bool:
	# check to see if it is a leap year19
	# for this problem, a leap year is not divisible by 4 or 400
	# Note from Connor: A leap year is in fact always divisible by 4, but never divisible by 400
	if yr % 4 == 0:
		if yr % 100 == 0:
			return False
		elif yr % 400 == 0:
			return True
		else:
			return True


while True:
	# Get a year
	year = int(input("Enter a year :: "))
	print(is_leap_year(year))
