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


def BTPrintNodesAtDepthK(root, k):
	if root == None:
		return 

	if k == 0:
		print(f"{root.data}", end = " ")
		return

	BTPrintNodesAtDepthK(root.left, k-1)
	BTPrintNodesAtDepthK(root.right, k-1)	
	

def BTReplaceNodeDataWithDepth(root, k, d = 0):
	if root == None:
		return

	# When depth (default parameter) is equal to k (depth provided by user)
	if d == k:
		root.data = d

	BTReplaceNodeDataWithDepth(root.left, k, d+1)
	BTReplaceNodeDataWithDepth(root.right, k, d+1)


def BTIsNodePresent(root, k):
	if root == None:
		return False

	if root.data == k:
		print(f"{k} is present in the tree")
		return True

	val1 = BTIsNodePresent(root.left, k)
	val2 = BTIsNodePresent(root.right, k)
	
	if val1 == True or val2 == True:
		return True


root = BTInput()
print()
#BTPrint(root)
#print()
#BTPrintNodesAtDepthK(root, 2)
#BTReplaceNodeDataWithDepth(root, 2)
#print()
#BTPrint(root)

BTIsNodePresent(root, 3)
BTIsNodePresent(root, 8)

