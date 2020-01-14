#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next; 
};

void insert_at_beg(struct node**, int);
void print(struct node**);

void print(struct node** head)
{
    struct node* temp = *head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


void insert_at_beg(struct node** head, int data)
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

int main()

{
    char str [] = "101010";
    char search [] = "11";
    int search_as_int = 3;
    int p = 997;
    
    int arr[p][10];
    struct node* array[p];
 
    
    int l_str = strlen(str);
    int l_search = strlen(search);
    int i,j,k,c=0;
    
    for (i=0; i<= l_str - l_search; i++)
    {
        int sum=0;
        for (j=0; j < l_search; j++)
        {
            sum = sum + (str[i+j]-'0') * pow(2,l_search-1-j);
        }
        
        int remainder = sum % p;
        
        insert_at_beg(&array[remainder],i);
        
    }
    
    print(&array[2]);
        
    int rem = search_as_int % p;
    //printf("%d",rem);
    for (i=0;i<10;i++)
    {
        if (arr[rem][0] == -1)
        {
            //printf("No match");
            break;
        }
        
        if (arr[rem][i] != -1) // go to that position and cross check
        {
            int sum=0; int c = l_search - 1; 
            for (j=i;j < i+l_search; j++)
            { sum = sum + (str[j]-'0') * pow(2,c); c--; }
            
            
            //if (search_as_int == sum)
            //printf("Match found at %d\n",i);
            //else
            //printf("No match at %d\n",i);
        }
        
    }
        
        
    
    return 0;
    
}
