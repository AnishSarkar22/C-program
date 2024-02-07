#include <stdio.h>

int main()
{
    int r, i, j, k;
    printf("Number of rows: ");
    scanf("%d", &r);

    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= 2 * (r - i); i++)
        {
            printf(" ");
        }
        for (k = 1; k < 2 * i; k++)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}