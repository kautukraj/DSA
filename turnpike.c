#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
};
struct node *head = NULL;
struct node *current = NULL;
struct node *prev = NULL;

int ABS(int);
int FindMax(struct node*);
void Insert(struct node*, int);
void Delete(struct node*, int);
int Search(struct node*, int);
bool ProAss1(int*, struct node*, int);
bool Try(int*, struct node*, int, int, int);
bool Possible(int*, int, struct node*, int, int, int);
int length(struct node*);



int ABS(int x)
{
    return abs(x);
}

int FindMax(struct node* head)
{
    struct node* temp = head;
    int max=head->data;
    while (temp!=NULL)
    {
        if (temp->data>max)
            max = temp->data;
        temp = temp->next;    
    }
}

void Insert(struct node* head, int data) 
{
   // Allocate memory for new node;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->data = data;
   link->next = NULL;

   // If head is empty, create new list
   if(head==NULL) 
   {
      head = link;
      return;
   }

   current = head;
   
   // move to the end of the list
   while(current->next!=NULL)
      current = current->next;
   
   // Insert link at the end of the list
   current->next = link; 
}



void Delete(struct node* head, int data) 
{
   int pos = 0;
   
   if(head==NULL) 
   {
      printf("Linked List not initialized");
      return;
   } 
    
   if(head->data == data) 
   {
      if(head->next != NULL) 
      {
         head = head->next;
         return;
      } else 
      {
         head = NULL;
         printf("List is empty now");
         return;
      }
   } 
   else if(head->data != data && head->next == NULL) 
   {
      printf("%d not found in the list\n", data);
      return;
   }

   //prev = head;
   current = head;
   
   while(current->next != NULL && current->data != data) 
   {
      prev = current;
      current = current->next;
   }        

   if(current->data == data) 
   {
      prev->next = prev->next->next;
      free(current);
   } else
      printf("%d not found in the list.", data);
}



int Search(struct node* head, int data)
{
    struct node* temp = head;
    while (temp!=NULL)
    {
        if (temp->data == data)
            return 1;
    }
    return 0;
    
}

int length(struct node* head)
{
    struct node* temp = head;
    int count = 0;
    while (temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    
    return count;
}

bool ProAss1(int* X, struct node* D, int n)
{
    X[0] = 0;
    X[n - 1] = FindMax(D);
    Delete(D, FindMax(D));
    X[n - 2] = FindMax(D);
    Delete(D, FindMax(D));
    if (Search(D,X[n-1]-X[n-2]))
    {
        Delete(D, X[n - 1] - X[n - 2]);
        return Try(X, D, n, 1, n - 3);
    }
    else
        return false;
}


bool Try(int* X, struct node* D, int n, int left, int right)
{
    int max;
    bool found = false;
    if (length(D)==0)
        return true;
    max = FindMax(D);
    if (Possible(X, n, D, max, left, right))
    {
        X[right] = max;
        for (int i = 0; i < left; ++i)
            Delete(D, ABS(X[i] - X[right]));
        for (int i = right + 1; i < n; ++i)
            Delete(D, ABS(X[i] - X[right]));
        found = Try(X, D, n, left, right - 1);
        if (found == false)
        {
            for (int i = 0; i < left; ++i)
                Insert(D, ABS(X[i] - X[right]));
            for (int i = right + 1; i < n; ++i)
                Insert(D, ABS(X[i] - X[right]));
        }
    }
    if (Possible(X, n, D, X[n - 1] - max, left, right) && found == false)
    {
        X[left] = X[n - 1] - max;
        for (int i = 0; i < left; ++i)
            Delete(D, ABS(X[i] - X[left]));
        for (int i = right + 1; i < n; ++i)
            Delete(D, ABS(X[i] - X[left]));
        found = Try(X, D, n, left + 1, right);
        if (found == false)
        {
            for (int i = 0; i < left; ++i)
                Insert(D, ABS(X[i] - X[left]));
            for (int i = right + 1; i < n; ++i)
                Insert(D, ABS(X[i] - X[left]));
        }
    }
    return found;
}

bool Possible(int *X, int n, struct node* D, int max, int left, int right)
{
    for (int i=0; i<left-1; i++)
    {
        if (Search(head, ABS((X[i]-max))) == true)
        continue;
        else
        return false;
    }
    
    for (int i=right+1; i<n; i++)
    {
        if (Search(head, ABS((X[i]-max))) == true)
        continue;
        else
        return false;
    }
    
    return false;
}


 int main()
 {
     Insert(head, 1);
     Insert(head, 1);
     Insert(head, 1);
     Insert(head, 2);
     Insert(head, 2);
     Insert(head, 3);
     int arr[4];
     bool f = ProAss1(arr,head,4);
     return 0;
 }
