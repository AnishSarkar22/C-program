// sum of digits and print it in reverse

#include <stdio.h>

int main()
{
    int a, b, c, d, e;
    printf("Enter a 4 digit number:  ");
    scanf("%d", &a);
    b = a % 10;
    c = (a / 10) % 10;
    d = (a / 100) % 10;
    e = (a / 1000) % 10;
    printf("Sum of the 4 digits is %d \n", b + c + d + e);
    printf("Reverse of the number is %d \n", e + d * 10 + c * 100 + b * 1000);
}