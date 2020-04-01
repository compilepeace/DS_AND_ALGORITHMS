

def removeDuplicates(s):
	finalString = ""
	d = dict()

	for c in s:
		if d.get(c, 0) == 0:
			d[c] = 1
			finalString = finalString + str(c)

	return finalString			



input_string = input("Enter a string containing duplicates: ")
result = removeDuplicates(input_string)
print(result)
