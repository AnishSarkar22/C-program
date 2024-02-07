#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    printf("Addition is %d\n", a + b);
    printf("Substraction is %d\n", a - b);
    printf("Multiplication is %d\n", a * b);
    printf("Division is %f\n", (float)a / b);
    return 0;
}