# Problem
# Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one 
# number is present only once in the array.
# You need to find and return that number which is unique in the array.
# Note : Given array will always contain odd number of elements.



user_input = input("Enter the array of integers (Space separated): ")
input_list = [int(i) for i in user_input.strip().split(' ')]

def FindUnique(l):
	l.sort()
	
	for i in range(0, len(l), 2):
			
		if i == len(l) - 1 or l[i] != l[i+1]:
 			return l[i] 

n = FindUnique(input_list)
print(f"Unique number: {n}")
