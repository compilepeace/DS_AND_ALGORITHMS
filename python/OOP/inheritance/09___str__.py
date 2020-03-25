

# This is same as class Binary:
class Binary(object):

	# Constructor to initialize the object attributes
	def __init__(self, name, b_type):
		self.name = name
		self.b_type = b_type


	def __str__(self):
		return "Here goes the description of the class"


b1 = Binary("ps", "ET_EXEC")
print(b1)

