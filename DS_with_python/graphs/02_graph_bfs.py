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

	def __bfsHelper(self, i, visited):
	
		import queue
		q = queue.Queue()
	
		q.put(i)
		q.put(None)
		visited[i] = True

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
		print()


	def bfs(self):
		visited = [False for x in range(self.nVertices)]
		for i in range(self.nVertices):
			if visited[i] == False:
				self.__bfsHelper(i, visited)

	def removeEdge(self, v1, v2):
		if (v1 > self.nVertices - 1) or (v1 < 0) or (v2 > self.nVertices - 1) or (v2 < 0):
			return False

		if self.adjMatrix[v1][v2] == 0 and self.adjMatrix[v2][v1] == 0:
			return

		self.adjMatrix[v1][v2] = 0
		self.adjMatrxi[v2][v1] = 0

	def __str__(self):
		return str(self.adjMatrix)


g = Graph(10)
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 3)
g.addEdge(1, 4)
g.addEdge(2, 6)
g.addEdge(4, 5)
g.addEdge(5, 6)

g.addEdge(7, 8)
g.addEdge(7, 9)

g.bfs()
