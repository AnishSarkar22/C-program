#include <stdio.h>
#include <string.h>

#define MAX 1000

int kmp(char substr[], char str[])
{
    int N = strlen(str);  // Length of the main string
    int M = strlen(substr);  // Length of the substring

    int d[MAX] = {0};  // Array to hold the longest prefix suffix values for the pattern
    int i, j;

    // Preprocess the pattern to create the longest prefix suffix array
    for (i = 1, j = 0; i < M; i++)
    {
        while (j > 0 && substr[j] != substr[i])
        {
            j = d[j - 1];
        }
        if (substr[j] == substr[i])
        {
            j++;
        }
        d[i] = j;
    }

    // Search the pattern in the main string
    for (i = 0, j = 0; i < N; i++)
    {
        while (j > 0 && substr[j] != str[i])
        {
            j = d[j - 1];
        }
        if (substr[j] == str[i])
        {
            j++;
        }
        if (j == M)
        {
            return i - j + 1;  // Found the pattern at index (i - j + 1)
        }
    }
    return -1;  // Pattern not found
}

int main()
{
    char str[MAX], substr[MAX];

    // Prompt the user to enter the main string
    printf("enter the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove the newline character

    // Prompt the user to enter the substring
    printf("enter the substring: ");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0'; // Remove the newline character

    // Find the position of the substring in the main string using KMP algorithm
    int pos = kmp(substr, str);
    if (pos != -1)
    {
        // If the substring is found, print the starting position (1-based index)
        printf("position starts at %d\n", pos + 1);
    }
    else
    {
        // If the substring is not found, print "match not found"
        printf("match not found\n");
    }
    return 0;
}
