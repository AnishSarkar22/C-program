#include <stdio.h>
#include <stdlib.h>

void input(int *, int, int);
void display(int *, int, int);
void multiply(int *, int *, int *, int, int, int, int);

int main() {
    int r, c;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int *p = (int *)malloc(r * c * sizeof(int));
    int *q = (int *)malloc(r * c * sizeof(int));
    int *res = (int *)malloc(r * c * sizeof(int));

    printf("Enter elements for matrix 1:\n");
    input(p, r, c);

    printf("Enter elements for matrix 2:\n");
    input(q, r, c);

    printf("1st matrix is:\n");
    display(p, r, c);
    printf("\n");
    printf("2nd matrix is:\n");
    display(q, r, c);

    multiply(p, q, res, r, c, c, r); // Multiply matrices

    printf("Resultant matrix is:\n");
    display(res, r, r);

    free(p);
    free(q);
    free(res);

    return 0;
}

void input(int *ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", (ptr + i * cols + j));
        }
    }
}

void display(int *ptr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", *(ptr + i * cols + j));
        }
        printf("\n");
    }
}

void multiply(int *matrix1, int *matrix2, int *result, int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            int sum = 0;
            for (int k = 0; k < cols1; k++) {
                sum += *(matrix1 + i * cols1 + k) * *(matrix2 + k * cols2 + j);
            }
            *(result + i * cols2 + j) = sum;
        }
    }
}
