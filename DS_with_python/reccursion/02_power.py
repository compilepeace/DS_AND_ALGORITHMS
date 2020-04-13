import sys
sys.setrecursionlimit(5000)

# Checking the command line args
script = sys.argv[0]
if ( len(sys.argv) != 3 ):
    print(f"Usage: python3 {script} <n> <a>")
    exit(0x1)


n = int(sys.argv[1])
a = int(sys.argv[2])

# Implementing n**a via reccursion 
def pow(n, a):
	if (a == 1):
		return n
	return n * pow(n, a-1)


result = pow(n, a)
print(result)


