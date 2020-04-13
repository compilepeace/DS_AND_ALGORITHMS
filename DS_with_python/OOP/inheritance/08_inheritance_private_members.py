# We can access the properties of base(parent) class by using 'super()' in child class.
# If we have unique functions in base and child classes (i.e. no 2 functions with same name), then 
# we can use self.parent_method() from child class to access parent_method() (of base class) but

# If the base class and child class are having some function with same name (for eg: __init__()), then
# we need to use super().func() to access the function of the parent class. If we do self.func() from
# child class then it will access func() defined in its own body (and not the parent body)

class Binary:

	def __init__(self, name, platform):
		self.__name = name						# Name is a private member
		self.platform = platform

	# Getter method to get the value of the private member 'name'
	def getName(self):
		return self.__name
	
	# Setter method to set the value of the private member 'name'
	def setName(self, name):
		self.__name = name
	

# Inherit from Binary (Parent class)
class ELF(Binary):

	def __init__(self, name, platform, b_type):
		
		# Calling Parent class's __init__ to blueprint
		super().__init__(name, platform)
		self.b_type = b_type


	def printAttributes(self):
		print(f"\nName : /bin/{self.getName()} \nplatform: {self.platform} \ntype : {self.b_type}")


elf = ELF("ls", "Linux", "ET_DYN")
elf.printAttributes()
elf.setName("ps")					# Setting the value of private member via a setter method
elf.printAttributes()
