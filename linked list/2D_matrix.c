#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void input(int *);
void display(int *);
void add(int *, int *, int *);
void sub(int *, int *, int *);
void transpose(int *, int *);
void multi(int *, int *, int *);
int r, c;


int main()
{
    printf("Enter the rows and column of the matrix:\n");
    scanf("%d%d", &r, &c);
    int *p = (int *)malloc(r * c * sizeof(int));
    int *q = (int *)malloc(r * c * sizeof(int));
    int *addi = (int *)malloc(r * c * sizeof(int));
    int *subt = (int *)malloc(r * c * sizeof(int));
    int *trans = (int *)malloc(r * c * sizeof(int));
    int *mult = (int *)malloc(r * c * sizeof(int));
    printf("Enter the elements in matrix1:\n");
    input(p);
    printf("Enter the elements in matrix2:\n");
    input(q);
    printf("\nAdding and Displaying the matrices:\n");
    add(p, q, addi);
    display(addi);
    printf("\nSubtracting and Displaying the matrices:\n");
    sub(p, q, subt);
    display(subt);
    printf("\nMultiplying and Displaying the matrices:\n");
    multi(p, q, mult);
    display(mult);
    printf("\nTransposing and Displaying the matrix:\n");
    transpose(p, trans);
    display(trans);
    return 0;
}
void input(int *ptr)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter the element at position (%d,%d):", i + 1, j + 1);
            scanf("%d", (ptr + (i * c + j)));
        }
    }
}
void display(int *ptr)
{
    printf("[");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", *(ptr + i * c + j));
        }
        if (i == r - 1)
        {
            printf("]");
        }
        else
        {
            printf("\n");
        }
    }
}
void add(int *ptr1, int *ptr2, int *add)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(add + i * c + j) = *(ptr1 + i * c + j) + *(ptr2 + i * c + j);
        }
    }
}
void sub(int *ptr1, int **ptr2, int *add)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(add + i * c + j) = *(ptr1 + i * c + j) - *(ptr2 + i * c + j);
        }
    }
}
void transpose(int *ptr1, int *ptr2)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(ptr2 + i * c + j) = *(ptr1 + j * r + i);
        }
    }
}
void multi(int *ptr1, int *ptr2, int *mult)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(mult + i * c + j) = 0;
            for (int m = 0; m < c; m++)
            {
                *(mult + i * c + j) += (*(ptr1 + i * c + m)) * (*(ptr2 + m * c + j));
            }
        }
    }
}