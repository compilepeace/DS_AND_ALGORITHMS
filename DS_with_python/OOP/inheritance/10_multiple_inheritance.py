

class Father:
	
	def __init__(self):
		print("__init__() of Father ")
		self.name = "Gaurav"

class Mother:
	
	def __init__(self):
		print("__init__ of Mother ")
		self.name = "Maity"


# Order of 'Mother' and 'Father' decides whose members are accessed if they have same member names
# Whichever class-name comes first has its attributes accessed
class Child(Mother, Father):

	# It is called as soon as the object of 'Child' class is created
	def __init__(self):
		super().__init__()
	
	def printName(self):
		print(self.name)

obj1 = Child()
obj1.printName()
