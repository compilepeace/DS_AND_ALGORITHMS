
user_input = input("Enter a list of numbers in any order (space separated) : ")
input_list = [int(i) for i in user_input.strip().split(' ')]


# The loop will should iterate (n-1) times. After the first round, the largest element will be 
# present at the end of the list
def bubble_sort(l, si, ei):
	for j in range(0, ei):
		for i in range(0, ei):
			if l[i] > l[i+1]:
				l[i], l[i+1] = l[i+1], l[i]		# Swapping if adjacent elements are not in order


bubble_sort(input_list, 0, len(input_list) - 1)
print(input_list)
