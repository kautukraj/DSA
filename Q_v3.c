#include <stdio.h>
#include <string.h>
int main()
{
    // all digits same is not allowed
    // where we are drawing line is inclusive
    char str [] = "0011";
    int l = strlen(str);
    int freq[l]; int count=0;
    for (int i=0; i<l; i++)
        freq[i]=0;
        
    for (int i=0; i<l; i++)
    {
        if (str[i]=='0')
            count++;
        freq[i] = count;    
    }
    
    for (int i=0;i<l;i++)
        printf("%d ",freq[i]);
    for (int i=0;i<l;i++)
    {
        if (freq[i] == l-i-1-freq[l-1]+freq[i])
            printf("\n%d\n",i);
        //printf("%d = %d\n",freq[i],l-freq[n]);    
    }
    return 0;
}
