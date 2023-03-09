// find maximum between 3 numbers

#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2, int num3)
{
    int result;
    if (num1 >= num2 && num1 >= num3)
        result = num1;
    else if (num2 >= num1 && num2 >= num3)
        result = num2;
    else
        result = num3;
}

int main()
{
    printf("The largest number is %d", max(4, 1000, 20));
}