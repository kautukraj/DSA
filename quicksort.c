#include <stdio.h>
int i,n,val;
void swap (int*, int*);
int partition (int [],int,int); 
void quickSort (int [],int,int);
void printArray (int[],int);


void swap(int * a, int * b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int a[], int f, int r)
{
    int pivot = a[r]; 
    int i = f; 
    int j;
    for (j = f; j < r; j++)
    {
        if (a[j] <= pivot) 
        {
            swap(&a[i], &a[j]); 
            i++;
        }
    }
    swap(&a[i], &a[r]); 
    return i; 
}

/*int randompartition(int a[],int f, int r)
{
    int pivotIndex = (rand() % (f - r + 1)) + r;
    swap(&a[pivotIndex],&a[r]);
    return partition(a,f,r);
    
}*/

void quickSort(int a[], int f, int r)
{
    if (f < r) 
    {
        int mid = partition(a, f, r);
        quickSort(a, f, mid-1); 
        quickSort(a, mid + 1, r); 
    }
}


void printArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
}


int main()
{
    scanf("%d",&n);
    int a[n];
    for (i=0;i<n;i++)
    scanf("%d,",&a[i]);
    quickSort(a, 0, n - 1);
    printArray(a,n);
    return 0;
}
