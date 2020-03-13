
user_input = input("Enter the elements of the list (space separated) : ")


# Getting the elements given by user in a list and sorting the list
input_list = [int(i) for i in user_input.strip().split(' ')]
input_list.sort()


# Now the list is ready to be searched for
n = int(input("Enter the number to be searched for : "))


# Takes number to be searched (x), start index (si) and end index (ei)
def BinarySearch(x, si, ei):
	if si > ei:
		print("[DEBUG] si > ei : Returning -1")
		return -1

	# Setting up mid
	mid = (si + ei)//2
	print(f"mid({mid}) : {input_list[mid]}")
	
	# If element to be found is at mid
	if x == input_list[mid]:
		print("[DEGUB] element at input_list[mid]")
		return mid
	
	if x > input_list[mid]:
		print("x > input_list[mid], calling BinarySearch() again")
		return BinarySearch(x, mid + 1, ei)
		
	elif x < input_list[mid]:
		print("x < input_list[mid], calling BinarySearch() again")
		return BinarySearch(x, si, mid - 1)


print(f"New Sorted list - {input_list}")
index = BinarySearch(n, 0, len(input_list) - 1)

if index != -1:
	print(f"Element found at index - {index} : {input_list[index]}")
else:
	print(f"{n} not found in the list - {input_list}")
