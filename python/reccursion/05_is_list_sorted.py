import sys
sys.setrecursionlimit(5000)

user_input = input("Enter the numbers (space separated) : ")

# Using list comprehension to cook a fresh list of integer values in the user_input string
input_list = [int(i) for i in user_input.strip().split(" ")]


def check_if_sorted(new_list):
	if len(new_list) <= 1:
		print("Sorted !")
		return
	if new_list[0] > new_list[1]:
		print("Not sorted !")
		sys.exit(0x1)
	sublist = []
	sublist = new_list[1:]
	print(sublist)
	check_if_sorted(sublist)

check_if_sorted(input_list)
