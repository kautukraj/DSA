#include <stdio.h>
#include <string.h>
int main()
{
    char num1 [] = "123";
    char num2 [] = "12";
    int len1 = strlen(num1);
	int len2 = strlen(num2); 
    //printf("%d %d\n", len1,len2);
	int result[len1+len2];
	int i_n1 = 0; 
	int i_n2 = 0; 
    int i,j,carry=0,n1,n2,sum=0;
    
    for (i=0;i<(len1+len2);i++)
        result[i]=0;
        
	for (i=len1-1; i>=0; i--) 
	{ 
		n1 = num1[i] - '0'; 
		printf("Value of n1 = %d\n",n1);
		i_n2 = 0; 
			 
		for (j=len2-1; j>=0; j--) 
		{ 

			n2 = num2[j] - '0'; 
			printf("Value of n2 = %d\n",n2);
			sum = n1*n2 + result[i_n1 + i_n2] + carry; 
			printf("Value of sum = %d\n",sum);
			carry = sum/10; 
			result[i_n1 + i_n2] = sum % 10; 
			printf("Value stored at %dth position is %d\n",(i_n1+i_n2),result[i_n1+i_n2]);
            //printf("%d ",result[i_n1+i_n2]);
			i_n2++; 
		} 
 
		if (carry > 0) 
			result[i_n1 + i_n2] += carry; // +=

		i_n1++; 
	}
	
}


