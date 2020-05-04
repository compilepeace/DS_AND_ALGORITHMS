# Using reccusion and dynamic programming - 28ms, 13.8MB
class Solution:
    
    def tribonacci(self, n: int) -> int:
        
        dp = [None for i in range(n+1)]
        result = self.tribonacciHelper(n, dp)
        return result
        
    def tribonacciHelper(self, n, dp):
        
        if n == 0:
            return 0
        
        if n == 1 or n == 2:
            return 1
        
        if dp[n-1] == None: 
            ans1 = self.tribonacciHelper(n-1, dp)
            dp[n-1] = ans1
        else:
            ans1 = dp[n-1]
        
        if dp[n-2] == None:
            ans2 = self.tribonacciHelper(n-2, dp)
            dp[n-2] = ans2
        else:
            ans2 = dp[n-2]
        
        if dp[n-3] == None:
            ans3 = self.tribonacciHelper(n-3, dp)
            dp[n-3] = ans3
        else:
            ans3 = dp[n-3]
        
        return (ans1 + ans2 + ans3)


# Iterative solution - 36ms, 13.7MB
'''
class Solution:
    def tribonacci(self, n: int) -> int:
        
        l = [0, 1, 1]
        if n < 3:
            return l[n]
        
        for i in range(3, n+1):
            l.append(l[i-1] + l[i-2] + l[i-3])
            
        return l[n]
'''