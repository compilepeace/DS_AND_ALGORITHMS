import sys
sys.setrecursionlimit(100000)


'''
f(10)-> f(5), f(9)		(i.e. 10/2, 10-1)
f(5) -> f(4)			(i.e. 5-1)
f(4) -> f(2), f(3)		(i.e. 4/2, 4-1)
f(2) -> f(1), f(1) 		(i.3. 2/2, 2-1)
f(3) -> f(1), f(2)		(i.e. 3/3, 3-1)
f(2) -> f(1), f(1)  	(i.e. 2/2, 2-1)
...
'''
def MinStepsTo1(n, dp):

	if n == 1:
		return 0

	a3 = INT_MAX
	if (n % 3) == 0:
		#print(f"n/3: {n/3}")
		if dp[n//3] == None:
			a3 = MinStepsTo1(n//3, dp)
			dp[n//3] = a3
		else:
			a3 = dp[n//3]

	a2 = INT_MAX
	if (n % 2) == 0:
		#print(f"n/2: {n/2}")
		if dp[n//2] == None:
			a2 = MinStepsTo1(n//2, dp)
			dp[n//2] = a2
		else:
			a2 = dp[n//2]

	if dp[n-1] == None:
		a1 = MinStepsTo1(n-1, dp)
		dp[n-1] = a1
	else:
		a1 = dp[n-1]	

	return 1 + min(a1, a2, a3)


INT_MAX = sys.maxsize
n = int(input("Enter a number: "))

dp = [None for i in range(n+1)]
min_steps = MinStepsTo1(n, dp)
print(f"Minimum steps to 1 : {min_steps}")
