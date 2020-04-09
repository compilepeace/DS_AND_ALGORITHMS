import sys

def minCostPath(l, m, n, dp):

	rows = len(l) - 1
	cols = len(l[1]) - 1
	#print(f"{rows}, {cols}: [{m}, {n}]")
	if m == rows and n == cols:
		#print(f"returning {l[m][n]}")
		return l[m][n]

	right_min = down_min = diagonal_min = INT_MAX

	current = l[m][n]

	if n < cols:
		if dp[m][n+1] == None:
			right_min = minCostPath(l, m, n+1, dp)
			dp[m][n+1] = right_min
		else:
			right_min = dp[m][n+1]
		#print(f"[->]: [{m},{n}] right_min : {right_min} {down_min} {diagonal_min}")

	if m < rows:
		if dp[m+1][n] == None:
			down_min  = minCostPath(l, m+1, n, dp)
			dp[m+1][n] = down_min
		else:
			down_min = dp[m+1][n]
		#print(f"[|]: [{m}, {n}] down_min : {right_min} {down_min} {diagonal_min}")

	if m < rows and n < cols:
		if dp[m+1][n+1] == None:
			diagonal_min = minCostPath(l, m+1, n+1, dp)
			dp[m+1][n+1] = diagonal_min
		else:
			diagonal_min = dp[m+1][n+1]
		#print(f"[\]: [{m}, {n}] diagonal_min : {right_min} {down_min} {diagonal_min}")

	return current + min(right_min, down_min, diagonal_min)
	

# mxn matrix
rows = 3	#m
cols = 3	#n
#input_list = [[1,5,11], [8,13,12], [2,3,7]]
input_list = [[1,2,3], [4,5,6], [7,8,9]]

INT_MAX = sys.maxsize
dp = [[None for col in range(cols)] for row in range(rows)]

result = minCostPath(input_list, 0, 0, dp)
print(dp)
print(f"Min cost to reach [{rows-1}, {cols-1}]: {result}")
