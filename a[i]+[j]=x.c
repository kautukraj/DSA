#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int search = 9;
    
    // brute force method
    /*for (int i=0; i<9; i++)
    {
        for (int j=i; j<9; j++)
        {
            if (a[i]+a[j] == search)
                printf("%d %d\n", i, j);
                
        }
    }*/
    
    // sort the array  and total is O(nlogn)
    /*for (int i=0; i<9; i++)
    {
        int l=0; int r=8;
        while (l<=r)
        {
            int mid = (l+r)/2;
            if (search - a[i] == a[mid])
                {
                    printf("%d %d\n", i,mid);
                    break;
                }
            else if (a[mid]<search-a[i])
                l++;
            else
                r--;
        }
    }*/
    
    // assume already sorted
    int l=0; int r=8;
    while(l<=r)
    {
        if (a[l]+a[r] == search)
        {
            printf("%d %d\n",l,r);
            break;
        }
        else if (a[l]+a[r]<search)
            l++;
        else
            r--;
    }
    
    
    
    
    return 0;
}

