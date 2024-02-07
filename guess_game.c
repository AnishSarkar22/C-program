// create a guessing game and having limits
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int secretNumber = 5;
    int guess, guess_count = 0, guess_limit = 3, outOfGuess = 0;

    while (guess != secretNumber && outOfGuess == 0)
    {
        if (guess_count < guess_limit)
        {
            printf("Enter a number: ");
            scanf("%d", &guess);
            guess_count++;
        }
        else
            outOfGuess = 1;
    }
    if (outOfGuess == 1)
        printf("Out of guesses");
    else
        printf("You Win!");

    return 0;
}