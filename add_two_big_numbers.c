#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// numbers are of same length. What if they aren't? Add sufficient number of 0's to the front.
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
    int i;

    for (i=0; i<len; i++)
    {
        carry = carry + (num1[i]-'0') + (num2[i]-'0');
        result[i] = carry % 10;
        carry = carry / 10;
    }
    result[i] = carry; // important line 

    for (i=len;i>=0;i--)
    {
        if (result[i]==0 && i==len)
            continue;
        else    
            printf("%d",result[i]);
    }
    
    return 0;
}
