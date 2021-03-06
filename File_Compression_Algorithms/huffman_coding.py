import os
import sys
import heapq


class BinaryTreeNode:
	def __init__(self, value, freq):
		self.value = value
		self.freq = freq
		self.left = None
		self.right = None
	
	def __lt__(self, other):
		return self.freq < other.freq

	#def __eq__(self, other):
	#	return self.freq == other.freq	


class HuffmanCoding:
	
	def __init__(self, path):
		self.path = path
		self.__heap = []
		self.__bCodes = dict()
		self.__reverseCodes = dict()


	def __getFrequencyDictionary(self, s):
	
		d = dict()
		for c in s:
			if c not in d:
				d[c] = 0
			d[c] += 1
		return d


	def __buildHeap(self, freqDict):

		for char in freqDict:
			newNode = BinaryTreeNode(char, freqDict[char])		
			heapq.heappush(self.__heap, newNode)
		return
				
	
	def __buildTree(self):
	
		while (len(self.__heap) >= 2):
			btNode1 = heapq.heappop(self.__heap)
			btNode2 = heapq.heappop(self.__heap)

			root = BinaryTreeNode(None, btNode1.freq + btNode2.freq)
			root.left = btNode1
			root.right = btNode2

			heapq.heappush(self.__heap, root)

		return

	
	def __buildCodesHelper(self, root, codeBits):
	
		if root == None:
			return

		# If root is not a merge node rather a leaf node, then add in bCodes dictionary() 	
		# Store the reverse codes as well
		if root.value is not None:
			self.__bCodes[root.value] = codeBits
			self.__reverseCodes[codeBits] = root.value
			return

		self.__buildCodesHelper(root.left, codeBits + "0")
		self.__buildCodesHelper(root.right, codeBits + "1")
		

	def __buildCodes(self):
		root = heapq.heappop(self.__heap)
		self.__buildCodesHelper(root, "")
	

	def __getEncodedText(self, s):
		encoded_text = ''
		for c in s:
			encoded_text += self.__bCodes[c]
		return encoded_text

	
	def __getPaddedEncodedText(self, encodedStr):
		padding_size = 8 - (len(encodedStr) % 8)
		padding = '0' * padding_size
		
		# Now, a byte will preceed the final padded encoded string representing the padding_size
		padding_len_str = "{0:08b}".format(padding_size) 
		final_string = padding_len_str + encodedStr + padding
		
		return final_string

	
	def __getBytesArray(self, paddedEncodedStr):
		
		bytesArray = list()
		for i in range(0, len(paddedEncodedStr), 8):
			byte = paddedEncodedStr[ i: i+8 ]
			bytesArray.append(int(byte, 2))
		
		return bytesArray


	def compress(self):
		
		# Open and read the file (from path) in binary format
		filepath, extension = os.path.splitext(self.path)
		output_filename = filepath + ".abhinav"
		output_fo = open(output_filename, 'wb')
		input_fo = open(self.path, 'r+')
		fileStr = input_fo.read().rstrip()

		# craft a frequency dictionary from the characters of the file
		frequencyDict = self.__getFrequencyDictionary(fileStr)

		# construct a min heap
		self.__buildHeap(frequencyDict)	

		# construct a binary tree from heap 
		self.__buildTree()		

		# Now, all our heap nodes are merged into a single root node, i.e. self.__heap = [root]
		# construct binary codes from binary tree
		self.__buildCodes()

		# construct encoded text using binary codes
		encodedText = self.__getEncodedText(fileStr)

		# pading the encoded text
		paddedEncodedText = self.__getPaddedEncodedText(encodedText)

		# Get bytes array
		bytesArray = self.__getBytesArray(paddedEncodedText)
		bytesString = bytes(bytesArray)
		
		# put the encoded text into a binary file 	
		output_fo.write(bytesString)
	
		# return the binary file as output
		return output_filename


	def __removePadding(self, padded_bit_string):
		padding_size = int(padded_bit_string[:8], 2)

		text = padded_bit_string[8:]
		string_without_padding = text[:-1*(padding_size)]
		
		return string_without_padding
		

	def __getDecodedString(self, s):
		final_string = ''
		bits_so_far = ''
	
		for bit in s:
			bits_so_far += bit
			if bits_so_far in self.__reverseCodes:
				char = self.__reverseCodes[bits_so_far]
				final_string += char
				bits_so_far = ''
		return final_string


	def decompress(self, input_path):
		filename, extension = os.path.splitext(input_path)
		output_path = filename + "_decompressed" + ".txt"

		output_fo = open(output_path, 'w')
		input_fo  = open(input_path, 'rb')		

		# Now we have to read the input file byte-by-byte and 
		# add each byte (as a stream of bits) into the bit_string	
		bit_string = ''	
		byte = input_fo.read(1)
		while byte:
			integer = ord(byte)
			binary_string  = bin(integer)[2:].rjust(8, '0')
			bit_string += binary_string
			byte = input_fo.read(1)

		string_without_padding = self.__removePadding(bit_string)
		
		decompressed_string = self.__getDecodedString(string_without_padding)
		output_fo.write(decompressed_string)
	

h = HuffmanCoding(sys.argv[1])
output_file_path = h.compress()
h.decompress(output_file_path)
