import sys
sys.setrecursionlimit(100000)

def lis(l, indx, dp):

	if indx+1 >= len(l):
		return 1

	subans = 0
	for i in range(indx+1, len(l)):
		
		if l[i] >= l[indx]:
			if dp[i] == None:
				ans = 1 + lis(l, i, dp)
				dp[i] = ans
			else:
				ans = dp[i]
			subans = max(subans, ans)

	if dp[indx + 1] == None:	
		ans2 = lis(l, indx + 1, dp)
		dp[indx + 1] = ans2
	else:
		ans2 = dp[indx + 1]
	overall = max(subans, ans2)
	
	return overall


INT_MIN = -sys.maxsize
user_input = input("Enter the array of numbers (space separated): ")
input_list = [int(i) for i in user_input.split()]

dp = [None for i in range(len(input_list))]
result = lis(input_list, 0, dp)
print(f"Longest Increasing Subsequence has length: {result}")

