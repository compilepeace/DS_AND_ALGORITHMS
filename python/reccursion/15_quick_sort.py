# 1. Choose a pivot
# 2. Make the pivot reach its right place
#    This is done by finding the no. of elements smaller than the pivot
#    For eg: [4, 5, 7, 2, 1, 9, 3], suppose 4 is choosed as the pivot,
#    Here 3 elements are smaller than 4 (i.e. 1,2 and 3), therefore its place is index 4
# 3. Now, ensure that all the elements smaller than the pivot is at its left side and all the
#    elements larger than it are at the right side.
# 4. Call QuickSort() at both the left half (sublist) and right half of the original list.  

import sys
sys.setrecursionlimit(15)


# getting user input
user_input = input("Enter a list of integers to sort (space separated values) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]


# Partitions the list into 2 halves and gives an index (of the pivot) for which all the elements
# to the left are smaller and all the elements to the right are greater than the pivot value
def Partition(l, si, ei):
	
	# Choosing a pivot
	pivot = l[si]
	
	count = 0
	# Find the no. of elements smaller to the pivot	
	for i in range(si+1, ei+1):
		if l[i] < pivot:
			count = count + 1
	print(f"pivot : {pivot}, count : {count}, si: {si}, ei: {ei}")

	# Place/swap the pivot to/with the 'count' index 
	l[si] = l[si + count]
	l[si + count] = pivot

	# 'i' is the pointer to left sublist and 'j' is the pointer to right sublist 
	i = si
	j = ei
	while i < count:
		# If left substring contains an element more than the value of the pivot, swap it with the 
		# right substring's value which is smaller than the pivot 
		if l[i] > pivot:
			while j > count:
				if l[j] < pivot:
					# swap
					temp = l[i]
					l[i] = l[j]
					l[j] = temp
				j = j - 1
		i = i + 1

	
	# Return the pivot index after the left and right sublist contains the values less/greater than 
	# the value of pivot
	return si + count
	

def QuickSort(l, si, ei):

	# Base case
	if si == ei or si > ei:
		return l

	print(f"\nBefore partitioning : {l}")
	# Finding pivot and placing it at the right position by swapping
	index = Partition(l, si, ei)
	print(f"After partitioning index: {index} list: {l}")

	# Applying QuickSort() to both the left end and right end of the index (pivot)
	QuickSort( l, si, index-1 )			# Sort Left sublist	
	QuickSort( l, index+1, ei )			# Sort Right sublist

	return l


final_list = QuickSort(input_list, 0, len(input_list) - 1)
print(final_list)
