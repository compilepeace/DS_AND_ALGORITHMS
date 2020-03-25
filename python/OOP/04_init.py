# __init__() : Acts as a constructor to the object. Whatever attributes we want the object to have
#              (as we create one) are passed to this function. 
#              Whenever an object is created, __init__ is called.

class Binary:

	def __init__(self, name, b_type):
		self.name = name
		self.b_type = b_type
		self.greeting = "Greetings, we're gonna build low level tools with this knowledge"

	def printAttributes(self):
		print(f"{self.__dict__}")
		#print(f"name : {self.name}, type : {self.b_type}")


b1 = Binary("/bin/mkdir", "ET_DYN")
b1.printAttributes()
