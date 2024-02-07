//copy a string's address to another variable

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    // Get a string
    char s[50];
    printf("Enter a string: ");
    scanf("%s", s);

    // Copy string's address
    char *t = s;

    // Capitalize first letter in string
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // Print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
}