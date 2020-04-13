import sys
import math

def isPerfectSquare(n):

    root = math.sqrt(n)
    result = root - int(root)

    if result == 0:
        return True
    else:
        return False


def minNumberOfSquares(n, dp):

	if n == 0:
		return 0

	# In case number is a perfect square
	if isPerfectSquare(n):
		return 1
	
	result = INT_MAX
	for i in range(1, int(math.sqrt(n)) + 1):
		if dp[n - i*i] == None:
			ans = minNumberOfSquares( n - i*i, dp)
		else:
			ans = dp[ n - i*i ]
		result = min(ans, result)

	dp[n] = 1 + result
	return dp[n]

INT_MAX = sys.maxsize
n = int(input("Enter the number: "))
dp = [None for i in range(n+1)]
result = minNumberOfSquares(n, dp)
print(f"Minimum number of sum of squares for {n}: {result}")
print(f"dp: {dp}")
