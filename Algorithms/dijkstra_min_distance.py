import sys
INT_MAX = sys.maxsize


# Implementing graphs using adjacency matrix 
class Graph:
	def __init__(self, nVertices):
		self.nVertices = nVertices
		self.adjMatrix = [[0 for i in range(nVertices)] for j in range(nVertices)]

	def addEdge(self, v1, v2, wt):
		if (v1 > self.nVertices - 1) or (v1 < 0) or (v2 > self.nVertices - 1) or (v2 < 0):
			return False

		self.adjMatrix[v1][v2] = wt
		self.adjMatrix[v2][v1] = wt 

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

	def __getMinVertex(self, distance, visited):
	
		min_vertex = -1	
		for i in range(self.nVertices):
			if visited[i] == False and (min_vertex == -1 or distance[i] < distance[min_vertex]):
				min_vertex = i

		return min_vertex	

	def dijkstras(self):

		vertex  = [i for i in range(self.nVertices)]	
		visited	= [False for i in range(self.nVertices)]
		distance = [INT_MAX for i in range(self.nVertices)]
		distance[0] = 0		

		for i in range(self.nVertices - 1):
			min_vertex = self.__getMinVertex(distance, visited)
			visited[i] = True

			for c in range(self.nVertices):	
					
				if self.adjMatrix[min_vertex][c] > 0 and visited[c] == False:
					d = distance[min_vertex] + self.adjMatrix[min_vertex][c]
					if distance[c] > d:
						distance[c] = d
					
		print("Shortest path from vertex 0 is as bellow -")
		for i in range(self.nVertices):
			print(f"{i} : {distance[i]}")
	

	def __str__(self):
		return str(self.adjMatrix)





n, x = map(int, input("Enter no. of edges and no. of further input rows (space separated): ").split())
edges = list()

g = Graph(n)

# Now, further input is given in the form of rows,
# where each row is - vertex1 vertex2 weight
while x > 0:
	v1, v2, weight = map(int, input().split())
	g.addEdge(v1, v2, weight)
	x -= 1

g.dijkstras()
