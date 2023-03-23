//Sum of series: 1 – x^2/2! + x^4/4! - ... upto nth terms

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double sum = 1, t = 1, m, y = 2, fct = 1,x=9;
    int n;

    printf("Input the number of terms : ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        fct = 1;
        for (int j = 1; j <= y; j++)
        {
            fct = fct * j;
        }
        t = t * (-1);
        m = t * pow(x, y) / fct;
        sum = sum + m;
        y += 2;
    }
    printf("%.4f", sum);

    return 0;
}
