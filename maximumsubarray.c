#include <stdio.h>

int maxSubArraySum(int a[], int size) 
{ 
	int max = -9999, sum = 0, 
	start =0, end = 0, s=0; 

	for (int i=0; i< size; i++ ) 
	{ 
		sum += a[i]; 

		if (sum>max) 
		{ 
			max = sum; 
			start = s; 
			end = i; 
		} 

		if (sum < 0) 
		{ 
			sum = 0; 
			s = i + 1; 
		} 
	} 
	printf("%d at %d %d\n",max,start,end); 
} 

/*Driver program to test maxSubArraySum*/
int main() 
{ 
	int a[] = {-2, -3, -4, -1, -2, -1, -5, -3}; 
	int n = sizeof(a)/sizeof(a[0]); 
	int max_sum = maxSubArraySum(a, n); 
	return 0; 
} 

