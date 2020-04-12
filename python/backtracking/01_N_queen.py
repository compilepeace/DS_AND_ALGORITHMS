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


# Is it safe to put our queen @ b[r][c]? (return False if it could get hit by any queen kept on board)
def isSafe(b, r, c, n):
	
	# check vertically upwards
	i = r - 1
	while i >= 0:
		if b[i][c] == 1:
			return False
		i = i - 1
	
	# check left diagonal
	i = r - 1
	j = c - 1
	while i >= 0 and j >= 0:
		if b[i][j] == 1:
			return False
		i = i - 1
		j = j - 1

	# check right diagonal
	i = r - 1
	j = c + 1
	while i >= 0 and j < n:
		if b[i][j] == 1:
			return False
		i = i - 1
		j = j + 1

	return True 


# We place queen for a particular row
def placeQueen(b, row, n):

	if row == n:
		printBoard(b)
		return

	for c in range(n):
		if isSafe(b, row, c, n) is True:
			b[row][c] = 1
			placeQueen(b, row + 1, n)
			b[row][c] = 0
	
	return
	

def nQueen(n):	
	
	# Initially we can place queen anywhere
	board = [[0 for c in range(n)] for r in range(n)]
	placeQueen(board, 0, n)
	return


board_size = int(input("Enter the dimension of the board: "))
nQueen(board_size)
