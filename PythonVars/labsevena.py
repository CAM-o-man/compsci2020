class Variables:
	
	def get_name(self):
		name = input("Please input your name: ")
		return name
	
	def get_age(self):
		age = int(input("Please input your age: "))
		return age
	
	def get_last_birthday(self):
		lastbirthday = int(input("Please input the year of your last birthday: "))
		return lastbirthday
	
	def __main__(self):
		usrname = self.get_name()
		usrage = self.get_age()
		usrbirth = self.get_last_birthday()
		print("{} is {} years old.".format(usrname, usrage))
		print("Their last birthday was in {}".format(usrbirth))
		print("Because of this, we can determine that they were born in {}".format(usrbirth - usrage))
		return
	
	def __init__(self):
		pass


class Math:
	def get_x(self):
		return int(input("Please enter an integer: "))
	
	def get_y(self):
		return int(input("Please enter another integer: "))
	
	def get_z(self):
		return int(input("Please enter a third integer: "))
	
	def product(self, x, y, z):
		if z is None:
			return x * y
		else:
			return x * y * z
	
	def modulo(self, x, y):
		return x % y
	
	def __main__(self):
		usrx = self.get_x()
		usry = self.get_y()
		usrz = self.get_z()
		print("You entered {}, {}, and {}".format(usrx, usry, usrz))
		print("The product of {} and {} is {}".format(usrx, usry, self.product(usrx, usry, None)))
		print("The product of all three is {}".format(self.product(usrx, usry, usrz)))
		print("{} mod {} is {}".format(usrx, usry, self.modulo(usrx, usry)))
		print("{} mod {} is {}".format(usrx, usrz, self.modulo(usrx, usrz)))
		print("{} mod {} is {}".format(usry, usrz, self.modulo(usry, usrz)))

	def __init__(self):
		pass
