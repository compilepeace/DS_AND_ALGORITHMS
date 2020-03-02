#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

#define MAX_SIZE 10000

void get_line(char *, int );
void infix_to_postfix(char *);
int is_digit(char );
int is_higher_preceedence(char , char );
int is_operator(char );

static char *result_string;

int main()
{
	char input_buffer[MAX_SIZE];

	cout << "Enter an infix expression (eg : a + b * c) : ";
	get_line(input_buffer, MAX_SIZE);
	infix_to_postfix(input_buffer);
	printf("Postfix form : %s\n", result_string);
}


void infix_to_postfix(char *exp)
{
	stack<char> s;
	result_string = (char *)malloc( strlen(exp) + 1 );
	int marker = 0;

	// Parse the infix expresion - 'exp'
	for (int i=0 ; i < strlen(exp) ; ++i) {
	
		// If the character encountered is an operand character, append it into the result string
		if ( int ret = is_digit( exp[i] ) ) {
			*(result_string + marker++) = exp[i]; 			
			continue;
		}	

		// If the character encountered is an operator
		else if ( is_operator(exp[i]) ) {
			// compare the preceedence of the character encountered with the character at s.top()
			while ( !s.empty() && is_higher_preceedence(s.top(), exp[i]) ) {
				*(result_string + marker++) = s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
	}

	// Pop everything until stack is empty (i.e. has no operators)
	while (!s.empty()) {
		*(result_string + marker++) = s.top();
		s.pop();
	}
	result_string[strlen(exp) + 1] = '\x00';			// Mark the end of the string
}


// Return 1 if op1 has higher preceedence over op2 operator
int is_higher_preceedence(char op1, char op2)
{
	int op1_priority = 0, op2_priority = 0;

	if (op1 == '*' || op1 == '/')	op1_priority = 1;
	else op1_priority = 0;

	if (op2 == '+' || op2 == '/')	op2_priority = 1;
	else op2_priority = 0;

	return (op1_priority > op2_priority) ? 1 : 0;
}

int is_operator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*') ? 1 : 0;
}

void get_line(char *input_buffer, int limit)
{
    char c;
    int i = 0;

    while ( --limit > 0 && (c = getchar()) != '\n' && c != EOF) {
        *(input_buffer + i) = c;
        ++i;
    }
    input_buffer[i] = '\x00';
}

int is_digit(char c) 
{ 
	return (c >= 0x30 && c <= 0x39) ? 1 : 0; 
}
