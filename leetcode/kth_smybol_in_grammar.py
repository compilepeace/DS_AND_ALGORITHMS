class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        # rows starting from 0
        rows = N - 1
        l = [ [0] ]
        cols = 1            # As initially only 1 column is there, i.e. 0 at l[0]
        
        for row in range(1, rows+1):
            #print("debug")
            sublist = []
            for col in range(0, 2**(row-1)):
                
                if l[row - 1][col] == 0:
                    sublist.append(0)
                    sublist.append(1)
                
                if l[row - 1][col] == 1:
                    sublist.append(1)
                    sublist.append(0)
            
            # Append the sublist in the main list
            l.append(sublist)
            #print(l, N-1, K-1)
        
        return l[N-1][K-1]

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            N = int(line);
            line = next(lines)
            K = int(line);
            
            ret = Solution().kthGrammar(N, K)

            out = str(ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()