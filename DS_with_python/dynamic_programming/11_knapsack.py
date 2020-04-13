

def knapsack(W, wt, val, i, dp):

	# Base case
	if i > len(wt) - 1:
		return 0
	
	if wt[i] > W:
		if dp[i+1][W] == None:
			ans = knapsack(W, wt, val, i+1, dp)
			dp[i+1][W] = ans
			return ans
		else:
			ans = dp[i + 1][W]
			return ans	

	else:
		# Value if you include the value, subtract its weight from the knapsack's capacity
		if dp[i+1][W - wt[i]] == None:
			subans = knapsack( W - wt[i], wt, val, i+1, dp)
			dp[i+1][W - wt[i]] = subans
			v1 = val[i] + subans
		else:
			v1 = val[i] + dp[i+1][W - wt[i]]		

		# Value if you do not include the wt in the knapsack
		if dp[i+1][W] == None:
			v2 = knapsack( W, wt, val, i+1, dp)
			dp[i+1][W] = v2
		else:
			v2 = dp[i+1][W]
	
		ans = max(v1, v2)
	
	
	return ans



weight = [int(i) for i in input("Enter weight list: ").split()]
value  = [int(i) for i in input("Enter value list : ").split()]
knapsack_capacity = int(input("Enter the maximum capacity of knapsack: "))

dp = [[None for i in range(knapsack_capacity + 1)] for i in range(len(weight) + 1)]


max_value = knapsack(knapsack_capacity, weight, value, 0, dp)
print(f"Maximum value that can be fitted in knapsack: {max_value}")

