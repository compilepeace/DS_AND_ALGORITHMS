import sys
sys.setrecursionlimit(5000)

# Checking the command line args
script = sys.argv[0]
if ( len(sys.argv) != 2 ):
    print(f"Usage: python3 {script} <n>")
    exit(0x1)

n = int(sys.argv[1])


def factorial(n):
	if n == 0:
		return 1
	return n * factorial(n-1)


result = factorial(n)
print(result)

 
