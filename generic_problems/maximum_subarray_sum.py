

def maxSubarraySum(l):

	sum_so_far = 0
	overall = 0 

	for i in range(0, len(l)):
		sum_so_far = max(l[i], sum_so_far + l[i])
		overall = max(sum_so_far, overall)
		print(f"ssf: {sum_so_far}, overall: {overall}")

	return overall


user_input = input("Enter a list of numbers (space separated): ")
input_list = [int(i) for i in user_input.split()]

result = maxSubarraySum(input_list)
print(f"maximum subarray sum: {result}")
