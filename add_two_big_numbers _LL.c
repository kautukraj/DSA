#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* head1;
struct node* head2;
struct node* result;

// reverse a linked list
/*void reverse(struct node** p)
{
    if (*p->next==NULL)
    {
         = p;
        return;
    }
    reverse(*p->next);
    struct node* q = *p->next;
    q->next = *p;
    *p->next = NULL;
    
}*/


void insert_at_pos(struct node** head, int data, int n)
{
    struct node* temp1=(struct node*)malloc(sizeof(struct node*));
    int i;
    temp1->data=data;
    temp1->next=NULL;
    if(n==1)//empty list
    {
        temp1->next=*head;
        *head=temp1;
        return;
    }
    struct node* temp2= *head;
    for(i=0;i<n-2;i++)
    temp2=temp2->next;
    
    temp1->next=temp2->next;
    temp2->next=temp1;
}


int find_pthelement(struct node** head, int p)
{
    struct node* temp = *head;
    for (int i=1;i<=p-1;i++)
        temp = temp->next;
        
    return (temp->data);
    
}


void insert_at_beg(int data, struct node** head)
{
    struct node* temp = malloc (sizeof(struct node*));
    temp->data = data;
    temp->next = NULL;
    if (*head==NULL) // empty list
    *head = temp;
    else
    {
        temp->next = *head;
        *head = temp;
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
    head1 = NULL; head2 = NULL; result = NULL;
    int i,carry=0;
    for (i=1; i<=5;i++)
    {
        insert_at_beg(i,&head1);
        insert_at_beg(i,&head2);
    }
 
    //reverse(&head1);
    //reverse(&head2);
    struct node* temp = head1;
    
    for (i=1;i<=5;i++)
    {
        int d1 = find_pthelement(&head1,i);
        int d2 = find_pthelement(&head2,i);
        carry = carry + d1 + d2; // find node
        insert_at_pos(&result,carry % 10,i); // insert node
        carry = carry / 10;
        
    }
    insert_at_pos(&result,carry,i); // insert node
    print(&result);
    return 0;
}
