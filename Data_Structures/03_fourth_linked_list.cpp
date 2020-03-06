#include <iostream>
using namespace std;

struct Node 
{
	int data;
	struct Node *next;
};


static struct Node *head;


void delete_node(int );
void insert_node(int , unsigned int );
void print_list();


int main()
{
    head = NULL;

    insert_node(9, 1);      // [9]
    insert_node(5, 2);      // [9, 5]
    insert_node(7, 3);      // [9 , 5, 7]
    insert_node(4, 2);      // [9, 4, 5, 7]

	delete_node(3);			// [9, 4, 7]
	delete_node(1);			// [4, 7]
	delete_node(2);			// [4]
	delete_node(2);			// segmentation fault
}

void delete_node(int position)
{
	struct Node *iter, *temp;	
	
	if (position == 1)
	{
		temp = head->next;
		free(head);
		head = temp;
		print_list();
		return;
	}	
	
	iter = head;
	// logic starts here
	for (int i=1; i< position-1; ++i)
	{
		if (iter == NULL)
		{
			fprintf(stdout, "Try another position\n");
			exit(0x3);
		}
		iter = iter->next;
	}

	if (iter->next == NULL)
	{
		head = NULL;
		
	}
	temp = iter->next->next;
	free(iter->next);
	iter->next = temp;


	print_list();
}


void insert_node(int n, unsigned int position)
{
    struct Node *iter, *temp = (struct Node *) malloc(sizeof(struct Node ));
    unsigned int i;

    // Checking malloc's return value
    if (temp == NULL)
    {
        fprintf(stdout, "%s in malloc()\n", __FUNCTION__);
        exit(0x2);
    }

    temp->data = n;

    if (head == NULL || position == 1)
    {
        temp->next = head;
        head = temp;
        print_list();
        return;
    }


    // Logic starts here
    // loop iterates till the previous element corresponding to the index (position-1) to be inserted at
    for (i=0, iter=head ; i < position - 2; ++i)
    {
        iter = iter->next;
    }
    temp->next = iter->next;
    iter->next = temp;

    print_list();
}


void print_list()
{
	struct Node *iter;

	for (iter = head; iter != NULL; iter = iter->next)
		fprintf(stdout, "%d ", iter->data);
	printf("\n");
}
