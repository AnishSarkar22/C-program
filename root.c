//find roots of a quadratic equation ax^2+bx+c=0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findroots(int a, int b, int c)
{
    double d = b*b - 4*a*c;
    if (a == 0 || d < 0)
    {
        printf("Invalid");
        return;
    }
    double sqrt_val = sqrt(abs(d));
    if (d == 0)
    {
        printf("Roots are real and equal: %f", -b/(2.0*a));
    }
    else
    {
        printf("Roots are real and different: %f, %f", (-b+sqrt_val)/(2.0*a), (-b-sqrt_val)/(2.0*a));
    }
}

int main()
{
    int a, b, c;
    printf("Enter coefficients a, b and c: ");
    scanf("%d %d %d", &a, &b, &c);
    findroots(a, b, c);
    return 0;
}
