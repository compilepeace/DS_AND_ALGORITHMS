import queue

class BTNode:
	
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None


def BTInput():

	n = int(input("-> "))
	if n == -1:
		return None

	root = BTNode(n)
	root.left = BTInput()
	root.right = BTInput()
	return root


# None is the marker to end a level
def BTprintLevelwise(root):

	q = queue.Queue()
	q.put(root)
	q.put(None)

	while not q.empty():
		cur = q.get()
		if cur is not None:
			print(f"{cur.data}", end = ' ')
			if cur.left is not None:
				q.put(cur.left)
			if cur.right is not None:
				q.put(cur.right)
		else:
			print()
			if not q.empty():
				q.put(None)


r = BTInput()
print()
BTprintLevelwise(r)

