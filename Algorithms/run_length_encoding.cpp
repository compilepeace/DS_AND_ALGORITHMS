#include <iostream>
#include <string.h>

using namespace std;


char *RunLengthEncoding(char *input)
{
	// Validate the input string
	if (strlen(input) > 100) {
		fprintf(stderr, "A liar, string length is more than 100!\n");
		exit(0x2);
	}

	// Allocate some memory on heap segment
	char *result = (char *)malloc( strlen(input) * 2 + 1);
	int i = 0, j = 0, count = 0;

	// Iterate until the end of input string
	// 1. Put the character encountered into the malloc'd memory
	// 2. Increment count until a different character is encountered 
	// 3. Put the count into the malloc'd memory
	// 4. Do this until the '\x00' (NULL byte) is encountered (that marks the end of string)
	// 5. Place the 0x00 byte at the end of our result string.
	for ( ; input[i] != '\x00'; ) {

		result[j] = input[i];                                       // Step 1
		++j;

		while(input[i] == input[i + count])		++count;            // Step 2
		i = i + count;

		int chars_written = sprintf(result + j, "%d", count);       // Step 3
		j = j + chars_written;
		count = 0;
	}
	
	result[j] = '\x00';                                             // Step 5
	
return result;
}



int main(int argc, char **argv)
{

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <input_string>\n", argv[0]);
		exit(0x1);
	}

	char *result = RunLengthEncoding(argv[1]);
	cout << result << '\n';

return 0x0;
}
