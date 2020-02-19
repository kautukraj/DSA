#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head;

void insertatbeg(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) // list is empty
    {
        head = newNode;
        return;
    }
    
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}


void print()
{
    struct node* temp = head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void reverse_print()
{
    struct node* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
        
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
}

int main()
{
    head = NULL;
    insertatbeg(10);
    insertatbeg(100);
    print();
    //reverse_print();
    return 0;
}
