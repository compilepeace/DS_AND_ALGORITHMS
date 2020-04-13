
class TreeNode:
	def __init__(self, data):
		self.data = data
		self.children = list()

def printTree(root):
	if root == None:
		return
	
	print(f"{root.data}", end = ': ')
	# Print all the children of root node
	for child in root.children:
		print(f"{child.data}", end = ' ')
	print()
	
	# Call printTree() on all the childrent of the root
	for child in root.children:
		printTree(child)

def inputGenericTree():
	
	data = int(input("Enter the data : "))
	root = TreeNode(data)
	numChildren = int(input(f"How many children does {data} have? "))
	
	for i in range(0, numChildren):
		child = inputGenericTree()
		root.children.append(child)

	return root


def countNodes(root):
	if root == None:
		return 0

	count = 1
	for child in root.children:
		count += countNodes(child)

	return count


def sumOfAllNodes(root):
	if root == None:
		return 0

	result = root.data
	for child in root.children:
		result += sumOfAllNodes(child)

	return result


def maxValueNode(root):
	if root == None:
		return None

	max_val = root.data
	for child in root.children:
		max_val = max(max_val, maxValueNode(child))

	return max_val


def heightOfTree(root):
	if root == None:
		return 0

	height = 0
	for child in root.children:
		height = max(height, heightOfTree(child))

	return 1 + height


root = inputGenericTree()	
printTree(root)

n = countNodes(root)
print(f"Tree has {n} nodes")

s = sumOfAllNodes(root)
print(f"Sum of all nodes in the tree : {s}")

largest = maxValueNode(root)
print(f"Maximum value in the tree : {largest}")

height = heightOfTree(root)
print(f"Height of the tree : {height}")
'''
n0 = TreeNode(9)
n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n4 = TreeNode(4)
n5 = TreeNode(5)
n10 = TreeNode(10)
n20 = TreeNode(20)
n30 = TreeNode(30)
n100 = TreeNode(100)
n110 = TreeNode(110)

n0.children.append(n1)
n0.children.append(n2)
n0.children.append(n3)
n0.children.append(n4)
n0.children.append(n5)


n3.children.append(n10)
n3.children.append(n20)
n3.children.append(n30)

n5.children.append(n100)
n5.children.append(n110)
'''
