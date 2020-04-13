# Implementing graphs using adjacency matrix 
class Graph:
	def __init__(self, nVertices):
		self.nVertices = nVertices
		self.adjMatrix = [[0 for i in range(nVertices)] for j in range(nVertices)]

	def addEdge(self, v1, v2):
		if (v1 > self.nVertices - 1) or (v1 < 0) or (v2 > self.nVertices - 1) or (v2 < 0):
			return False

		self.adjMatrix[v1][v2] = 1
		self.adjMatrix[v2][v1] = 1 

	def bfs(self):
	
		import queue
		q = queue.Queue()
		visited = [False for x in range(self.nVertices)]	
	
		q.put(0)
		q.put(None)
		visited[0] = True

		while not q.empty():			

			i = q.get()
			'''
			print(f"{i} queue: ", end = '')
			for x in range(q.qsize()):
				print(f"{q.queue[x]}", end = ' ')
			print() 
			'''	
			if i is not None:
				print(i, end = ' ')
			else:
				print()
				if q.empty():
					break
				q.put(None)
				continue
			
			for j in range(self.nVertices):
				if self.adjMatrix[i][j] == 1 and visited[j] == False:
					q.put(j)
					visited[j] = True

	# Returns a dictionary of child:parent relationship
	def __getPathBfsHelper(self, v1, v2, visited, d):

		v2_found = False
		import queue
		q = queue.Queue()
	
		q.put(v1)
		visited[v1] = True
		
		parent = child = None
		while not q.empty():
		
			u = q.get()
			parent = u	
		
			# set a flag
			if u == v2:
				v2_found = True
	
			for c in range(self.nVertices):
				if self.adjMatrix[u][c] == 1 and visited[c] == False:
					d[c] = parent
					q.put(c)
					visited[c] = True	
		
		return v2_found


	def getPathBfs(self, v1, v2):
		visited = [False for i in range(self.nVertices)]
		d = dict()

		if v1 > v2:
			v1, v2 = v2, v1
		
		result = self.__getPathBfsHelper(v1, v2, visited, d)
		if result is False:
			return False

		l = list()
		# dictionary mantained in {child: parent} fashion
		# We want it from v1->v2 (parent to child)
		l.append(v2)
		child = v2
		while 1:
			parent = d.get(child, False) 
			if parent is False:
				break		
			if parent == v1:
				l.append(parent)
				break
			l.append(parent)
			child = parent

		print(l[::-1])


	def removeEdge(self, v1, v2):
		if (v1 > self.nVertices - 1) or (v1 < 0) or (v2 > self.nVertices - 1) or (v2 < 0):
			return False

		if self.adjMatrix[v1][v2] == 0 and self.adjMatrix[v2][v1] == 0:
			return

		self.adjMatrix[v1][v2] = 0
		self.adjMatrxi[v2][v1] = 0

	def __str__(self):
		return str(self.adjMatrix)


g = Graph(7)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(0, 3)
g.addEdge(2, 4)
g.addEdge(3, 6)
g.addEdge(4, 6)

v1 = 0
v2 = 6

result = g.getPathBfs(v2, v1)
if result == False:
	print(f"Path between {v1}->{v2} : not found")

g.bfs()
