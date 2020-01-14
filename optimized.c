#include <stdio.h>
#include <string.h>
#include <math.h>
int main()

{
    char str [] = "1100000011";
    char search [] = "11";
    int p = 997;
    
    int N = search[0]- '0'; int Y = str[0]- '0';
    int x = 2;
    for (int i=1;i<strlen(search);i++)
    {
        x = x*2;
        N = N*2 + (search[i] - '0');
        Y= Y*2 + (str[i] - '0');
    }
    
    if (N==Y)
    printf("Match found at 0\n");
    
    for (int i=1;i<=strlen(str)-strlen(search);i++)
    {
        Y = Y*2 + (str[strlen(search)-1+i]-'0') - x*(str[i-1]-'0');
        if (N==Y)
        printf("Match found at %d\n",i);
        else
        printf("No match at %d\n",i);
    }
    
    return 0;
    
}
