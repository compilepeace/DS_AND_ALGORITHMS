
i = 0
while i < 10:
	i = i + 1
	try:
		n = int(input("Enter the numerator : "))
		d = int(input("Enter the denominator : "))
		print(f"Result : {n/d}")
	
	except (ValueError, ZeroDivisionError):
		print(f"Enter an integer value as input where the denominator should be greater than 0!")

	except:
		print("Some error occured")

print("Program continued...")




