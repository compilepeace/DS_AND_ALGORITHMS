#include <iostream>
using namespace std;

// Queue itself is implemented mostly via linked list
struct Queue {
	int data;
	struct Queue *next;
};


struct Queue *front, *rear;

void EnQueue(int );
void DeQueue();
int IsEmpty();
int Peek();
void print_list();


int main()
{
	// Initially when the Q is empty
	front = rear = NULL;

	printf("IsEmpty() returned : %d\n", IsEmpty());		
	EnQueue(1);		// [1]
	EnQueue(7);		// [1, 7]
	EnQueue(8);		// [1, 7, 8]
	EnQueue(9);		// [1, 7, 8, 9]

	DeQueue();		// [7, 8, 9]
	printf("IsEmpty() returned : %d\n", IsEmpty()); 
	
	Peek();			// 7
	DeQueue();
	DeQueue();
	DeQueue();
	DeQueue();
}

// Push the element at the rear end
void EnQueue(int n)
{
	struct Queue *new_node = (struct Queue *) malloc(sizeof(struct Queue));

	if (new_node == NULL) {
		fprintf(stderr, "%s : malloc()\n", __FUNCTION__ );
		return;
	}

	(*new_node).data = n;

	// Insert the new_node after the last element
	if (front == NULL && rear == NULL) {
		front = rear = new_node;
		print_list();
		return;
	}
	
	rear->next = new_node;
	new_node->next = NULL;
	rear = new_node;
	print_list();
}


void DeQueue()
{
	struct Queue *temp = front;

	// If the Queue is empty
	if (front == NULL && rear == NULL) {
		fprintf(stderr, "%s : Queue is empty, i.e. NO DeQueue()\n", __FUNCTION__);
		return;
	}

	// If there is only one node
	if (front == rear) {
		temp = front;
		front = rear = NULL;
		free(temp);
		return;
	}

	front = front->next;
	free(temp);
	print_list();
}


int IsEmpty()
{
	return (front == NULL) ? 1 : 0 ;
}


// Returns -1 if the list is empty
int Peek()
{
	return (front == NULL) ? -1 : front->data;
}

void print_list()
{
	struct Queue *iter;

	cout << "List : ";
	for (iter = front; iter != NULL ; iter = iter->next)
		fprintf(stdout, "%d ", iter->data);
	cout << endl;
}
