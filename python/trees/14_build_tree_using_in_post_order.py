class BTNode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


# 1. Find the root (First element in the preorder_list)
# 2. Find the left and right subtree (from inorder list via root node) 
# 3. 
def BTbuildInorderPostorder(inorder, postorder):
	
	if len(postorder) == 0:
		return None

	root = BTNode(postorder[-1])

	left_count = 0	
	for i in inorder:
		if root.data == i:
			break
		else:
			left_count += 1

	

	root.left = BTbuildInorderPostorder(inorder[:left_count] , postorder[: left_count])
	root.right = BTbuildInorderPostorder(inorder[left_count+1:], postorder[left_count:-1])

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


inorder   = [4, 2, 5, 1, 6, 3, 7]
postorder = [4, 5, 2, 6, 7, 3, 1]

root = BTbuildInorderPostorder(inorder, postorder)
BTPrint(root)
