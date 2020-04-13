# Instance method : method in which object (recieved in 'self' being recieved as parameter) is passed.


class Binary:

	def __init__(self, name, b_type):
		self.name = name
		self.b_type = b_type

	# An instance method 	
	def binaryType(self):
		if self.b_type == "ET_DYN":
			print(f"{self.name} : A Shared object binary")
		elif self.b_type == "ET_EXEC":
			print(f"{self.name} : An Executable binary")
		elif self.b_type == "ET_REL":
			print(f"{self.name} : A Relocatable binary")
		elif self.b_type == "ET_CORE":
			print(f"{self.name} : A core file/binary")
		else:
			print(f"{self.name} : An unknown binary format")


b1 = Binary("ls", "ET_DYN")

# This is internally called by python as Binary.binaryType(b1), i.e. Class_name.method(object), i.e.
# why we need to use a 'self' parameter that represents the object itself.
b1.binaryType()

