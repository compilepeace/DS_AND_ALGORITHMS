import queue

class TreeNode:
	def __init__(self, data):
		self.data = data
		self.children = list()

def levelWiseInput():

	q = queue.Queue()
	n = int(input("Enter the root node : "))
	root = TreeNode(n)
	q.put(root)

	while not q.empty():
		node = q.get()
		print(f"How many children does {node.data} have ?", end = ' ')
		num_children = int(input())
	
		for i in range(0, num_children):
			data = int(input("Enter the value of child: "))
			new_node = TreeNode(data)
			node.children.append(new_node)
			q.put(new_node)

	return root


def printLevelWise(root):
	if root == None:
		return -1

	q = queue.Queue()
	q.put(root)
	q.put(None)

	while not q.empty():
		node = q.get()
			
		if node != None:
			for i in node.children:
				q.put(i)
			print(f"{node.data}", end = ' ')
		else:
			if not q.empty():
				q.put(None)
			print()
			

def printTree(root):
	if root == None:
		return

	print(f"{root.data}", end = ': ')
	for child in root.children:
		print(f"{child.data}", end = ' ')
	print()

	for child in root.children:
		printTree(child)


root = levelWiseInput()
print()
printTree(root)
print()
printLevelWise(root)
print()
