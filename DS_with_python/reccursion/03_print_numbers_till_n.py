import sys
sys.setrecursionlimit(5000)

# Checking the command line args
script = sys.argv[0]
if ( len(sys.argv) != 2 ):
    print(f"Usage: python3 {script} <n>")
    exit(0x1)

user_input = int(sys.argv[1])


def print_numbers_reverse(n):
	if (n == 0):
		return
	print(f"{n}", end = " ")
	print_numbers_reverse(n-1)
	
def print_numbers(n):
	if (n == 0):
		return
	print_numbers(n-1)
	print(f"{n}", end = " ")


print_numbers(user_input)
print()
print_numbers_reverse(user_input)
print()
