#include <stdio.h>

int main()
{
    int n1 = 0, n2 = 1, n3, n4;
    printf("Enter the value of n ");
    scanf("%d", &n3);
    printf("%d %d ", n1, n2);
    for (int i = 2; i < n3; i++)
    {
        n4 = n1 + n2;
        printf("%d ", n4);
        n1 = n2;
        n2 = n4;
    }
    return 0;
}