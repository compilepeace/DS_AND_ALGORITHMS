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


	def hasPathHelper(self, v1, v2, visited):
		
		if self.adjMatrix[v1][v2] == 1:
			return True

		visited[v1] = True
		for i in range(self.nVertices):
			if self.adjMatrix[v1][i] == 1 and visited[i] == False:
				ans = self.hasPathHelper(i, v2, visited)
				if ans is True:
					return True

		return False



	def hasPath(self, v1, v2):
		visited = [False for i in range(self.nVertices)]
		result = self.hasPathHelper(v1, v2, visited)
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

print(g.hasPath(0, 4))
print(g.hasPath(2, 5))
print(g.hasPath(2, 7))

g.bfs()
