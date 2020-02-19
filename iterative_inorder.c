#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node* newNode(int); 
void inorder(struct node*);

struct node  
{ 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
  
void inorder(struct node* node)
{
    int top;
    struct node* stack[100];
    bool B[100];
    if (node!=NULL)
    {
        top = -1;
        stack[++top] = node;
        B[top] = false;
        while (top>=0)
        {
            if (B[top] == true)
            printf("%d ",(stack[top--])->data);
            else
            {
                node = stack[top--];
                if (node->right)
                {
                    stack[++top] = node->right;
                    B[top] = false;
                }
                
                stack[++top] = node;
                B[top] = true;
                
                if (node->left)
                {
                    stack[++top] = node->left;
                    B[top] = false;
                }
            }
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
  inorder(root);
 
  return 0; 
}
