
def wordWithFrequency(s, c):
	input_list = s.split()
	result_list = list()
	d = dict()

	for word in input_list:
		d[word] = d.get(word, 0) + 1

	for word in d:
		if d[word] == c:
			result_list.append(word)

	return result_list


def maxFrequency(s):
	input_list = s.split()
	result_list = list()
	d = dict()

	for word in input_list:
		d[word] = d.get(word, 0) + 1
	
	# Maximum frequency
	maximum = 0	
	for word in d:
		if d[word] > maximum:
			maximum = d[word]
			key = word

	return key, d[key]


user_input = input("Enter the string : ")
result = wordWithFrequency(user_input, 2)
print(result)

result, frequency = maxFrequency(user_input) 
print(f"Maximum occured word: {result}: {frequency} ")
