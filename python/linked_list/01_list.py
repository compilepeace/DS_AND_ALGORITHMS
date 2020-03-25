
class Node:


	def __init__(self, data):
		self.data = data
		self.next = None


	def print_list(self, head):
		ptr = head
		while ptr is not None:
			print(f"{ptr.data}->", end = ' ')
			ptr = ptr.next
		print("None")


	def length(self, head):
		ptr = head
		count = 0
		while ptr is not None:
			count += 1
			ptr = ptr.next 

		return count


	def print_ith_node(self, head, i):
		ptr = head
		count = 0
		while ptr is not None:
			count += 1
			if count == i:
				return ptr.data
			ptr = ptr.next
		
		return -1

	
	def insert(self, head, n, i):
		ptr = head
		new_node = Node(n)

		# insert at the beginning 
		if i == 1:
			new_node.next = head.next
			head = new_node
			return head

		for j in range(1, i):
			if j == i-1:
				new_node.next = ptr.next
				ptr.next = new_node
				return head
			else:
				ptr = ptr.next


def GetList():

	# Getting list elements from user	
	input_list = [int(i) for i in input("Enter the list -> ").split()]
	head = None
	tail =  None

	for n in input_list:
		# Create a node and link its 'next'
		new_node = Node(n)

		# If it is the first element of input list
		if head is None:
			tail = head = new_node
			continue
		
		# If it is not the first element in the list
		tail.next = new_node
		tail = new_node

	return head


head = GetList()
#head.print_list(head)
#size = head.length(head)
#print(f"List has : {size} elements")
#i = int(input("Enter the index (starting from 1) you want to query: "))
#result = head.print_ith_node(head, i)
#print(f"list[i] : {result}")
head.print_list(head)
head = head.insert(head, 200, 2)
head.print_list(head)
