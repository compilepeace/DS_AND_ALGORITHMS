#include <iostream>
using namespace std;


struct Node 
{
	struct Node *prev;
	int data;
	struct Node *next;
};


struct Node *head_ptr;

void insert_node(int , int );
void delete_node(int position);
void print_list();
void print_reverse_list(struct Node *);


int main()
{
	head_ptr = NULL;			// Initializing head pointer before inserting any node
	
	insert_node(9, 1);      // [9]
    insert_node(5, 2);      // [9, 5]
    insert_node(7, 3);      // [9 , 5, 7]
    insert_node(4, 2);      // [9, 4, 5, 7]
	insert_node(1, 1);		// [1, 9, 4, 5, 7]

	print_reverse_list(head_ptr);

	delete_node(1);
	delete_node(4);
	delete_node(2);
	delete_node(2);
}

void insert_node(int n, int position)
{
	struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
	
	if (temp == NULL){
		fprintf(stderr, "%s in malloc()\n", __FUNCTION__);
		exit(0x2);
	}

	temp->data = n;

	// set links
	// Insert at head
	if (position == 1) {
		if (head_ptr == NULL) {				// This is the first node to be inserted
			head_ptr = temp;
			head_ptr->prev = NULL;
			head_ptr->next = NULL;
			print_list();
			return;
		}
		else {								// Insert the node in a filled linked list at head
			temp->next = head_ptr;
			temp->prev = NULL;
			head_ptr->prev = temp;
			head_ptr = temp;
			print_list();
			return;
		}
	}

	if (head_ptr == NULL && position != 1) {
    	fprintf(stdout, "%s : List is empty, %d is not a valid position\n", __FUNCTION__, position);
    	return;
	}

	struct Node *iter = head_ptr;
	int count = 0;
	for (int i = 0; i < (position-2) ; ++i) {
		if (iter != NULL){ 
			iter = iter->next;
			++count;
		}
	}

	// Exit if invalid position
	if (count != position-2){
		fprintf(stderr, "%s : Position not valid %d - %d\n", __FUNCTION__, count, position-2);
		return;
	}	

	// If there is only one node in the list
	if (iter == head_ptr && head_ptr->next == NULL){
		iter->next = temp;
		temp->next = NULL;
		temp->prev = iter;
		print_list();
		return;
	}

	// If pushing to the end of list
	if (iter->next == NULL){
		iter->next = temp;
		temp->prev = iter;
		temp->next = NULL;	
		print_list();
		return;
	}

	// If inserting in between
	if (iter->next != NULL){
		temp->next = iter->next;
		temp->prev = iter;
		iter->next = temp;
		temp->next->prev = temp;
		print_list();
		return;
	}
}

void delete_node(int position)
{
	struct Node *temp = head_ptr;

	// If list is empty
	if (head_ptr == NULL) {
		fprintf(stdout, "%s : No node to delete in the list\n", __FUNCTION__);
		return;
	}

	// delete the first(head) node
	if (position == 1) {
		// list with only 1 element or list with more than 1 element
		head_ptr = head_ptr->next;
		if (head_ptr != NULL) head_ptr->prev = NULL;
		free(temp);  
		print_list();
		return;
	}

	// delete a node from the middle of the linked list
	for (int i = 0; i < (position - 1); ++i) {
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	if (temp->next != NULL) temp->next->prev = temp->prev;	
	free(temp);
	
	print_list();
}

void print_list()
{
	struct Node *iter;

	for (iter = head_ptr; iter != NULL ; iter = iter->next)
		fprintf(stdout, "%d ",  iter->data);
	cout << "\n";
}


// This ensures that the previous pointers are set properly
void print_reverse_list(struct Node *iter)
{
	// Reaching the end of linked list
	while (iter->next != NULL) {
		iter = iter->next;
	}	

	cout << "Reverse linked list : ";
	while (iter != NULL) {
		fprintf(stdout, "%d ", iter->data);
		iter = iter->prev;
	}
	cout << "\n";
}
