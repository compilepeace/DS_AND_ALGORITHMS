class BTNode:
	
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


def BTPrint(root):
	if root == None:
		return

	print(f"{root.data}", end = ': ')
	if root.left != None:
		print(f"L{root.left.data}", end = ', ')
	if root.right != None:
		print(f"R{root.right.data}", end = ' ')
	print()

	BTPrint(root.left)
	BTPrint(root.right) 


def BTInput():

	n = int(input("-> "))
	if n == -1:
		return None

	root = BTNode(n)
	root.left = BTInput()
	root.right = BTInput()
	return root
	
def BTCountNodes(root):
	if root == None:
		return 0

	left_count = BTCountNodes(root.left)
	right_count = BTCountNodes(root.right)

	return 1 + left_count + right_count


r = BTInput()
print()
BTPrint(r)

n = BTCountNodes(r)
print(f"Total number of nodes : {n}") 
