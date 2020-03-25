
class ZeroDenominatorException(ZeroDivisionError):
	
	def __init__(self, s):
		print(s)
	

i = 0
while i < 10:
	i = i + 1
	try:
		n = int(input("Enter the numerator : "))
		d = int(input("Enter the denominator : "))
	
		# To manually raise the exception before the exception is automatically raised (when we 
		# perform division by 0)
		if d == 0:
			raise ZeroDenominatorException("\tDivide by zero")	
	
	except (ValueError, ZeroDivisionError):
		print(f"\tEnter an integer value as input where the denominator should be greater than 0!")

	except ZeroDenominatorException:
		print("\tZeroDenominatorException is rasied")

	except:
		print("\tSome exception occured")

	# If no exception is raised, flow of control transfers to else
	else:
		print(f"Result : {n/d}")

	# Even if exception is raised, the code in 'finally' block will be executed before aborting
	finally:
		print("This executes no matter what exception is raised")

print("Program continued...")




