//addition of diagonal elements in a 3x3 matrix
#include <stdio.h>

const int max = 10;
int diagonal_sum(int m, int n, int matrix[][max])
{
    int i, j, a = 0, sum = 0;
    if (m == n)
    {
        printf("The matrix is \n");
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                printf("%d", matrix[i][j]);
            }
            printf("\n");
        }
        for (i = 0; i < m; ++i)
        {
            sum = sum + matrix[i][i];
            a = a + matrix[i][m - i - 1];
        }
        printf("Main diagonal elements sum is = %d\n", sum);
        printf("Off-diagonal elements sum is = %d\n", a);
    }
    else
        printf("Not a square matrix\n");
}

int main()
{
    int m = 3, n = 3;
    int matrix[][10] = {{1, 4, 6}, {3, 5, 6}, {5, 8, 9}};
    diagonal_sum(m, n, matrix);
    return 0;
}