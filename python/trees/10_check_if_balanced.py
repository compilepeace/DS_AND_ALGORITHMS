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



#def BTHeight(root):
#	if root == None:
#		return 0
#
#	return 1 + max( BTHeight(root.left), BTHeight(root.right) )


#def BTisBalanced(root):
#
#	if root == None:
#		return True
#
#	left_height = BTHeight(root.left)
#	right_height = BTHeight(root.right)
#
#	if abs(left_height - right_height) > 1:
#		return False
#	
#	left_balance = BTisBalanced(root.left)
#	right_balance = BTisBalanced(root.right)
#
#	if left_balance and right_balance:
#		return True
#	else:
#		return False


def BTisBalanced(root):
	if root == None:
		return 0, True

	left_height, left_balance = BTisBalanced(root.left)
	right_height, right_balance = BTisBalanced(root.right)
	
	if abs( left_height - right_height ) > 1:
		return 1 + max( left_height, right_height), False
	
	elif left_balance and right_balance:
		return 1 + max( left_height, right_height), True

	else:
		return 1 + max( left_height, right_height), False
	


root = BTInput()
#h = BTHeight(root)
#print(f"Height of tree : {h}")
print()
BTPrint(root)
height, result = BTisBalanced(root)

if result == True:
	print("Tree is balanced")
else:
	print("Tree not balanced")
