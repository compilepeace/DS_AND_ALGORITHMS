
c = "#"
s = input("Enter a string containing duplicates : ")

def DelimitDuplicate(s, si):
    # Base case when si reached the end of string
    if si >= len(s)-1:
        return s

    if s[si] == s[si + 1]:
        modified_string = s[:si+1] + c + s[si+1:]
        return DelimitDuplicate(modified_string, si + 1)
    
    else:
        return DelimitDuplicate(s, si + 1)

new_str = DelimitDuplicate(s, 0)
print(new_str)
