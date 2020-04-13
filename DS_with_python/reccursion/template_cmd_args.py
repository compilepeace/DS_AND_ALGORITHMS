import sys
sys.setrecursionlimit(5000)

# Checking the command line args
script = sys.argv[0]
if ( len(sys.argv) != 2 ):
    print(f"Usage: python3 {script} <n>")
    exit(0x1)


