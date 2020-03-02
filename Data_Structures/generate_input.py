
n = 10

fo = open('hell_input', 'w')

fo.write(str(n))

for i in range(1, n+1): 
	fo.write(" " + str(i));

fo.write("\n")

fo.close()
