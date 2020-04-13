import sys
sys.setrecursionlimit(5000)

user_input = input("Enter the numbers (space separated) : ")

# Using list comprehension to cook a fresh list of integer values in the user_input string
input_list = [int(i) for i in user_input.strip().split(' ')]


def sum_of_elements(index):
	if index == 0:
		return input_list[index]
	sum = input_list[index] + sum_of_elements(index - 1)
	return sum


result = sum_of_elements(len(input_list) - 1)
print(result)
	
