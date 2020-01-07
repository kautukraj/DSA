#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

struct node {
    	int data;
    	struct node* next;
};


struct node* head;
void factorial(int);
int multiply(int,struct node*,int);
void reversePrint (struct node*);
int findith_element(struct node*, int);
void insert_at_i(struct node*, int, int);


void insert_at_i(struct node* head, int value, int i)
{
	struct node* temp1 = (struct node*) malloc (sizeof(struct node*));
	temp1->data = value;
	temp1->next = NULL;
	
	if (i==1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	struct node* temp2 = head;

	for (int j=0;j<i-2;j++)
	temp2 = temp2->next;	

	temp1->next = temp2->next;
	temp2->next = temp1;

}


int findith_element(struct node* head, int i)
{
	int count = 0;
	struct node* temp = head;
	for (int j = 1; j<=i-1; j++)
	temp = temp->next;

	return (temp->data); 
}


void reversePrint (struct node* head)
{
	if (head==NULL)
	return;
	
	reversePrint(head->next);
	printf("%d", head->data);
}

void factorial(int n) 
{ 
 	int x,i;
	head = NULL;
	struct node* newNode = (struct node*) malloc (sizeof(struct node*));
	newNode->data = 1;
	newNode->next = NULL;
	// assign result[0] = 1 
	int res_size = 1; 
	
	for (x=2; x<=n; x++) 
		res_size = multiply(x, head, res_size); 

	reversePrint(head);
	
} 

int multiply(int x, struct node* head, int res_size) 
{ 
    int carry = 0; 
    int i;
    for (i=1; i<=res_size; i++) // initially was (i=0; i<res_size; i++) 
	{ 
		//int ith_element = findith_element(head,i);
		//printf("%d",ith_element);		
		//int prod = ith_element * x + carry; // res[i]

		//int val = prod % 10; // res[i]; insert at ith position
		//insert_at_i(head,val,i);
		//carry = prod/10;	 
	} 

	while (carry!=0) 
	{ 
		//int val1 = carry%10; // insert at res_size th position
		//insert_at_i(head, val1, res_size); 
		//carry = carry/10; 
		//res_size++; 
	} 
	//return res_size; 
} 


int main() 
{ 
    clock_t t; 
    t = clock(); 
    int a = 18;
    factorial(a); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nfactorial() took %f seconds to execute %d!\n", time_taken,a); 
} 
