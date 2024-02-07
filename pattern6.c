#include <stdio.h>

int main()
{
    int i, j, d, v, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        d = n - 1;
        v = i;
        for (j = 1; j <= i + 1; j++)
        {
            printf("%d ", v);
            v = v + d;
            d--;
        }
        printf("\n");
    }
    return 0;
}
