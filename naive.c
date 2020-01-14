#include <stdio.h>
#include <string.h>
int main()
{
    char text[] = "aaaaaa";
    char search[] = "aa";
    int n = strlen(text);
    int m = strlen(search);
    int i, j;

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (search[j] != text[i + j])
                break;
        }

        if (j == m)
            printf("Match found at %d\n", i);
    }

    return 0;
}
