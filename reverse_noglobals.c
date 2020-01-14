#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void reverse_recurse(struct node** head, struct node* temp)
{
    if (temp->next==NULL)
    {
        *head = temp;
        return;
    }
    
    reverse_recurse(head, temp->next);
    struct node* q = temp->next;
    q->next = temp;
    temp->next = NULL;
    
} 

void insertatbeg(struct node** head, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->next = NULL;
    if (*head==NULL)
    *head = newNode;
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
    
}

void print(struct node** head)
{
    struct node* temp = *head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node* head;
    head = NULL;
    struct node* temp = head;
    insertatbeg(&head,1);
    insertatbeg(&head,2);
    insertatbeg(&head,3);
    reverse_recurse(&head,temp);
    print(&head);
    return 0;
}
