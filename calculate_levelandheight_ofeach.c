// C program for different tree traversals 
#include <stdio.h> 
#include <stdlib.h> 
#define MAX(x, y) (x > y ? x : y)
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	int level;
	int height;
	struct node* left; 
	struct node* right; 
	struct node* parent;
}; 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newNode(int data, struct node* parent) 
{ 
	struct node* node = (struct node*) 
								malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL;
	node->parent = parent;

	return(node); 
} 

/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 
		
	if (node->left == NULL && node->right == NULL)	
	    node->height = 0;
	else
	    node->height = 1 + MAX(node->left->height, node->right->height);

	// first recur on left subtree 
	printPostorder(node->left); 

	// then recur on right subtree 
	printPostorder(node->right); 

	// now deal with the node 
	printf("Height of %d is %d\n", node->data, node->height); 
} 



/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 

	if (node->parent == NULL) 
	    node->level = 0;
	else
	    node->level = 1 + (node->parent)->level;
	
	printf("Level of %d is %d\n", node->data, node->level);    

	/* then recur on left sutree */
	printPreorder(node->left); 

	/* now recur on right subtree */
	printPreorder(node->right); 
}	 

/* Driver program to test above functions*/
int main() 
{ 
	struct node *root = newNode(1, NULL); 
	root->left			 = newNode(2, root); 
	root->right		 = newNode(3, root); 
	root->left->left	 = newNode(4, root->left); 
	root->left->right = newNode(5, root->left); 


	printPreorder(root); 

	printPostorder(root); 

	getchar(); 
	return 0; 
} 

