
user_input = input("Enter a string x_x : ")
c = input("Enter the character to be removed : ")


def RemoveChar(s, c):
	if (len(s) == 0):
		return s

	substring = RemoveChar(s[1:], c)
	if s[0] == c:
		return substring
	else:
		return s[0] + substring

result = RemoveChar(user_input, c)
print(result)
