#include <stdio.h>
#include <stdlib.h>

int i,n,val;
void swap (int*, int*);
int partition (int [],int,int,int); 
void quickSort (int [],int,int);


void swap(int * a, int * b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition(int a[], int i, int j, int pivot)
{
    int l = i; int r = j;
    while(l<=r)
    {
        while (l<=r && a[l]<=pivot)
            l++;
        while (l<=r && a[r]>pivot)
            r--;
            
        if (l<=r)
        {
            swap(&a[l],&a[r]);
            l++; r--;
        }
    }  
    
    int k = l-1;    
    a[i-1] = a[k];
    a[k] = pivot;
        
    return k;    
}


void quickSort(int a[], int i, int j)
{
    if (i < j) 
    {
        int p = (rand()%(j-i+1)) + i;
        swap(&a[i],&a[p]);
        int k = partition(a,i+1,j,a[i]);
        quickSort(a, i, k-1); 
        quickSort(a, k + 1, j); 
    }
}

int main()
{
    int n;
    scanf("%d\n",&n);
    int a[n];
    for (i=0;i<n;i++)
    scanf("%d ",&a[i]);
    quickSort(a, 0, n - 1);

    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
        
    return 0;
}
