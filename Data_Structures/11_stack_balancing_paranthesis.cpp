#include <iostream>
#include <string.h>
#include <stack>

#define MAX_SIZE 10000
using namespace std;


void check_balanced_symbols(char *);
void get_line(char *, int );


int main()
{
	char input_string[MAX_SIZE];

	cout << "Enter a sequence of symbols to check for balancing : ";
	// Get an input string from user
	get_line(input_string, MAX_SIZE);

	check_balanced_symbols(input_string);
}


void check_balanced_symbols(char *input)
{
	stack<char> symbols;
	unsigned int i = 0;

	// Parse the string character-by-character
	while(i < strlen(input)) {
		// If character encountered is one of - '(', '[' or '{' -> i.e. expression opener,
		// Push it onto the stack 
		if ( input[i] == '(' || input[i] == '[' || input[i] == '{' ) {
			fprintf(stdout, "\033[32m[+]\033[0m Pushing %c onto stack\n", input[i]);	
			symbols.push(input[i]);
		}


		if (symbols.empty() && strlen(input) != 0) {
			fprintf(stderr, "Not balanced, list is empty while we got %c\n", input[i]);
			return;
		}

		// If character encountered is one of - ')', ']' or '}' -> i.e. expression closure
		if ( input[i] == ')' || input[i] == ']' || input[i] == '}' ) {
			if	( (input[i] == ']' && symbols.top() == '[') ||
				  (input[i] == '}' && symbols.top() == '{') ||
				  (input[i] == ')' && symbols.top() == '(')  
				) {
				fprintf(stdout, "\033[31m[-]\033[0m Poping %c form stack\n", input[i]);
				symbols.pop();
			}
			else {
				fprintf(stderr, 
						"%s : Not balanced symbols. should have encountered %c but encountered %c\n",
						__FUNCTION__, symbols.top(), input[i]); 
				return;
			}
		}
		++i;
	}

	if (symbols.empty())
		fprintf(stdout, "Balanced symbols. Well done !\n");
	else
		fprintf(stderr, "closing symbol missing for : %c\n", symbols.top());
}


void get_line(char *input_buffer, int limit)
{
	int i = 0;
	char c;
	
	while ( --limit > 0 && (c = getchar()) != '\n' && c != EOF ) {
		if (limit == 1)
			break;
		*(input_buffer + i++) = c;
	} 

	input_buffer[i] = '\x00';
}
