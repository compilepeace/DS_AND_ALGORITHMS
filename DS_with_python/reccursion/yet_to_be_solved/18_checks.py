#Suppose you have a string made up of only 'a' and 'b'. Write a recursive function that checks if the string was generated using the following rules:
#a. The string begins with an 'a'
#b. Each 'a' is followed by nothing or an 'a' or "bb"
#c. Each "bb" is followed by nothing or an 'a'
#If all the rules are followed by the given string, return true otherwise return false.

def check(s, si, ei):
    if si == ei:
        return True
    
    if s[0] != 'a':
        return False
    
    # If an 'a' is encountered
    if s[si] == 'a':
        # If 'a' is followed by a nothing
        if s[si + 1] == '':
            return True
        # If 'a' is followed by an 'a'
        elif s[si + 1] == 'a':
            return check(s, si+1, ei)
        
        # Else 'a' is followed by a 'b'
        else:
            # Check if a is followed by 2 b's
            if si +2 <= ei and s[si + 2] == 'b': 
                return check(s, si+1, ei)
            else:
                return False
    
    # If a 'b' is encountered
    else:
        # If 'bb' is encountered
        if s[si + 1] == 'b':
            # Is the 'bb' followed by an 'a'
            if si +2 <= ei and s[si + 2] == 'a':
                return check(s, si + 1, ei)
            # Is the 'bb' followed by a nothing ''
            elif si +2 <= ei and s[si + 2] == '':
                return True
            else:
                return False
        else:
            return False
    
    
result = check(s, 0, len(s)-1)
if result == True:
    print("true")
else:
    print("false")

