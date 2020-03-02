#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};


static struct Node *head;


void push_node(int );
void push_node_at_head(int );
void print_list();


int main()
{
	head = NULL;
	

	int i, n;
	unsigned int mid;

	// Getting a list as input from the user
	cout << "How many numbers do you intend to enter ? ";
	scanf("%d", &n);
	int user_data[n];
	
	for (i=0; i < n ; ++i)
		scanf("%d", &user_data[i]);

	mid = n/2;
	
	for (i = 0; i < mid ; ++i)
		push_node(user_data[i]);

	for (i = mid; i < n ; ++i)
		push_node_at_head(user_data[i]);
	
	cout << "final list : ";
	print_list();
}


void push_node(int n)
{

	struct Node *iter;
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	(*temp).data = n;
	(*temp).next = NULL;

	// pushing in case list is empty
	if (head == NULL)
	{
		head = temp;
		temp->next = NULL;
	}

	// when list is not empty, parse the list to push element at the end
	else
	{	
		iter = head;
		while(iter->next != NULL)
			iter = iter->next;
		
		// Now iter points to the last element
		iter->next = temp;	
	}

	fprintf(stdout, "[%s] ", __FUNCTION__);
	print_list();
}


void push_node_at_head(int n)
{
	struct Node *iter;
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	
	if (temp == NULL)
	{
		fprintf(stderr, "%s in malloc()\n", __FUNCTION__);
		exit(0x3);
	}

	(*temp).data = n;
	(*temp).next = head;
	head = temp;

	fprintf(stdout, "[%s] ", __FUNCTION__);
	print_list();
}


void print_list()
{
	struct Node *iter = head;
	fprintf(stdout, "List : ");
	for ( ; iter != NULL; iter = iter->next)
	{
		fprintf(stdout, "%d ", iter->data);
	}

	printf("\n");
}


