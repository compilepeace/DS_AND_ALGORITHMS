import sys
sys.setrecursionlimit(5000)

user_input = input("Enter the numbers (space separated) : ")

# Using list comprehension to cook a fresh list of integer values in the user_input string
input_list = [int(i) for i in user_input.strip().split(" ")]


print(input_list)
