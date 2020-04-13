class BTNode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

def BTInput():
	
	n = int(input())
	if n == -1:
		return None

	root = BTNode(n)
	root.left = BTInput()
	root.right = BTInput()
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


def BTHeight(root):
	if root == None:
		return 0

	left_height = BTHeight(root.left)
	right_height = BTHeight(root.right)
	larger = max(left_height, right_height)

	return 1 + larger


def BTNumberOfLeafNodes(root):
	if root == None:
		return 0

	n1 = BTNumberOfLeafNodes(root.left)
	n2 = BTNumberOfLeafNodes(root.right)

	if n1 == 0 and n2 == 0:
		return 1
	else:
		return n1 + n2



root = BTInput()
BTPrint(root)
h = BTHeight(root)
print(f"Height of tree : {h}")

n = BTNumberOfLeafNodes(root)
print(f"Number of leaf nodes : {n}")
