#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head;

void insertatbeg(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->next = NULL;
    if (head==NULL)
    head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
    
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

int floyd()
{
    struct node* p1 = head;
    struct node* p2 = head;
    while (p2!=NULL)
    {
        p1 = p1->next;
        p2 = p2->next;
        if (p2!=NULL)
            p2 = p2->next;
        else
            return 0;
        if (p1==p2)
            return 1;
    }
    return 0;
}

int main()
{
    head = NULL;
    insertatbeg(10);
    insertatbeg(5);
    insertatbeg(1);
    insertatbeg(0);
    /*struct node* temp1 = head;
    while (temp1->next->next!=NULL)
        temp1 = temp1->next;
    struct node* temp2 = temp1->next;
    temp2->next = temp1;*/
    int f = floyd();
    printf("%d", f);
    
    
    return 0;
}
