#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};


void insert_node(struct Node *, int );

int main()
{
	struct Node *root_ptr = NULL;			// Trees will be known by their root node

	insert_node(root_ptr, 15);
	insert_node(root_ptr, 10);

}


void insert_node(struct Node *root, int n)
{
	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));

	if (new_node == NULL) {
		fprintf(stderr, "%s: malloc()\n", __FUNCTION__);
		exit(0x10);
	}

	// If this is the first node to be inserted
	if (root == NULL) {
		new_node->data = n;
		new_node->left = NULL;
		new_node->right = NULL;
		return;
	}

}
