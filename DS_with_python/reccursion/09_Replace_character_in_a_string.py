input_string = input("Enter the string : ")
c = input("Enter the character to be replaced : ")
r = input(f"Enter the character which replaces {c} : ")

new_list = list(input_string)

for index in range(0, len(new_list)):
	if new_list[index] == c:
		new_list[index] = r

result_string = ''.join(new_list)
print(result_string)


def ReplaceChar(s, c1, r1):
	if (len(s) == 0):
		return s
	substring = ReplaceChar(s[1:], c1, r1)
	if s[0] == c1:
		return r1 + substring
	else:
		return s[0] + substring


modified_string = ReplaceChar(input_string, c, r)
print(modified_string)
