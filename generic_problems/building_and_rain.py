
user_input = input("Enter the list of heights of buildings (Space separated) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]


def BlocksFilled(l):

	for i in range(0, len(l)):
		

	
n = BlocksFilled(input_list)
print(f"Blocks filled : {n}")
