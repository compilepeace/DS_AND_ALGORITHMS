# Static methods are class methods (unlike object methods)
# @staticmethod : A decorator that will stop the binding of the object, when the function with this
#                 decorator is passed, it will ignore the passing of object (as 'self') 


class Binary:

	# Whatever class attributes we want to assign are passed into the __init__ function 
	def __init__(self, name, b_type):
		self.name = name
		self.b_type = b_type

	@staticmethod
	def greetingFromHell():
		print(f"Hell greets you with grace")


b1 = Binary("/bin/ps", "ET_DYN")
b1.greetingFromHell()						# Internally used as Binary.greetingFromHell(b1)

