#include <stdio.h>
#include <string.h>

int match(char text[], char pattern[]);

int main()
{
    char text[100];
    char pattern[100];
    printf("enter the text: ");
    gets(text);
    printf("enter the pattern to find: ");
    gets(pattern);
    int position = match(text, pattern);
    if (position != -1)
    {
        printf("string found at location %d: \n", position + 1);
    }
    else
    {
        printf("not found\n");
    }
    return 0;
}

int match(char text[], char pattern[])
{
    int c;
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    if (pattern_length > text_length)
    {
        return -1;
    }
    for (c = 0; c <= text_length - pattern_length; c++)
    {
        int position = c;
        int e = c;
        int d;
        for (d = 0; d < pattern_length; d++)
        {
            if (pattern[d] == text[e])
            {
                e++;
            }
            else
            {
                break;
            }
        }
        if (d == pattern_length)
        {
            return position;
        }
    }
    return -1;
}