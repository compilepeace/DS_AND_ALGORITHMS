import sys
sys.setrecursionlimit(10000)


def printBoard(b):
	n = len(b)
	m = len(b[0])

	print("~~" * n)
	for i in range(n):
		for j in range(m):
			print(b[i][j], end = ' ')
		print()
	print("~~" * n)


def printPath(maze, i, j, b):

	rows = len(maze)
	cols = len(maze[0]) 

	# Base case (i.e. we reached maze[rows-1][cols-1])
	if i == rows - 1 and j == cols - 1:
		b[i][j] = 1
		printBoard(b)
		return

	# Blocking points
	if i < 0 or j < 0 or i >= rows or j >= cols or maze[i][j] == 0 or b[i][j] == 1:
		return
	
	b[i][j] = 1

	printPath(maze, i, j+1, b)	# Move right
	printPath(maze, i+1, j, b)	# Move down
	printPath(maze, i, j-1, b)	# Move left
	printPath(maze, i-1, j, b)	# Move up

	b[i][j] = 0
	return 


def ratInAMaze(maze):	
	solution = [[0 for c in range(len(maze[0]))] for r in range(len(maze))]
	printPath(maze, 0, 0, solution)
	return



rows, cols = map(int, input("Enter the dimension of matrix (N x M): ").split())
maze = list()
for r in range(rows):
	maze.append( [int(i) for i in input("Enter row: ").split()] ) 

print("Entered maze matrix is")
print("-x"*rows)
for m in range(rows):
	for n in range(cols):
		print(maze[m][n], end = ' ')
	print()
print("-x"*rows)

ratInAMaze(maze)
