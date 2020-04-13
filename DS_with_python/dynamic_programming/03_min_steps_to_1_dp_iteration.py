import sys
sys.setrecursionlimit(100000)


def MinStepsTo1(n, dp):

	dp[0] = 0
	dp[1] = dp[2] = dp[3] = 1
	
	# Starting from index 4 of dp array
	for i in range(4, n+1):
		a1 = a2 = a3 = INT_MAX

		if (i % 3) == 0:
			a3 = 1 + dp[i//3]
		if (i % 2) == 0:
			a2 = 1 + dp[i//2]
		a1 = 1 + dp[i-1]
		
		dp[i] = min(a1, a2, a3)

	return dp[n]


INT_MAX = sys.maxsize
n = int(input("Enter a number: "))

dp = [None for i in range(n+1)]
min_steps = MinStepsTo1(n, dp)
print(f"Minimum steps to 1 : {min_steps}")
