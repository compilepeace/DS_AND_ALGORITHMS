#include <iostream>



struct Node
{
	int data;
	struct Node *next;
};


// Variables
static struct Node *head = NULL;
static int init_list     = 0;
static unsigned int count_nodes = 0;


struct Node *create_node()
{
	// Allocate memory for a linked list on heap segment
	struct Node *ptr = (struct Node *) malloc(sizeof(struct Node ));

		if (ptr == NULL)
		{
			fprintf(stderr, "%s: malloc()\n", __FUNCTION__);
			exit(0x1);
		}

	return ptr;
}


void add_node(int n)
{

	// Create a new node
	struct Node *iter, *temp = create_node();
	++count_nodes;
	(*temp).data = n;


	// If this is the first node to be inserted
	if (count_nodes == 1)
	{
		(*temp).next = NULL;
		head = temp;
		return;	
	}

	else
	{
		// Parse the linked list and push the new node after the last node
		for (iter = head; iter->next != NULL ; iter = iter->next);
		iter->next = temp;
		temp->next = NULL;
	}
}


void print_list()
{
	struct Node *iter = head;

	for (; iter != NULL; iter = iter->next)
		fprintf(stdout, "parsing %d node\n", iter->data);
}

int main()
{

	// Initialize the list as empty
	head = NULL;

	struct Node *temp = create_node();

	add_node(10);
	add_node(20);
	add_node(30);
	add_node(40);
	add_node(50);
	add_node(60);

	print_list();
}

