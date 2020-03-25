
user_input = input("Enter a list of numbers (space separated) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]


# n is the number to be inserted
# b is upper bound of the list
def InsertIntoSorted(l, n, ei):
	
	new_list = []
	inserted = False
	for i in range(0, ei+1):
		if n > l[i] and i<ei+1:
			new_list.append(l[i])

		else:
			new_list.append(n)
			new_list.append(l[i])
			inserted = True
			break

	if inserted == False:
		new_list.append(n)
	
	print(new_list, ei, len(l))

	# append the remaining list
	for j in range(i+1, len(l)):
		new_list.append(l[j])

	print(new_list)
	return new_list


# initially l[:bound] sublist is sorted and l[bound+1:] sublist is unsorted
def InsertionSort(l, bound):
	
	if bound > len(l) - 1:
		print(f"Final list : {l}")
		return 
	
	insert_n = l[bound]
	l.reverse()
	l.remove(l[-(bound+1)])							# Remove the element from the list
	l.reverse()
	print(f"[{bound}] removed {insert_n} : {l}") 
	l = InsertIntoSorted(l, insert_n, bound - 1)	# insert the element at the appropriate position
	print(f"[{bound}] inserted {insert_n} : {l}")
	InsertionSort(l, bound+1)


InsertionSort(input_list, 1)
