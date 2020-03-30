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


def BTdiameterOfTree(root):

	if root == None:
		return 

	left_height = BTdiameterOfTree(root.left)
	right_height = BTdiameterOfTree(root.right)	

	

root = BTInput()
print()
BTPrint(root)
result = BTdiameterOfTree(root)
print(f"Diameter of the tree is : {result}")

