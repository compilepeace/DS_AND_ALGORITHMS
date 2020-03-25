
class BTNode:
	
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


def BTInput():
	
	n = int(input())
	if n == -1:
		return None

	new_node = BTNode(n)
	new_node.left = BTInput()
	new_node.right = BTInput()
	return new_node

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


# preorder traversal - Root, left, right
def BTPreorder(root):
	if root == None:
		return

	print(f"{root.data}", end = ' ')
	BTPreorder(root.left)
	BTPreorder(root.right)


# postorder traversal
def BTPostorder(root):
	if root == None:
		return

	BTPostorder(root.left)
	BTPostorder(root.right)
	print(f"{root.data}", end = ' ')


# inorder traversal
def BTInorder(root):
	if root == None:
		return

	BTInorder(root.left)
	print(f"{root.data}", end = ' ')
	BTInorder(root.right)


root = BTInput()
BTPrint(root)

print("Preorder ", end = ': ')
BTPreorder(root)
print()
print("Inorder  ", end = ': ')
BTInorder(root)
print()
print("Postorder", end = ': ')
BTPostorder(root)
print()
