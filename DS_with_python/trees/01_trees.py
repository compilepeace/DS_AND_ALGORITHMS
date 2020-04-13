class BTNode:

	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

def BTCountNodes(root):
	if root == None:
		return 0
	
	left_count = BTCountNodes(root.left)
	right_count = BTCountNodes(root.right)
	return 1 + left_count + right_count


def BTPrint(root):
	if root == None:
		return

	print(f"{root.data}", end = ': ')
	if root.left != None:
		print(f"L{root.left.data},", end = ' ')
	if root.right != None:
		print(f"R{root.right.data}", end = ' ')

	print()
	
	BTPrint(root.left)
	BTPrint(root.right)


btn1 = BTNode(1)
btn2 = BTNode(2)
btn3 = BTNode(3)
btn4 = BTNode(4)
btn5 = BTNode(5)
btn6 = BTNode(6)
btn7 = BTNode(7)

btn1.left = btn2
btn1.right = btn3

btn2.left = btn4
btn2.right = btn5

btn3.left = btn6
btn3.right = btn7

BTPrint(btn1)
