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

	def bfs(self, x):
	
		import queue
		q = queue.Queue()
		visited = [False for x in range(self.nVertices)]	
	
		q.put(x)
		q.put(None)
		visited[x] = True

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


	def __parseVertex(self, i, visited):

		import queue
		q = queue.Queue()
		
		l = list()
		q.put(i)
		visited[i] = True
		
		while not q.empty():
		
			u = q.get()
			l.append(u)
			for c in range(self.nVertices):
				if self.adjMatrix[i][c] == 1 and visited[c] == False:
					q.put(c)					
					visited[c] = True

		return l if len(l) > 1 else None

	# Returns a dictionary of child:parent relationship
	def allConnectedComponents(self):

		visited = [False for i in range(self.nVertices)]
		count = 0
		result = sublist = list()
		for i in range(self.nVertices):
			if visited[i] == False:
				count += 1
				sublist = self.__parseVertex(i, visited)		
				if sublist is not None:
					result.append(sublist)	
	
		print(f"The graph has {count} components")
		print(f"Components : {result}")


	def removeEdge(self, v1, v2):
		if (v1 > self.nVertices - 1) or (v1 < 0) or (v2 > self.nVertices - 1) or (v2 < 0):
			return False

		if self.adjMatrix[v1][v2] == 0 and self.adjMatrix[v2][v1] == 0:
			return

		self.adjMatrix[v1][v2] = 0
		self.adjMatrxi[v2][v1] = 0

	def __str__(self):
		return str(self.adjMatrix)


g = Graph(9)
g.addEdge(1, 2)
g.addEdge(1, 3)
g.addEdge(4, 5)
g.addEdge(4, 6)
g.addEdge(7, 8)

v1 = 0
v2 = 6

g.allConnectedComponents()

print('---------')
g.bfs(1)
print('---------')
g.bfs(4)
print('---------')
g.bfs(7)
print('---------')

