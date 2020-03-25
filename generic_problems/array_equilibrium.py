
user_input = input("Enter a list of integers (space separated) : ")
input_list =  [int(i) for i in user_input.strip().split(' ')]


# Time Complexity : O(n)
def FindEquilibrium(l):

	if (len(l) < 3):
		return -1	

	# Initially, assuming index 1 as equilibrium index  
	lsum = l[0]
	rsum = 0
	for j in range(2, len(l)):
		rsum = rsum + l[j]

	# Initially, assuming index 1 as equilibrium index
	i = 1
	temp = 0
	# We got the left sublist sum in 'lsum' and right sublist sum in 'rsum'
	# Now we need to iterate i over the list till 2nd last element while comparing the lsum and rsum
	while i < len(l) - 1 :
	
		if lsum == rsum:
			return i
	
		else:
			lsum = lsum + l[i]
			rsum = rsum - l[i+1]
			i += 1

	return -1


equilibrium_index = FindEquilibrium(input_list)
print( f"Index : {equilibrium_index} , element : {input_list[equilibrium_index]}" )
