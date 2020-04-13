#include <iostream>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
};

static struct Node *head;


void insert_node(int , unsigned int );
void print_reverse_list(struct Node *);
void print_list();

int main()
{
    head = NULL;
    
    insert_node(9, 1);      // [9]
    insert_node(5, 2);      // [9, 5]
    insert_node(7, 3);      // [9 , 5, 7]
    insert_node(4, 2);      // [9, 4, 5, 7]

	cout << "Reverse List : ";
	print_reverse_list(head);
	cout << "\n";
}


void print_reverse_list(struct Node *iter)
{
	// Last element in the list
	if (iter == NULL) return;

	// recursively call this function until the last element of the list is encountered
	print_reverse_list(iter->next);
	printf("%d ", iter->data);
	return;
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

	cout << "List : ";
	for (iter = head; iter != NULL; iter = iter->next)
		fprintf(stdout, "%d ", iter->data);

	cout << "\n";
}
