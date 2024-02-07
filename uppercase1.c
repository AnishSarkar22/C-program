//uppercases a string with using ctype function 

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    const char *s;      // or use " char s[100]; " 
    printf("Before: ");
    scanf("%s", s);

    printf("After: ");
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");

    return 0;
}
