
class BTNode:
	
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


def BTInput():
	
	n = int(input())
	if n == -1:
		return None

	new_node = BTNode(n)
	new_node.left = BTInput()
	new_node.right = BTInput()
	return new_node

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


# Function prints sum of data in all the nodes
def BTSumOfNodes(root):

	if root == None:
		return 0

	left_sum = BTSumOfNodes(root.left)
	right_sum = BTSumOfNodes(root.right)

	return root.data + left_sum + right_sum



root = BTInput()
BTPrint(root)

sum = BTSumOfNodes(root)
print(f"Sum of data in all the nodes of the Binary Tree : {sum}")
