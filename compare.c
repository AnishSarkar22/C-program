//compare 2 strings

#include <string.h>
#include <stdio.h>

int main()
{
    // Get two strings
    char str1[50], str2[50];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    if (strcmp(str1, str2) == 0)
        printf("Strings are equal\n\n");
    else
        printf("Strings are not equal\n\n");

    /* Print strings' addresses
    printf("%p\n", str1);
    printf("%p\n", str2);
    */
    return 0;
}