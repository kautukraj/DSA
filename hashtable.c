#include <stdio.h>
#include <string.h>
#include <math.h>
int main()

{
    char str [] = "1111100001111";
    char search [] = "11";
    int search_as_int = 3;
    int p = 997;
    
    int arr[p][10];
    // initialize entire 2D array with -1
    for (int i=0;i<997;i++)
    {
        for (int j=0;j<10;j++)
            arr[i][j] = -1;
    }
    
    int l_str = strlen(str);
    int l_search = strlen(search);
    int i,j,k,c=0;
    
    for (i=0; i<= l_str - l_search; i++)
    {
        int sum=0;
        for (j=0; j < l_search; j++)
        {
            sum = sum + (str[i+j]-'0') * pow(2,l_search-1-j);
        }
        
        int remainder = sum % p;
        
        for (k=0;k<10;k++) // store the position in our 2D array
        {
            if (arr[remainder][k] == -1)
            { arr[remainder][k] = i; break;}
        }

        printf("%d %d\n",sum,i);
    
        
    }
    
    for (int i=0;i<997;i++)
        {
            for (int j=0;j<10;j++)
                printf("%d ",arr[i][j]);
            putchar('\n');    
        }
        
    int rem = search_as_int % p;
    //printf("%d",rem);
    for (i=0;i<10;i++)
    {
        if (arr[rem][0] == -1)
        {
            printf("No match at all");
            break;
        }
        
        if (arr[rem][i] != -1) // go to that position and cross check
        {
            int sum=0; int c = l_search - 1; 
            for (j=arr[rem][i];j < arr[rem][i]+l_search; j++)
            {
                sum = sum + (str[j]-'0') * pow(2,c);
                c--;
            }
            
            printf("%d\n",sum);
            
            if (search_as_int == sum)
            printf("Match found at %d\n",arr[rem][i]);
            else
            printf("No match at %d\n",arr[rem][i]);
        }

        
    }
        
        
    
    return 0;
    
}
