import sys
import math


def isPerfectSquare(n):

	root = math.sqrt(n)
	result = root - int(root)
	
	if result == 0:
		return True
	else:
		return False


# This solution does not work for numbers like 41 = 5^2 + 4^2 => i.e. can be reached in 2 steps,
# Hence there is only one way -> i.e. to explore all possible paths
def minNumberOfSquares(n, dp):

	dp[0] = 0
	dp[1] = 1
	min_value = 1
	min_value_index = 1

	for i in range(2, n+1):
		if isPerfectSquare(i) == True:
			dp[i] = 1
			min_value_index = i
		else:
			dp[i] = dp[min_value_index] + dp[ i - min_value_index]

	return dp[n]


n = int(input("Enter the number"))
dp = [None for i in range(n+1)]
result = minNumberOfSquares(n, dp)
print(f"Minimum number of sum of squares for {n}: {result}")

