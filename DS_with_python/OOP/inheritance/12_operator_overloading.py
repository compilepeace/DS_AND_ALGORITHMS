import math
class Point:
	
	def __init__(self, p1, p2):
		self.__p1 = p1
		self.__p2 = p2

	def __str__(self):
		return "A message from point (" + str(self.__p1) + "," + str(self.__p2) + ")"

	# Overloading '+' operator, __add__() is fixed
	def __add__(self, point_object):
		return Point(self.__p1 + point_object.__p1, self.__p2 + point_object.__p2)

	# Overloading '<' operator
	def __lt__(self, point_object):
		return math.sqrt(self.__p1**2 + self.__p2**2) < math.sqrt(point_object.__p1**2 + point_object.__p2**2)


s1 = Point(2,5)
s2 = Point(6, 1)

p3 = s1 + s2
print(f"{p3}")
