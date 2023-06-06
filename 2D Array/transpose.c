// find the transpose of the matrix

#include <stdio.h>

int main()
{
    int r, c;
    printf("ENter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter all the elements: \n");
    int arr[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    // 1 2 3
    // 4 5 6

    // 1 4
    // 2 5
    // 3 6
    printf("\n");
    for (int i = 0; i < c; i++)     // c=3, r = 2
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d", arr[j][i]);
        }
        printf("\n");
    }
}