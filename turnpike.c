#include <stdio.h>
#include <stdlib.h>

int check(int*, int, int*, int, int);

int main()
{
    int elements[] = {1,1,1,2,2,3};
    int ans[4];
    ans[0] = 0;
    ans[3] = 3;
    int remElements[] = {1,1,1,2,2};
    int length = sizeof(remElements) / sizeof (remElements[0]);
    int flag = check(remElements, length, ans, 1, 4);
    printf("%d",flag);
}

int check(int* remElements, int length, int* ans, int left, int right)
{
    if (left==right)
    return;

    else
    {
        ans[left] = remElements[length-1];
        // create remElements2 array

        if (check(remElements2, length-1, ans, left+1, right)==1)
            return 1;
        else
        {
            ans[right] = remElements[length-1];
            if (check(remElements2, length-1, ans, left, right-1)==1)
                return 1;
            else
                return 0;
        
        }
    }
}