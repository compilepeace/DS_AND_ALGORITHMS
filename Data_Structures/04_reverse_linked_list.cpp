#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
};

static struct Node *head;


void reverse_list();
void insert_node(int , unsigned int );
void print_list();


int main()
{
    head = NULL;

    insert_node(9, 1);      // [9]
    insert_node(5, 2);      // [9, 5]
    reverse_list();
	insert_node(7, 3);      // [9 , 5, 7]
    insert_node(4, 2);      // [9, 4, 5, 7]

	reverse_list();
}


void reverse_list()
{
	struct Node *ptr = NULL, *link = NULL;

	// Only one element is the list
	if (head->next == NULL){
		print_list();
		return;
	}

	ptr = head->next;
	
	// For 2 elements in a list
	if (ptr->next == NULL){
		ptr->next = head;
		head->next = NULL;
		head = ptr;
		print_list();
		return;
	}

	link = ptr->next;
	head->next = NULL;

	do
	{
		ptr->next = head;
		head = ptr;
		ptr = link;
	
		if (link != NULL)
			link = link->next;

	} while ( ptr != NULL);


	cout << "After reversing : ";
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
        fprintf(stdout, "%d ", (*iter).data);

    printf("\n");
}

