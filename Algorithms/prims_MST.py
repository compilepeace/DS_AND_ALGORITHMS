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

	def __getMinVal(self, weight, visited):

		min_vertex = -1
		for i in range(self.nVertices):
			if visited[i] == False and (min_vertex == -1 or weight[min_vertex] > weight[i]):
				min_vertex = i

		return min_vertex

	def primsMst(self):

		visited = [False for i in range(self.nVertices)] 
		parent  = [-1 for i in range(self.nVertices)]
		weight  = [INT_MAX for i in range(self.nVertices)]
		
		weight[0] = 0	

		# Traverse over visited list
		for i in range(self.nVertices):
			min_vertex = self.__getMinVal(weight, visited)
			visited[min_vertex] = True

			# Explore its (min_weight's) adjacent vertices and update their parent and 
			# weight values (if needed)
			for c in range(self.nVertices):
				if self.adjMatrix[min_vertex][c] != 0 and visited[c] == False:
					if weight[c] > self.adjMatrix[min_vertex][c]:
						weight[c] = self.adjMatrix[min_vertex][c] 
						parent[c] = min_vertex

		print()
		for i in range(1, self.nVertices):
			if i < parent[i]:
				print(f"{i} {parent[i]} {weight[i]}")
			else:
				print(f"{parent[i]} {i} {weight[i]}")		
			
	

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

g.primsMst()
