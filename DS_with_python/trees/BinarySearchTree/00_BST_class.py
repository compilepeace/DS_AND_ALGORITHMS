class BTnode:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


class BST:

	def __init__(self):
		self.root = None
		self.nodes_count = 0
	

	def isPresent(self, k):
		return self.isPresentHelper(self.root, k)

	def isPresentHelper(self, root, k):
		if root == None:
			return False
		
		if root.data == k:
			return True		

		if root.data > k:
			return self.isPresentHelper(root.left, k)

		if root.data < k:
			return self.isPresentHelper(root.right, k)


	def insert(self, data):
		self.nodes_count += 1
		self.root = self.insertHelper(self.root, data)

	def insertHelper(self, root, n):
		if root == None:
			new_node = BTnode(n)
			return new_node
		
		if n < root.data:
			root.left = self.insertHelper(root.left, n)
			return root

		else:
			root.right = self.insertHelper(root.right, n) 
			return root


	def deleteData(self, data):
		deleted, new_root = self.deleteDataHelper(self.root, data)
		if deleted:
			self.nodes_count -= 1
		self.root = new_root
		return deleted

	def deleteDataHelper(self, root, n):
		if root == None:
			return False, None
		
		if n < root.data:
			isDeleted, root.left = self.deleteDataHelper(root.left, n)	
			return isDeleted, root	
	
		if n > root.data:
			isDeleted, root.right = self.deleteDataHelper(root.right, n) 
			return isDeleted, root
	
		if n == root.data:
			# deleted node is a leaf
			if root.left == None and root.right == None:
				return True, None

			# deleted node having one child
			if  (root.left is None and root.right is not None):
				return True, root.right
			elif (root.left is not None and root.right is None):
				return True, root.left

			# deleted node having both children
			if root.left is not None and root.right is not None:
				right_minimum_node = self.minimum(root.right)		
				root.data = right_minimum_node.data
				isDeleted, root.right = self.deleteDataHelper(root.right, right_minimum_node.data)
				return isDeleted, root

	def minimum(self, root):
		if root.left == None:
			return root

		else:
			return self.minimum(root.left)


	def count(self):
		return nodes_count

	def printTree(self):
		self.printTreeHelper(self.root)

	def printTreeHelper(self, root):
		if root == None:
			return

		print(f"{root.data}", end = ': ')
		if root.left != None:
			print(f"{root.left.data}", end = ', ')
		if root.right != None:
			print(f"{root.right.data}", end = ' ')
		print()
		
		self.printTreeHelper(root.left)
		self.printTreeHelper(root.right)



b = BST()
b.insert(10)
b.insert(5)
b.insert(7)
b.insert(6)
b.insert(8)
b.insert(12)
b.insert(11)
b.insert(15)

print(f"Number of nodes present : {b.nodes_count}")
b.printTree()
print()
print(f"Is 9 present : {b.isPresent(9)}")
print(f"Is 13 present: {b.isPresent(13)}")
print(f"Is 11 present: {b.isPresent(11)}")
print(f"Is 7 present : {b.isPresent(7)}")
print()
# Try this with 8, 7 and 5 to cover all these cases of deletion
print(f"Number of nodes present : {b.nodes_count}")
b.deleteData(5)
b.printTree()
print(f"Number of nodes present : {b.nodes_count}")
