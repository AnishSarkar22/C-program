#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kmp(char str[], char substr[])
{

    int n = strlen(str);
    int m = strlen(substr);
    int d[m], j, i;
    for (i = 0; i < m; i++)
        d[i] = 0;
    for (i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && (substr[j] != substr[i]))
            j = d[j - 1];
        if (substr[j] == substr[i])
        {
            j++;
            d[i] = j;
        }
    }
    for (i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && substr[j] != str[i])
            j = d[j - 1];
        if (substr[j] == str[i])
            j++;
        if (j == m)
        {
            free(d);
            return i - j + 1;
        }
        free(d);
    }
    return -1;
}
int main()
{
    char str[100], substr[20];
    printf("Enter the string: ");
    gets(str);
    printf("Enter the substring: ");
    gets(substr);
    int pos = kmp(str, substr);
    if(pos==-1)
    {
        printf("Match not found");
    }
    else
    {
        printf("Pattern starts from %d",pos+1);
    }


    return 0;
}