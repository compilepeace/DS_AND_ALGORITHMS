import queue

class BTnode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


# Algorithm is - 
# -> Take the input and push it into a queue
# -> while queue is not empty:
# -> pop out of queue and ask for its children (left and right)
def BTlevelWiseInput():
	
	q = queue.Queue()
	root_data = int(input("Enter the data you want to put into root node: "))
	if root_data == -1:
		return None
	root = BTnode(root_data)
	q.put(root)

	while not q.empty():
		
		cur = q.get()
		left_data = int(input(f"Enter left child of {cur.data}-> "))
		if left_data != -1:
			left_node = BTnode(left_data)
			cur.left = left_node
			q.put(left_node)

		right_data = int(input(f"Enter right child of {cur.data} -> "))
		if right_data != -1:
			right_node = BTnode(right_data)
			cur.right = right_node
			q.put(right_node)
		

	return root


def BTPrint(root):

	if root == None:
		return

	print(f"{root.data}", end = ': ')
	if root.left != None:
		print(f"{root.left.data}", end = ', ')
	if root.right != None:
		print(f"{root.right.data}", end = ' ')
	print()

	BTPrint(root.left)
	BTPrint(root.right)


def BSTsearch(root, n):

	if root == None:
		return None

	if n == root.data:
		return root

	elif n < root.data:
		return BSTsearch(root.left, n)
	
	else:
		return BSTsearch(root.right, n)


n = 5
root = BTlevelWiseInput()
BTPrint(root)
node = BSTsearch(root, n)
if node != None:
	print(f"{node.data} found @ {node}")
else:
	print(f"{n} not found")
