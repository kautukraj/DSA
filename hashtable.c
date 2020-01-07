#include <stdio.h>
#include <string.h>
#include <math.h>
int main()

{
    char str [] = "1010100101010110";
    char search [] = "0101";
    int p = 997;
    int arr[p][2];
    int l_str = strlen(str);
    int l_search = strlen(search);
    int i,j,c=0;
    
    for (i=0; i<=l_str - l_search; i++)
    {
        int sum=0;
        for (j=0; j<l_search; j++)
        {
            sum = sum + (str[i+j]-'0')*pow(2,l_search-1-j);
        }
        
        int remainder = sum % p;
        arr[remainder][c++] = sum;
        
    }
    
    for (int i=0;i<997;i++)
        {
            for (int j=0:j<2;j++)
                printf("%d")
        }
    
    return 0;
    
}
