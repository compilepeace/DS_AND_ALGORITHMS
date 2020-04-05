import sys


def LIC(l, indx = 0):

	if indx >= len(l)-1:
		return 0	

	longest = INT_MIN

	# Iterate over the list
	for i in range(indx+1, len(l)):
		if l[i] >= l[indx]:
			ans = LIC(l, indx)
			longest = max(longest, ans)

	return 1 + longest


INT_MIN = -sys.maxsize
user_input = input("Enter the array of numbers (space separated): ")
input_list = [int(i) for i in user_input.split()]

result = LIC(input_list)
print(f"Longest Increasing Subsequence has length: {result}")

