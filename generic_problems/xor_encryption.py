import sys

script = sys.argv[0]
if len(sys.argv) != 3:
	print(f"Usage: {script} <FILE> <KEY>")
	sys.exit(0x1)
FILE = sys.argv[1]
KEY  = sys.argv[2]


# Takes in a binary string as input and returns an string XOR'd with KEY
def xorEncrypt(bstring):
	
	barray = bytearray(bstring)
	result_barray = bytearray()
	i = 0
	
	for b in barray:
		i = i % len(KEY)
		byte = b ^ ord(KEY[i])
		#print(f"xoring KEY[{i}]" + str(KEY[i]) + f": {b} = {byte}")
		result_barray.append(byte)
		i += 1

	final_bstring = bytes(result_barray)
	return final_bstring


def xorDecrypt(bstring):
	return "inside xordecrypt"



fo = open(FILE, 'rb')
binary_content = fo.read()
# encrypt or decrypt as you wish
#fo.truncate(0)             # Clears the content of file
#fo.write(encrypted_string)
fo.close()

encrypted_string = xorEncrypt(binary_content)
fo_encrypt = open(f'{FILE}.{KEY}.encrypt', 'ab')
fo_encrypt.write(encrypted_string)
fo_encrypt.close()

fo = open(f'{FILE}.{KEY}.encrypt', 'rb')
binary_content = fo.read()
fo.close()

decrypted_string = xorEncrypt(encrypted_string)
fo_decrypt = open(f'{FILE}.{KEY}.decrypt', 'wb')

#for b in decrypted_string:
#	c = b.decode('utf-8')
#	fo_decrypt.write(c)
fo_decrypt.write(decrypted_string)
fo_decrypt.close()
