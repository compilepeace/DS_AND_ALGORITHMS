class MapNode:
	def __init__(self, key, value):
		self.key = key
		self.value = value
		self.next = None


class Map:
	def __init__(self):
		self.bucketSize = 5
		self.buckets = [None for i in range(self.bucketSize)] 
		self.count = 0

	def rehash(self):
		temp = self.buckets
		self.buckets = [None for i in range(2*self.bucketSize)]
		self.bucketSize = 2 * self.bucketSize
		self.count = 0
	
		# Now get all the nodes from the buckets into temp
		for head in temp:
			while head is not None:
				self.insert(head.key, head.value)
				head = head.next

	def loadFactor(self):
		return (self.count/self.bucketSize)			


	def getIndex(self, k):
		hashVal = hash(k)
		return (abs(hashVal) % self.bucketSize)

	def insert(self, key, value):
		index = self.getIndex(key)

		# If the index is already captured by other node
		head = self.buckets[index]
		while head is not None:
			if head.key == key:
				head.value = value
				return 
			head = head.next

		# If key was not found in the linked list
		new_node = MapNode(key, value)
		new_node.next = self.buckets[index]
		self.buckets[index] = new_node
		self.count += 1
		
		# Rehash if the load factor (countOfNodes/bucketSize) >= 0.7
		loadFactor = self.count/self.bucketSize
		if loadFactor >= 0.7:
			self.rehash()


	def search(self, key):
		index = self.getIndex(key)

		head = self.buckets[index]
		while head is not None:
			if head.key == key:
				return head.value
			head = head.next
		
		return False


	def remove(self, key):
		index = self.getIndex(key)

		head = self.buckets[index]
		while head is not None:
			
			# If node is at the beginning of the list
			if head.key == key:
				self.buckets[index] = head.next
				self.count -= 1
				return
			elif head.next != None and head.next.key == key:
				head.next = head.next.next
				self.count -= 1
				return
			head = head.next
		
		return False
		

m = Map()
for i in range(0,20):
	m.insert('Abhi' + str(i), i)
	print(f"load_factor : {m.loadFactor():f}, bucketSize: {m.bucketSize}")


#m = Map()
#m.insert('Brahma', 1)
#print(m.count)
#m.insert(2, 2)
#print(m.count)
#m.insert('Brahma', 3)
#print(m.count)
#m.insert('Vishnu', 4)
#m.insert('Mahesh', 'The destroyer')
#m.insert('Abhinav', 0)

#value = m.search('Mahesh')
#if value == False:
#	print("Incorrect key provided")
#else:
#	print(f"map['Mahesh']: {value}")



#print(f"count before deleting: {m.count}")
#result = m.remove('Abhinav')
#if result == False:
#	print(f"Couldn't find what you wanted to delete")
#else:
#	print(f"Deleted, now count becomes : {m.count}")

#result = m.remove('Manish')
#if result == False:
#	print(f"Couldn't find what you wanted to delete")
#else:
#	print(f"Deleted, now count becomes : {m.count}")
