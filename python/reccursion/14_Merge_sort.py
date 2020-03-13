
user_input = input("Enter a list of integers to sort (space separated values) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]



# Merge l1 and l2 in l
def Merge(l1, l2, l):
	
	i1 = i2 = i = 0
	
	while i1 < len(l1) and i2 < len(l2):
		if l1[i1] < l2[i2]:
			l[i] = l1[i1]
			i1 = i1 + 1
		else:
			l[i] = l2[i2]
			i2 = i2 + 1
		i = i + 1

	while i1 < len(l1):
		l[i] = l1[i1]
		i = i + 1
		i1 = i1 + 1

	while i2 < len(l2):
		l[i] = l2[i2]
		i = i + 1
		i2 = i2 + 1

	return l


def Sort(l):
	 
	mid = len(l)//2				# Integer division
	# Base Case : When only 1 element is left
	if mid == 0:
		return l

	print(f"\nSortL({l[:mid]})")		
	sublist1 = Sort( l[:mid] )
	print(f"SortR({l[mid:]})")
	sublist2 = Sort( l[mid:] )

	print(f"\nCalling Merge( {sublist1}, {sublist2}, {l}")	
	s =  Merge( sublist1, sublist2, l )			# Merge sublist1 and sublist2 in original list 'l'
	print(f"Merge() returned {s}")
	return s

final_list = Sort(input_list)
print(final_list)
