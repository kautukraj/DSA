#include <stdio.h>
#include <time.h>
int main()
{
	// program to find the computation speed of a computer 
	int n = 1000; int s = 5; // s can be anything and finally converges to -1
    int i,j,k;
    clock_t t; 
    t = clock(); 
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            s = 2*s + 1; // 10^n * 3 number of computations
        }
    }
    
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("Time taken %lf\n",time_taken);
    printf("%d",s); // finally -1
    
    
    
    return 0;
}
