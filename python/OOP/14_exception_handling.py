
i = 0
while i < 3:
	i = i + 1
	try:
		n = int(input("Enter the numerator : "))
		d = int(input("Enter the denominator : "))
		print(f"Result : {n/d}")
	
	except ValueError:
		print(f"Please enter an integer value !")
	
	except ZeroDivisionError:
		print(f"Denominator should not be zero !")
	
	# Default case : If any error not specified occured
	except:
		print("Some error occured")


try:
	print(z)
except NameError:
	print("NameError occured")

print("Program continued...")




