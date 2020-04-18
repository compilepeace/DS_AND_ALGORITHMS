import heapq

def kLargestElements(l, k):
	smallArray = l[:k]
	heapq.heapify(smallArray)

	for i in range(k, len(l)):
		if smallArray[0] < l[i]:
			heapq.heapreplace(smallArray, l[i])

	return smallArray[::-1]
			


input_array = [int(i) for i in input("Enter an array of integers (space separated): ").split()]
k = int(input("Enter the value of k: "))
result = kLargestElements(input_array, k)
print(f"{k} smallest elements in {input_array}: {result}")
