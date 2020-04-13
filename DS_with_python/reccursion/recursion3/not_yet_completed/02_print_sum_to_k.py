
def printSumToK(l, i, k, subl):

	if i == len(l):
		return 

	if k == 0:
		for j in subl:
			print(j, end = ' ')
		print()

	# including l[i]
	printSumToK(l, i+1, k-l[i], subl + [l[i]])
	
	# excluding l[i]
	printSumToK(l, i+1, k, subl)



array = [int(j) for j in input("Enter an array of integers: ").split()]
total_sum = int(input("Enter the value of k: "))

printSumToK(array, 0, total_sum, [])
