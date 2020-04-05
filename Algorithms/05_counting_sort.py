# Idea is to keep a bookkeeping array whose index are the elements of input array

import sys

def countingSort(l):
	
	largest = INT_MIN
	for i in l:
		largest = max(largest, i)

	print(f"largest: {largest}")

	bookkeeping = [0 for i in range(largest+1)]
	for e in l:
		bookkeeping[e] += 1 	

	# Construct the final array using bookkeeping array
	idx = 0
	for i in range(largest+1):
		if bookkeeping[i] != 0:
			for x in range(bookkeeping[i]):
				l[idx] = i
				idx += 1


INT_MIN = -sys.maxsize
user_input = input("Enter an array of integers to sort (space separated): ")
input_list = [int(i) for i in user_input.split()]
countingSort(input_list)
print(f"sorted list: {input_list}")
