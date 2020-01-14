#include <stdio.h>
#include <time.h>
int main()
{
	int arr[1000000000]; // maximum allowed size of array is 2 * 10^6
	// if using malloc then 3 * 10^7 
    int s;
    int n=1000;
    int i,j,k;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            s = 2*s + 1;
        }
    }
    
	printf("%d",s);
    
    
    return 0;
}
