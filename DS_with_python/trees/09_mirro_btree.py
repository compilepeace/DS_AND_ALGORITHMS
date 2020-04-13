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


# Mirrors out the tree whose root is provided as parameter
def BTmirror(root):
	if root == None:
		return

	root.left, root.right = root.right, root.left
	
	BTmirror(root.left)
	BTmirror(root.right)


root = BTInput()
print()
BTPrint(root)
BTmirror(root)
print()
BTPrint(root)
