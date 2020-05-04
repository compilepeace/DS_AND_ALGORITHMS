# Source (A), Helper (B), Destination (C)

#user_input = input("Enter the stack values at source (A) (space separated): ")
#input_list = [int(i) for i in user_input.strip().split(' ')] 
count = int(input("How many disks are there : "))

def TowerOfHanoi(n, A, B, C):

	if n == 0:
		return

	if n == 1:
		return

	TowerOfHanoi(n-1, A, C, B)
	TowerOfHanoi(n-1, B, A, C)
	

TowerOfHanoi(count, 's', 'h', 'd')
