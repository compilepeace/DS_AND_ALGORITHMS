# Method of Resolution Order (MRO) is the order in which the classes are accessed.
# class_name.mro() : prints the list of order

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
print("Method of resolution order is given bellow : ")
print(Child.mro())
