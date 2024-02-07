//pyramid pattern using '#'

#include <stdio.h>
#include <stdlib.h>

void draw(int n);

int main()
{
    // Get height of pyramid
    int height;
    printf("Height: ");
    scanf("%d", &height);

    // Draw pyramid
    draw(height);
    return 0;
}

void draw(int n)
{
    // If nothing to draw
    if (n <= 0)
    {
        return;
    }

    // Draw pyramid of height n - 1
    draw(n - 1);

    // Draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
