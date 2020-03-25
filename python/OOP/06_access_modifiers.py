# See about Name Mangling if you want to access a private member outside of the class

# Private members can only be accessed by the member functions of the class and raise an error when
# accessed by any function outside the class in which it is defined.

# By default all the class attributes are public
# To make a member private preceed its name by a '__'

class Binary:

	# Defining a private member
	__private_member = 10
	
	def __init__(self, name, b_type):
		self.__name = name			# This is a private member now
		self.b_type = b_type

	# Private members can only be accesed by a member function of Binary class.
	def modifyName(self):
		print(f"Originally, name was : {self.__name}")
		self.__name = "/bin/" + self.__name
		print(f"Now, name is changed to : {self.__name}")


b1 = Binary("ps", "ET_DYN")

# print(f"{b1.__name}")   -> This statement raises an error as private member cannot be accessed 
# anywhere outside the class
b1.modifyName()

# Name Mangling is used to access private members of the class
print("Accessing private members via Name Mangling now")
print(b1._Binary__name)

