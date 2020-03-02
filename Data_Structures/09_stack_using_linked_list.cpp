#include <iostream>
using namespace std;


struct Stack {
	int data;
	struct Stack *next;
};

struct Stack *top = NULL;


void push(int n)
{
	// Push at beginning to implement stack push
	struct Stack *new_node = (struct Stack *)malloc(sizeof(struct Stack));
	if (new_node == NULL) {
		fprintf(stderr, "%s : in malloc()\n", __FUNCTION__);
		return;
	}

	new_node->data = n;

	// If stack is empty
	if (top == NULL) {
		top = new_node;
		new_node->next = NULL;
		return;
	}	

	// If stack is not empty
	new_node->next = top;
	top = new_node;
}	


void pop()
{	
	if (top == NULL) {
		fprintf(stderr, "%s : stack empty\n", __FUNCTION__);
		return;
	}

	struct Stack *temp = top;
	top = top->next;
	free(temp);
}


void print_stack() 
{
	struct Stack *iter;
	
	cout << "stack : ";
	for ( iter = top; iter != NULL; iter = iter->next) 
		fprintf(stdout, "%d ", iter->data);
	
	cout << "\n";
}

int main()
{
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
	pop();
	print_stack();
	pop();
	print_stack();
	pop();
	print_stack();
}
