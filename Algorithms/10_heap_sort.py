

# We'll use the remove aproach of priority queues and store the max recieved at the end of the heap
def sortHeap(heap):
	endIndex = len(heap) - 1
	
	while endIndex > 0:
		heap[0], heap[endIndex] = heap[endIndex], heap[0]
		endIndex -= 1
		j = 0
		while True:

			pi = j 
			lci = (2 * j) + 1
			rci = (2 * j) + 2
			maxValIndex = pi

			if rci <= endIndex and (heap[pi] < heap[lci] or heap[pi] < heap[rci]):
				if heap[lci] > heap[rci]:
					maxValIndex = lci
				else:
					maxValIndex = rci

			elif rci > endIndex and lci <= endIndex:
				if heap[pi] < heap[lci]:
					maxValIndex = lci

			if maxValIndex == pi:
				break

			heap[pi], heap[maxValIndex] = heap[maxValIndex], heap[pi]				
			j = maxValIndex


def upHeapify(l):
	# Don't iterate on leaf nodes, start up-heapifying from 1st non-leaf node
	i = (len(l)//2) - 1
	lastIndex = len(l) - 1

	while i >= 0:
		j = i
		while True:
			pi = j
			lci = (2 * j) + 1
			rci = (2 * j) + 2	
			maxValIndex = pi	

			# If both lci and rci are valid
			if (rci <= lastIndex) and ( l[lci] > l[pi] or l[rci] > l[pi] ):
				if l[lci] > l[rci]:
					maxValIndex = lci
				else:
					maxValIndex = rci 
	
			# If only lci is valid
			elif rci > lastIndex and lci <= lastIndex:
				if l[lci] > l[pi]:
					maxValIndex = lci	

			if maxValIndex == pi:
				break			

			# swap the parent value with maxValue
			l[pi], l[maxValIndex] = l[maxValIndex], l[pi]
			j = maxValIndex	
		
		i -= 1

def heapSort(arr):
	if len(arr) == 0:
		return
	upHeapify(arr)
	sortHeap(arr)	




array = [int(i) for i in input("Enter a list of numbers (space separated): ").split()]
heapSort(array)
print(array)
