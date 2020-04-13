# Fibonacci series : 0 1 1 2 3 5 8 13 ... n-1, n
# F(n) = F(n-1) + F(n-2)

import sys
sys.setrecursionlimit(5000)


# Checking the command line args
script = sys.argv[0]
if ( len(sys.argv) != 2 ):
    print(f"Usage: python3 {script} <n>")
    exit(0x1)

user_input = int(sys.argv[1])


# iterative approach
def print_nth_fibonacci_number(n):
	first = 0
	second = 1
	for i in range(3, n+1):
		current = first + second
		first = second
		second = current
	print(f"{n}th fibonacci number (iterative approach) : {second}")


# Using recursion
def fibonacci_recursive(n):
	if n == 0:
		print(f"f({n}) returns 0")
		return 0
	if n == 1:
		print(f"f({n}) returns 1")
		return 1
	fib_n_1 = fibonacci_recursive(n - 1)
	fib_n_2 = fibonacci_recursive(n - 2)
	next_number = fib_n_1 + fib_n_2
	print(f"f({n}) returns {next_number}")
	return next_number


print_nth_fibonacci_number(user_input)
result = fibonacci_recursive(user_input - 1)
print(f"{user_input}th fibonacci number (iterative approach) : {result}")
