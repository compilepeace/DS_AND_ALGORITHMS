class BTNode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


# 1. Find the root (First element in the preorder_list)
# 2. Find the left and right subtree (from inorder list via root node) 
# 3. 
def BTbuildInorderPreorder(inorder_list, preorder_list):
	
	# Base case
	if len(preorder_list) == 0:
		return None

	#if len(preorder_list) == 1:
	#	root = BTNode(preorder_list[0])
	#	return root
	
	# Step 1 : Get the root
	root = BTNode(preorder_list[0])

	# This is count of nodes before root in inorder_list (for left subtree)
	left_count = 0
	for i in inorder_list:
		if i == root.data:
			break
		else:
			left_count += 1

	# This is count of nodes after root in inorder_list (for right subtree)
	right_count = len(inorder_list) - (left_count + 1)
	
	root.left = BTbuildInorderPreorder(inorder_list[ 0: (left_count+1) ], preorder_list[ 1: (left_count + 1) ])
	root.right = BTbuildInorderPreorder(inorder_list[ left_count+1: ], preorder_list[ left_count+1: ]) 

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


inorder  = [4, 2, 5, 1, 6, 3, 7]
preorder = [1, 2, 4, 5, 3, 6, 7]

root = BTbuildInorderPreorder(inorder, preorder)
BTPrint(root)
