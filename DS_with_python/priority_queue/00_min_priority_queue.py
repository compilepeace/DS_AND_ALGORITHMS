import sys
INT_MAX = sys.maxsize

class PriorityQueueNode:
	def __init__(self, value, priority):
		self.value = value
		self.priority = priority


class PriorityQueue:
	def __init__(self):
		self.pq = list()

	def getSize(self):
		return len(self.pq)

	def getMin(self):
		if self.isEmpty() is True:
			return None
		return self.pq[0].value 
		

	def isEmpty(self):
		return True if len(self.pq) == 0 else False


	# child index - ci and parent index - pi
	def __percolateUp(self):
		ci = self.getSize() - 1 

		# Swap parent-child nodes until the child priority is less than parent priority in Min Heap
		while ci > 0:
			pi = (ci - 1) // 2
			
			if (self.pq[ci].priority < self.pq[pi].priority):
				self.pq[ci], self.pq[pi] = self.pq[pi], self.pq[ci]	
				ci = pi	
				continue
			else:
				break

	# A.K.A Up-Heapify or Percolate up -> since we move upwards while inserting	
	def insert(self, value, priority):
		newNode = PriorityQueueNode(value, priority)	
		self.pq.append(newNode)
		self.__percolateUp()


	# A.K.A Down-Heapify or Percolate down -> since we move downwards while removing
	def remove(self):
		ret_value  = self.pq[0]
		self.pq[0] = self.pq.pop()

		# Now that we have our last element of the Priority Queue at 0th index
		# Compare it with its children and swap it with the child having minimum priority
		pi = 0
	
		while True:
		
			min_priority_index = INT_MAX	
			lci = 2 * pi + 1
			rci = 2 * pi + 2
			last_index   = self.getSize() - 1
	
			if lci > last_index:
				lci = None
				rci = None
				break
			elif rci > last_index:
				rci = None
		
			# If either left-child index or right-child index is not None
			if lci is not None or rci is not None:

				# When both of them are not None
				if lci is not None and rci is not None:
					# Check if the parent's prioriy is less than children's priority
					if self.pq[pi].priority > self.pq[lci].priority or self.pq[pi].priority > self.pq[rci].priority:
						if self.pq[lci].priority < self.pq[rci].priority:
							min_priority_index = lci
						else:
							min_priority_index = rci
					else:
						break

				# When rci is None but lci is not None
				elif rci is None:
					if self.pq[lci].priority < self.pq[pi].priority:
						min_priority_index = lci	
					else:
						break

				# Now swap the parent index value with min_priority_index (between 2 children)
				self.pq[pi], self.pq[min_priority_index] = self.pq[min_priority_index], self.pq[pi]
				pi = min_priority_index
		
		return ret_value	

	
	def printQueue(self):
		print()
		for i in range(self.getSize()):
			print(self.pq[i].value, self.pq[i].priority)
		print()


n = int(input("How many elements do you want to enter: "))

pqueue = PriorityQueue()
while n > 0:
	value, priority = map(int, input("Value, priority: ").split())
	pqueue.insert(value, priority)	
	n -= 1			

pqueue.printQueue()
pqueue.remove()
pqueue.printQueue()
pqueue.remove()
pqueue.printQueue()
pqueue.remove()
pqueue.printQueue()
