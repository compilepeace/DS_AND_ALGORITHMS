import sys
sys.setrecursionlimit(5000)

n = int(input("Enter the number to search : "))
user_input = input("Enter the list (space separated) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]


# First occurence of the number to be searched via recursive approach
def FirstOccurence(index):
	if (index == (len(input_list))):
		print(f"{n} not present in the list - {input_list}")
		sys.exit(0x1)

	if input_list[index] == n:
		print(f"{n} occured the first time at index : {index}")
		return

	FirstOccurence(index + 1)


# Last occurence of the number to be searched via recursive approach
def LastOccurence(index):
	if index == -1:
		print(f"{n} not present in the list - {input_list}")
		sys.exit(0x2)

	if input_list[index] == n:
		print(f"Last occurence of {n} is at index : {index}")
		return

	LastOccurence(index - 1)


FirstOccurence(0)
LastOccurence(len(input_list) - 1)
