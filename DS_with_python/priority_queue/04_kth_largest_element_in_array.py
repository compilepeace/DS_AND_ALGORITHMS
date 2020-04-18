import heapq
import sys

def kthLargestElement(l, k):
	smallArray = l[:k]
	heapq.heapify(smallArray)

	for i in range(k, len(l)):
		if smallArray[0] < l[i]:
			heapq.heapreplace(smallArray, l[i])
	
	ans = min(smallArray)

	return ans
			


input_array = [int(i) for i in input("Enter an array of integers (space separated): ").split()]
k = int(input("Enter the value of k: "))
result = kthLargestElement(input_array, k)
print(f"{k}th largest element in {input_array}: {result}")
