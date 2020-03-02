#include <iostream>
#include <string.h>
#include <stack>
#include <ctype.h>

using namespace std;

#define MAX_SIZE 10000

void get_line(char *, int );
void postfix_evaluation(char *);
int perform_operation(int , int , char );
int isOperator(char );

int main()
{
	char input_buffer[MAX_SIZE];
	cout << "Enter a postfix string : ";
	get_line(input_buffer, MAX_SIZE);

	printf("%s : Calling postfix_evaluation(\"%s\")\n", __FUNCTION__, input_buffer); 

	postfix_evaluation(input_buffer);
}


int isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*'); 
}

int perform_operation(int num1, int num2, char c)
{
	switch(c)
	{
		case '+': return (num1 + num2);
		case '-': return (num1 - num2);
		case '*': return (num1 * num2);
		case '/': return (num1 / num2);
		default : return -1;
	}
	
}

void postfix_evaluation(char *postfix_input)
{
	stack<int> container;
	int operand1, operand2;

	cout << "\n";
	// Parse the postfix_input string
	for (int i = 0; i < strlen(postfix_input) ; ++i) {

		// If an operand (number) is encountered, push it onto the stack 
		// and continue scanning next character	
		if ( isdigit(postfix_input[i]) ) {
			cout << "[+] Pushing : " << postfix_input[i] - '0' << endl;
			container.push(postfix_input[i] - '0');
			continue;
		}

		// If an operator is encountered
		else if ( isOperator(postfix_input[i]) )
		{
			operand2 = container.top();
			container.pop();
			operand1 = container.top();
			container.pop();
			
			int result = perform_operation(operand1, operand2, postfix_input[i]);
			container.push(result);
			cout << "[+] Pushed " << result << "\n\n";
			cout << "Top of stack contains : " << container.top() << endl;
		}	

		else {
			fprintf(stderr, "%s: Invalid postfix_input -> %s\n", __FUNCTION__, postfix_input);
			return;
		}
	}

	cout << "Result : " << container.top() << endl;
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

