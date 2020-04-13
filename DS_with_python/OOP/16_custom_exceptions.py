
# This class inherits from inbuilt Exception class
class ZeroDenominatorException(Exception):
	
	def __init__(self, s):
		print(f"\t{s}")


i = 0
while i < 10:
	i = i + 1
	try:
		n = int(input("Enter the numerator : "))
		d = int(input("Enter the denominator : "))
	
		# To manually raise the exception before the exception is automatically raised (when we 
		# perform division by 0)
		if d == 0:
			raise ZeroDenominatorException("Denominator is 0")	
	
		print(f"Result : {n/d}")
	
	except (ValueError, ZeroDivisionError):
		print(f"Enter an integer value as input where the denominator should be greater than 0!")

	except ZeroDenominatorException:
		print("\tZeroDenominatorException is rasied")

	except:
		print("Some exception occured")

print("Program continued...")




