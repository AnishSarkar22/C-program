// swap 2 variables without using 3rd variable
#include <stdio.h>

int main()
{
    int a, b;
    printf("Enter 2 numbers: \n");
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("The swapped numbers are %d %d", a, b);
    return 0;
}