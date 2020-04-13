class BTnode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


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



print("Enter a list of integers (space separated): ", end = ' ')
input_list = [int(i) for i in input().split()]
input_list.sort()

root = BSTinput(input_list)

BTPrint(root)
