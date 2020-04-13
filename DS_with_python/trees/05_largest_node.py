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


#This function parses the tree and returns the largest node
def FindLargest(root, largest):

	if root == None:
		return largest

	if root.data > largest:
		largest = root.data

	largest = FindLargest(root.left, largest)
	largest = FindLargest(root.right, largest)
	return largest


def NodesGreaterThanX(root, x):
	count = 0
	if root == None:
		return 0

	if root.data > x:
		count += 1

	count += NodesGreaterThanX(root.left, x)
	count += NodesGreaterThanX(root.right, x)
	return count


root = BTInput()
BTPrint(root)
result = FindLargest(root, -1)
print(f"Largest node in the tree: {result}")
count = NodesGreaterThanX(root, 5)
print(f"Number of nodes greater than 5 : ", count)
