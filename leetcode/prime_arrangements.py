class Solution:
    
    # Returns a list storing prime no.'s till n (including n)
    def FindPrimeList(self, n):
        
        l = []
        if n > 2: 
            l.append(2)

        for i in range(3, n+1, 2):
            if i == 3:
                l.append(i)
                continue
            
            if ( i % 2 == 0):
                continue
            
            flag = 0
            for j in range(3, (i//2) + 2, 2):
                # If i is divisible by j, it is not a prime number, so set the flag
                if (i % j) == 0:
                    flag = 1
                    break
            
            if flag != 1:
                l.append(i)
                
        return l
    
    def Factorial(self, n):
        result = 1
        for i in range(1, n+1):
            result = result * i
        return result
    
    
    def numPrimeArrangements(self, n: int) -> int:
        
        if n < 3:
            return 1
        
        prime_list = self.FindPrimeList(n)
        prime_count = len(prime_list)
        
        answer = factorial(prime_count) * factorial( n - prime_count )
        return answer % (10**9 + 7)

