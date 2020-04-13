# Abstract classes cannot have their own objects, they are intended to be inherited
# Implement all the abstract methods in child class, if any abstract method is not implemented, 
# creating an object throws up an error


from abc import ABC, abstractmethod

# An abstract class
class Human(ABC):
	
	def __init__(self):
		print("Abstract class __init__()")

	@abstractmethod
	def love(self):
		pass

	@abstractmethod
	def hate(self):
		pass

class Abhinav(Human):
	
	def __init__(self):
		print("Abhinav's __init__()")

	# These abstract methods need definitions
	def love(self):
		pass
	
	# Without defining these abstract methods, python throws up an error
	def hate(self):
		pass

o1 = Abhinav()
