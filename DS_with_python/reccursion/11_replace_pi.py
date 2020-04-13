
user_input = input("Enter the string containing pi : ")

# Replace occurence of pi with 3.14 in a string using recursion
def ReplacePi(s):
	if len(s) == 1 or len(s) == 0:
		return s
	if s[0] == 'p' and s[1] == 'i':
		substring = ReplacePi(s[2:])
		return "3.14" + substring
	else:
		substring = ReplacePi(s[1:])
		return s[0] + substring



result_string = ReplacePi(user_input)
print(result_string)
