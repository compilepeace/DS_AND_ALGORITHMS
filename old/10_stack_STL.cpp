#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

#define MAX_SIZE 1000

void get_line(char *, int );
void reverse_string(char *, int );

int main()
{
	char input_buffer[MAX_SIZE];

	cout << "Enter the string to be reversed : ";
	get_line(input_buffer, MAX_SIZE);
	

	reverse_string(input_buffer, strlen(input_buffer));

	printf("Reversed string : %s\n", input_buffer);
}


void get_line(char *input_buffer, int limit)
{
	int i=0;
	char c;

	while ( (c = getchar()) != '\n' && c != '\n' ) {
		if (limit == 0)
			break;
		--limit;
		input_buffer[i++] = c; 
	}
	input_buffer[i] = '\x00';
} 


void reverse_string( char *input_string, int size) 
{
	stack<char> my_stack;

	// Pushing characters onto the stack
	for (int i = 0 ; i < size ; ++i) 
		my_stack.push(*(input_string + i));		

	// Overwriting the input string (character array) by poping characters from the stack
	for (int i = 0 ; i < size ; ++i) {
		*(input_string + i) = my_stack.top(); 	// Returns the reference of the topmost element of stack
		my_stack.pop();
	}
}
