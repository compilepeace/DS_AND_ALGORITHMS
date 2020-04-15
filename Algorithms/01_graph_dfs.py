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

	def __dfsHelper(self, v, visited):
	
		print(v)
		visited[v] = True
		for i in range(self.nVertices):
			if (self.adjMatrix[v][i] == 0 and visited[i] == False):
				# Explore this vertex	
				self.__dfsHelper(i, visited)	
					

	def dfs(self):
		visited = [False for i in range(self.nVertices)] 
		for i in range(self.nVertices):
			if visited[i] == False:
				self.__dfsHelper( 0, visited)
	
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
g.addEdge(3, 2)
g.addEdge(2, 4)

g.addEdge(5, 6)
g.addEdge(5, 7)

g.dfs()
