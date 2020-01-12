#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head;


void print()
{
    struct node* temp = head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

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

void insertatn(int data, int n)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->next = NULL;
    struct node* temp = head;
    if (temp==NULL)
    insertatbeg(data);
    else
    {
        if (n==1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        for (int i=0; i<n-2; i++)
        temp = temp->next;
    
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
}

void insertatend(int data)
{
    if (head == NULL)
    {
        insertatbeg(data);
        return;
    }
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->next = NULL;
    struct node* temp = head;
    
    while (temp->next != NULL)
    temp = temp->next;
    
    temp->next = newNode;
    
}

void deleteatbeg()
{
    if (head==NULL)
    {
        printf("List is already empty");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}

void deleteatn(int n)
{
    struct node* temp = head;
    if (n==1)
    {
        deleteatbeg();
        return;
    }
    
    for (int i=1; i<=n-2; i++)
    temp = temp->next;
    
    struct node* myNode = temp->next;
    temp->next = myNode->next;
    free(myNode);
}

void deleteatend()
{
    if (head==NULL)
    {
        printf("List is already empty");
        return;
    }
    
    struct node* temp = head;
    while (temp->next->next!=NULL)
    temp = temp->next;
    
    struct node* myNode = temp->next;
    temp->next = NULL;
    free(myNode);
    
}

void print_recurse(struct node* head)
{
    if (head==NULL)
    return;
    
    printf("%d ",head->data);
    print_recurse(head->next);
    
}

void reverseprint_recurse(struct node* head)
{
    if (head==NULL)
    return;
    
    reverseprint_recurse(head->next);
    printf("%d ",head->data);
    
}

void reverse_recurse(struct node* p)
{
    if (p->next==NULL)
    {
        head = p;
        return;
    }
    
    reverse_recurse(p->next);
    struct node* q = p->next;
    q->next = p;
    p->next = NULL;
    
}


int main()
{
    head = NULL;
    insertatbeg(10);
    insertatbeg(100);
    insertatn(200,1);
    insertatend(1);
    //deleteatbeg();
    //deleteatn(2);
    //deleteatend();
    //print();
    struct node* temp = head;
    //reverseprint_recurse(temp);
    reverse_recurse(temp);
    print();
    
    
    return 0;
}
