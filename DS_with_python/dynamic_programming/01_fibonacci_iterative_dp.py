import time

# Fibonacci using memoization (i.e. applying some storage to use result of overlapping subproblems)
def fibonacci_dp(n, dp):

	dp[0] = 0
	dp[1] = 1
	fib = 0
	
	for i in range(2, n+1):
		dp[i] = dp[i-1] + dp[i-2]

	return dp[n]



n = int(input("Enter the number: "))

start_dp = time.time()
dp = [None for i in range(n+1)]
fib_dp = fibonacci_dp(n, dp)
end_dp = time.time()
total_time = end_dp - start_dp
print(f"Fibonacci of {n} : {fib_dp} (taking {total_time})")

