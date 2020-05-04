# Goal is to find the Minimum Spanning Tree



class Edge:
	def __init__(self, source, destination, weight):
		self.src = source
		self.des = destination
		self.wt  = weight


def getParent(vertex, parent):
	if (vertex == parent[vertex]):
		return vertex

	return getParent(parent[vertex], parent)


def krushkalMst(edges, nVertices):

	parent = [i for i in range(nVertices)]
	edges  = sorted(edges, key = lambda obj: obj.wt)		# We sort edges by wt field of object

	count = 0
	output = list()
	i = 0

	while count < (nVertices - 1):
		v1 = getParent(edges[i].src, parent)
		v2 = getParent(edges[i].des, parent)

		if parent[v1] != parent[v2]:
			output.append(edges[i])
			parent[v1] = parent[v2]
			count += 1
		i += 1

	return output


# n is edge count and x is no. of further input rows
n, x = map(int, input("Enter no. of edges and no. of further input rows (space separated): ").split())
edges = list()

# Now, further input is given in the form of rows,
# where each row is - vertex1 vertex2 weight
while x > 0:
	v1, v2, weight = map(int, input().split())
	e = Edge(v1, v2, weight)
	edges.append(e)

	x -= 1

result = krushkalMst(edges, n)


print()
print("-x"*5)
for i in range(len(result)):
	
	if result[i].src > result[i].des:
		print(f"{result[i].des} {result[i].src} {result[i].wt}")
	else:
		print(f"{result[i].src} {result[i].des} {result[i].wt}")


