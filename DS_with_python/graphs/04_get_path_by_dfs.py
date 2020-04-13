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

	# Returns a list of path from v1->v2, if path doesn't exist, returns None
	def __getPathHelper(self, v1, v2, visited, l):
		
		if self.adjMatrix[v1][v2] == 1:
			l.append(v2)
			l.append(v1)
			return l

		visited[v1] = True
		for c in range(self.nVertices):
			if self.adjMatrix[v1][c] == 1 and visited[c] == False:
				ans = self.__getPathHelper(c, v2, visited, l)
				if ans is not None:
					l.append(v1)
					return l

		return None
	


	def getPath(self, v1, v2):
		visited = [False for i in range(self.nVertices)]
		# v1 should store the smaller value
		if v1 > v2:
			v1, v2 = v2, v1

		List = list()
		for i in range(self.nVertices):
			if visited[i] == False:
				result = self.__getPathHelper(v1, v2, visited, List)
				if result is not None:
					break
	
		return result


	def removeEdge(self, v1, v2):
		if (v1 > self.nVertices - 1) or (v1 < 0) or (v2 > self.nVertices - 1) or (v2 < 0):
			return False

		if self.adjMatrix[v1][v2] == 0 and self.adjMatrix[v2][v1] == 0:
			return

		self.adjMatrix[v1][v2] = 0
		self.adjMatrxi[v2][v1] = 0

	def __str__(self):
		return str(self.adjMatrix)


g = Graph(8)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 3)
g.addEdge(1, 4)
g.addEdge(2, 6)
g.addEdge(4, 5)
g.addEdge(5, 6)

v1 = 0
v2 = 6
result = g.getPath(v2, v1)
if result == None:
	print(f"Path from {v1} -> {v2}: {result}")
else:
	print(f"Path from {v1} -> {v2}: {result}") 

g.bfs()
