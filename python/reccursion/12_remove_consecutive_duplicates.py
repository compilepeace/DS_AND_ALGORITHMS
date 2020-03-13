user_input = input("Enter a string : ")

def RemoveDuplicates(s):
	# base case
	if len(s) == 0 or len(s) == 1:
		return s	
	
	substring = RemoveDuplicates(s[1:])
	if s[0] == s[1]:
		return substring

	else:
		return s[0] + substring


result_string = RemoveDuplicates(user_input)
print(result_string)
