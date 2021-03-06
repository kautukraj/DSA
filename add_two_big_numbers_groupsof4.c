#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// numbers are of same length. What if they aren't?
// do using linked list as well as in Python 
// subtraction of such numbers
// groups of 4

void my_strrev(char* str) 
{
    int l = 0;
    while (str[l])
        ++l; 

    int i;
    for (i = 0; i < l / 2; i++)
    {
        char temp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = temp;
    }
}

int main()
{
    char num1[100]; char num2[100]; int result [101];
    scanf("%s\n",num1);
    scanf("%s",num2);
    my_strrev(num1);
    my_strrev(num2);
    int carry;
    int len = strlen(num1);
    int i,j;
    
    // make groups of num1
    int no_of_groups = len/4;
    int groups[no_of_groups];
    for (i=0;i<no_of_groups;i++)
    {
        int c=0;
        for (j=4*i;j<4*(i+1);j++)
        {
            groups[i] += pow(10,c)* ( num1[j]- '0');
            c++;
        }
    }
    
    
    for (i=0;i<no_of_groups;i++)
        printf("%d\n",groups[i]);
    
    /* for (i=0; i<len/4; i++)
    {
        carry = carry + num1_4[i] + num2_4[i];
        result[i] = carry % 10000;
        carry = carry / 100000;
    }
    result[i] = carry;

    for (i=len;i>=0;i--)
    {
        if (result[i]==0 && i==len)
            continue;
        else    
            printf("%d",result[i]);
    } */
    
    return 0;
}
