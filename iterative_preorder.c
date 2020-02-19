#include <stdio.h>
#include <stdlib.h>

struct node* newNode(int); 
void preorder(struct node*);

struct node  
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
void preorder(struct node* node)
{
    int top;
    struct node* stack[100]; // [number of nodes]
    if (node!=NULL)
    {
        top = -1;
        stack[++top] = node;
        while (top>=0)
        {
            printf("%d ",stack[top]->data);
            node = stack[top--];
            if (node->right)
                stack[++top] = node->right;
            if (node->left)
                stack[++top] = node->left;    
        }
        
    }
}


struct node* newNode(int data) 
{ 
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 
  
  
int main() 
{ 
  struct node *root = newNode(1);   
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  preorder(root);
 
  return 0; 
}
