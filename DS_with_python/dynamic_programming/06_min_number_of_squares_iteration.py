import sys
import math

def isPerfectSquare(n):

    root = math.sqrt(n)
    result = root - int(root)

    if result == 0:
        return True
    else:
        return False


def minNumberOfSquares(n):

	dp = [None for i in range(n+1)]
	dp[0] = 0
	for j in range(1, n+1):

		result = INT_MAX	
		for i in range(1, int(math.sqrt(j) + 1)):
			ans = dp[j - i*i]
			result = min(ans, result)
			print(f"j: {j}, i: {i} result: {result}")

		dp[j] = 1 + result	

	print(dp)
	return dp[n]
	

INT_MAX = sys.maxsize
n = int(input("Enter the number: "))
result = minNumberOfSquares(n)
print(f"Minimum number of sum of squares for {n}: {result}")

