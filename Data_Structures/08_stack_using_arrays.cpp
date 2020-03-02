#include <iostream>
using namespace std;

#define MAX 10000


static long long int stack[MAX];
static int top;

void push(long long int );
long long int pop();
int IsEmpty();
void print_stack();


int main()
{
	top = -1;

	push(1);
	print_stack();
	push(2);
	print_stack();
	push(3);	
	print_stack();
	push(4);
	print_stack();
	push(5);
	print_stack();
	
	pop();
	print_stack();
	pop();
	print_stack();

	int return_value = IsEmpty();
	if (return_value == 1)
		printf("Empty stack\n");
	else
		printf("Stack not empty\n");	
}


void push(long long int val)
{
	if (top == MAX) 	{
		fprintf(stdout, "%s stack overflow\n", __FUNCTION__);
		return;
	}
	++top;
	stack[top] = val;
}

long long int pop()
{
	if (top == -1){
		fprintf(stdout, "Stack empty\n", __FUNCTION__);
		return;
	}
	return stack[top--]; 
}

int IsEmpty()
{
	return (top == -1)? 1 : 0 ;
}

void print_stack()
{
	cout << "Stack : ";
	for(int i=0 ; i <= top; ++i)
		printf("%lld ", stack[i]);
	cout << "\n";
}
