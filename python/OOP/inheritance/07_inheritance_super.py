# We can access the properties of base(parent) class by using 'super()' in child class

class Binary:

	def __init__(self, name, platform):
		self.name = name
		self.platform = platform


# Inherit from Binary (Parent class)
class ELF(Binary):

	def __init__(self, name, platform, b_type):
		
		# Calling Parent class's __init__ to blueprint
		super().__init__(name, platform)
		self.b_type = b_type


	def printAttributes(self):
		print(f"Name : /bin/{self.name} \nplatform: {self.platform} \ntype : {self.b_type}")


elf = ELF("ls", "Linux", "ET_DYN")
elf.printAttributes()
