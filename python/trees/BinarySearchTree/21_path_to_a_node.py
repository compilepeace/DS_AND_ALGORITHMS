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


def BSTfindNode(root, k, l):

	if root == None:
		return False

	if root.data == k:
		l.append(root.data)
		return True

	ret_val1 = BSTfindNode(root.left, k, l)
	ret_val2 = BSTfindNode(root.right, k, l)
	
	if ret_val1 is True or ret_val2 is True:			
		l.append(root.data)
		return True
	else:
		return False

	
root = BTinput()
BTPrint(root)

result_list = []
BSTfindNode(root, 1, result_list)

print(result_list[::-1])
