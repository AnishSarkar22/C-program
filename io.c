#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr = NULL;
    ptr = fopen("myfile.txt", "r+");
    char str[4];
    // fgets(str, 4, ptr);
    // printf("The string is: %s\n", str);

    fputc('o', ptr);
    fputs("this is harry", ptr);

    fclose(ptr);
    return 0;
}