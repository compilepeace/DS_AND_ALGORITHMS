
input_list = [int(i) for i in input("Enter the list of heights of buildings (Space separated) : ").strip().split()]


def BlocksLogged(l):

	differenceList = [0 for i in range(len(l))]
	rList = [0 for i in range(len(l))]
	lList = [0 for i in range(len(l))]
	maxLeft = maxRight = 0

	# Getting the max from and storing from both start(left) and end(right) of the input list
	for i in range(len(l)):
		j = len(l) - i - 1

		if l[i] > maxLeft:
			maxLeft = l[i]

		if l[j] > maxRight:
			maxRight = l[j]

		lList[i] = maxLeft
		rList[j] = maxRight


	# Create a difference list
	for i in range(len(l)):
		differenceList[i] = min( lList[i], rList[i] )

	# Calculating the blocks logged
	blocks = 0
	for i in range(len(l)):
		blocks += differenceList[i] - l[i]

	return blocks

	
	
n = BlocksLogged(input_list)
print(f"Blocks filled : {n}")
