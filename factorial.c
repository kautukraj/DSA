#include <stdio.h>
#include <time.h>

void factorial(int);
int multiply(int,int[],int);

void factorial(int n) 
{ 
	int res[10000]; 
 	int x,i;
	res[0] = 1; 
	int res_size = 1; 
	
	for (x=2; x<=n; x++) 
		res_size = multiply(x, res, res_size); 

	for (i=res_size-1; i>=0; i--) 
		printf("%d",res[i]); 
} 

int multiply(int x, int res[], int res_size) 
{ 
	int carry = 0; 
    int i;
    for (i=0; i<res_size; i++) 
	{ 
		int prod = res[i] * x + carry; 

		res[i] = prod % 10;
		carry = prod/10;	 
	} 

	while (carry!=0) 
	{ 
		res[res_size] = carry%10; 
		carry = carry/10; 
		res_size++; 
	} 
	return res_size; 
} 

// Driver program 
int main() 
{ 
	clock_t t; 
    t = clock(); 
    int a = 3000;
    factorial(a); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nfactorial() took %f seconds to execute %d!\n", time_taken,a); 
} 

