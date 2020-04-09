

def knapsack(W, wt, val, i, dp):




weight = [int(i) for i in input("Enter weight list: ").split()]
value  = [int(i) for i in input("Enter value list : ").split()]
knapsack_capacity = int(input("Enter the maximum capacity of knapsack: "))

dp = [[None for i in range(knapsack_capacity + 1)] for i in range(len(weight) + 1)]


max_value = knapsack(knapsack_capacity, weight, value, 0, dp)
print(f"Maximum value that can be fitted in knapsack: {max_value}")

