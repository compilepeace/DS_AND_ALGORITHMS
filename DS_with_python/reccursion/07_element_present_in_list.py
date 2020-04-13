import sys
sys.setrecursionlimit(5000)

n = int(input("Enter the number to search : "))
user_input = input("Enter the list (space separated) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]

# Recursive approach
def FindNumber(index):
	if input_list[index] == n:
		print(f"{n} found at index : {index}")
		return
	if index < 0:
		print(f"{n} NOT found in list !")
		return False
	FindNumber(index - 1)


FindNumber(len(input_list) - 1)
	

