import sys
sys.setrecursionlimit(5000)

# Checking the command line args
script = sys.argv[0]
if ( len(sys.argv) != 2 ):
    print(f"Usage: python3 {script} <n>")
    exit(0x1)

user_input = int(sys.argv[1])

def sum_till_n_numbers(n):
	if (n == 1):
		return 1
	return n + sum_till_n_numbers(n-1)


sum = sum_till_n_numbers(user_input)
print(sum)
