# Runtime: 24ms, memory usage: 13.8MB
class Solution:
    
    # Retuns the number of occurences of 'X' or 'O'
    def count(self, b, c):
        
        print(b)
        count = 0
        for i in range(3):
            for j in range(len(b[i])):
                if b[i][j] == c:
                    count += 1
                    
        return count
    
    # Returns the number of wins or 0 in 'NO WIN' situation
    def wins(self, board, c):
        b = [[0 for j in range(3)] for i in range(3)]
        
        # Fill b with 1 on all the occurences of character c
        for i in range(3):
            for j in range(len(board[i])):
                if board[i][j] == c:
                    b[i][j] = 1
            
        wins = 0

        # 2 Checks for diagonals
        if (b[0][0] == 1 and b[1][1] == 1 and b[2][2] == 1):
            wins += 1
        if (b[0][2] == 1 and b[1][1] == 1 and b[2][0] == 1):
            wins += 1  
        
        # 3 Checks for rows
        if (b[0][0] == 1 and b[0][1] == 1 and b[0][2] == 1):
            wins += 1
        if (b[1][0] == 1 and b[1][1] == 1 and b[1][2] == 1):
            wins += 1
        if (b[2][0] == 1 and b[2][1] == 1 and b[2][2] == 1):
            wins += 1
        
        # 3 Checks for columns
        if (b[0][0] == 1 and b[1][0] == 1 and b[2][0] == 1):
            wins += 1
        if (b[0][1] == 1 and b[1][1] == 1 and b[2][1] == 1):
            wins += 1
        if (b[0][2] == 1 and b[1][2] == 1 and b[2][2] == 1):
            wins += 1
            
        return wins
    
    
    def validTicTacToe(self, board: List[str]) -> bool:
        # We will look for cases that cannot happen to be valid one's a tic-tac-toe game
        # -> count('X') < count('O') and count('X') - count('Y') > 1
        # -> Both 'X' and 'O' doesn't win at the same time
        
        xCount = self.count(board, 'X')
        oCount = self.count(board, 'O')
        if xCount < oCount or (xCount - oCount) > 1:
            #print(f'count false {xCount} {oCount}')
            return False
        
        xWins = self.wins(board, 'X')
        oWins = self.wins(board, 'O')
        
        if xWins and (xCount <= oCount):
            return False
        
        if oWins and (xCount != oCount):
            return False
        
        if ((not xWins) and (not oWins)) and xCount < oCount:
            return False
        
        
        if (xWins and oWins):
            #print('{xWins} {oWins} wins false')
            return False
        
        return True
        