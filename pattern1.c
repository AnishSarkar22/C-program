#include <stdio.h>

void main()
{
    int i, s, n = 5, j = 0;
    for (i = 0; i < n; i++)
    {
        for (s = 0; s < n - i; s++)
        {
            printf("  ");
        }
        for (j = 0; j <= 2 * i; j++)
        {
            if (j == 0 || j == 2 * i)
            {
                printf("*");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    for (i = 0; i < 2 * n; i++)
    {
        printf("* ");
    }
}