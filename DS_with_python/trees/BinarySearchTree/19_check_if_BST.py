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


def BSTinput(l):

	if len(l) == 0:
		return None
	
	mid_index = len(l)//2
	root = BTnode( l[mid_index] )

	root.left  = BSTinput( l[:mid_index] )
	root.right = BSTinput( l[mid_index+1:] )

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


def BTfindMax(root):
	if root == None:
		return INT_MIN

	left_max = BTfindMax(root.left)
	right_max = BTfindMax(root.right)

	return max(left_max, right_max, root.data)


def BTfindMin(root):
	if root == None:
		return INT_MAX

	left_min = BTfindMin(root.left)
	right_min = BTfindMin(root.right)

	return min(left_min, right_min, root.data)


def BSTcheck(root):
	if root == None:
		return True

	max_left_subtree = BTfindMax(root.left)
	min_right_subtree = BTfindMin(root.right)
	
	if (max_left_subtree > root.data) or (min_right_subtree < root.data):
		return False

	is_left_BST = BSTcheck(root.left)
	is_right_BST = BSTcheck(root.right)

	return is_left_BST and is_right_BST
	


INT_MAX = 2147483647
INT_MIN = -2147483648
#print("Enter a list of integers (space separated): ", end = ' ')
#input_list = [int(i) for i in input().split()]
#input_list.sort()

#root = BSTinput(input_list)

root = BTinput()

BTPrint(root)

isBST = BSTcheck(root)
if isBST is True:
	print("A BST")
else:
	print("Not a BST")
