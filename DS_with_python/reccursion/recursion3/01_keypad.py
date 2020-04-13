
def keypad(n):

	if n/10 == 0:
		return [""]

	singleInt = n%10
	if singleInt == 2:
		string="abc"
	elif singleInt==3:
		string="def"     
	elif singleInt==4:
		string="ghi"
	elif singleInt==5:
		string="jkl"   
	elif singleInt==6:
		string="mno"  
	elif singleInt==7:
		string="pqrs"
	elif singleInt==8:
		string="tuv"
	elif singleInt==9:
		string="wxyz"

	smallans = keypad(n//10) 
	l = []
	for i in smallans:
		for j in string:
			l.append(i + j)

	return l
	

li = list()
number = int(input("Enter a number: "))
li = keypad(number)
print(li)
