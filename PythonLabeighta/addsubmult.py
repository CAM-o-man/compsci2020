

def add_sub_mult():
	a: int = int(input("Please enter a number: "))
	b: int = int(input("Please enter a second number: "))

	if a > b:
		return a - b
	elif a < b:
		return a + b
	else:
		return a * b
