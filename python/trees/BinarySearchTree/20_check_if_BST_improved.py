class BTnode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


def BTinput():

	new_node = int(input("-> "))
	if new_node == -1:
		return
	else:
		root = BTnode(new_node)

	root.left = BTinput()
	root.right = BTinput()

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


def BSTcheck(root):
	
	if root == None:
		return INT_MIN, INT_MAX, True

	left_max_value, left_min_value, left_is_bstree = BSTcheck(root.left)
	right_max_value, right_min_value, right_is_bstree = BSTcheck(root.right) 

	minimum = min(left_min_value, right_min_value, root.data)
	maximum = max(left_max_value, right_max_value, root.data)

	is_bstree = True
	if root.data <= left_max_value or root.data > right_min_value:
		is_bstree = False
	if not(left_is_bstree) or not(right_is_bstree):
		is_bstree = False

	print(root.data, maximum, minimum, is_bstree)
	return maximum, minimum, is_bstree


INT_MAX = 2147483647
INT_MIN = -2147483648
#print("Enter a list of integers (space separated): ", end = ' ')
#input_list = [int(i) for i in input().split()]
#input_list.sort()

#root = BSTinput(input_list)

root = BTinput()

BTPrint(root)

maximu, minimum, isBST = BSTcheck(root)
if isBST is True:
	print("A BST")
else:
	print("Not a BST")
