
user_input = input("Enter a list of numbers (space separated) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]


def SelectionSort(l, si, ei):
	
	# Base case
	if si >= ei:
		return 

	# Find the minimum element from the list and swap
	smallest_index = si
	for i in range(si+1, ei+1):
		if l[i] <= l[smallest_index]:
			smallest_index = i

	# Swap to get the smallest element at l[si]	
	l[si], l[smallest_index] = l[smallest_index], l[si]
	SelectionSort(l, si+1, ei)


SelectionSort(input_list, 0, len(input_list)-1)
print(input_list)
