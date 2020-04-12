# Source (A), Helper (B), Destination (C)

#user_input = input("Enter the stack values at source (A) (space separated): ")
#input_list = [int(i) for i in user_input.strip().split(' ')] 
count = int(input("How many disks are there : "))

def TowerOfHanoi(n, A, B, C):

	if n == 0:
		return

	# If only one disk is present
	if n == 1:
		print(f"{A}->{C}")
		return

	TowerOfHanoi(n-1, A, C, B)
	TowerOfHanoi(n-1, B, A, C)
	print(f"{A}->{C}")
'''
	if n == 1:
		print(f"Move top from : {a} to {c}")
		return

	TowerOfHanoi(n-1, A, B, C)			# n = 3, 2, 1, 0
	print(f"Move {n}th disk from: {c} to {b}") 
	TowerOfHanoi(n-1, B, A, C)
	print(f"M
'''
	
TowerOfHanoi(count, 's', 'h', 'd')
