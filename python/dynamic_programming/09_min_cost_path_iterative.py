import sys

def minCostPath(l, m, n):

	dp = [[None for col in range(cols)] for row in range(rows)]

	# Start iterating from the last row column-wise backwards towards [m,n] -> [0,0] 	
	for i in range(m, -1, -1):
		for j in range(n, -1, -1):

			right_min = down_min = diagonal_min = INT_MAX			
			# Check right (next col)		
			if (j+1) <= n:
				right_min = dp[i][j+1] 
			
			# Check down (next row)
			if (i + 1) <= m:
				down_min = dp[i+1][j] 
			
			# Check diagonal
			if (i + 1) <= m and (j + 1) <= n:
				diagonal_min = dp[i+1][j+1] 
			
			# Starting point - [2,2]
			elif i == m and j == n:
				val = l[i][j]
				dp[i][j] = val
				continue
 
			#print(f"{right_min}, {down_min}, {diagonal_min}")
			dp[i][j] = l[i][j] + min(right_min, down_min, diagonal_min)
	

	print(f"Result array is: {dp}")
	return dp[0][0]


# mxn matrix
rows = 3	#m
cols = 3	#n
input_list = [[1,5,11], [8,13,12], [2,3,7]]
#input_list = [[1,2,3], [4,5,6], [7,8,9]]

INT_MAX = sys.maxsize

print(f"Input array is : {input_list}", end = '\n\n')
result = minCostPath(input_list, rows-1, cols-1)
print(f"Min cost to reach [{rows-1}, {cols-1}]: {result}")
