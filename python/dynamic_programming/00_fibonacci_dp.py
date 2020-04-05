import time

def fibonacci(n):

	if n == 0 or n == 1:
		return n

	val1 = fibonacci(n-1)
	val2 = fibonacci(n-2)

	return val1 + val2


# Fibonacci using memoization (i.e. applying some storage to use result of overlapping subproblems)
def fibonacci_dp(n, dp):

	if n == 0 or n == 1:
		return n

	if dp[n-1] == None:
		res1 = fibonacci_dp(n-1, dp)
		dp[n-1] = res1
	else:
		res1 = dp[n-1]

	if dp[n-2] == None:
		res2 = fibonacci_dp(n-2, dp)
		dp[n-2] = res2
	else:
		res2 = dp[n-2]
	
	return res1 + res2



n = int(input("Enter the number: "))

start_dp = time.time()
dp = [None for i in range(n+1)]
fib_dp = fibonacci_dp(n, dp)
end_dp = time.time()
total_time = end_dp - start_dp
print(f"Fibonacci of {n} : {fib_dp} (taking {total_time})")

start_time = time.time()
fib = fibonacci(n)
end_time = time.time()
total_time = end_time - start_time
print(f"Fibonacci of {n} : {fib} (taking {total_time})")
