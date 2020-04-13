

# Append all the subsequences into the list 'l'
def subseq(s, i, l):

	if i > len(s)-1:
		l.append(" ")
		return

	subseq(s, i+1, l)
	for c in range(len(l)):
		l.append(str(s[i]) + str(l[c]))

	return



s = input("Enter a string: ")
l = list()
subseq(s, 0, l)
print(l)
