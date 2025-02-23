#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char playAgain;

    do {
        srand(time(0)); 
        int secretNumber = rand() % 100 + 1; 
        int guess, attempts = 0, maxAttempts;

       
        printf("\nChoose difficulty: \n");
        printf("(1) Easy - 10 attempts\n(2) Medium - 7 attempts\n(3) Hard - 5 attempts\n");
        int difficulty;
        scanf("%d", &difficulty);

        
        if (difficulty == 1) maxAttempts = 10;
        else if (difficulty == 2) maxAttempts = 7;
        else maxAttempts = 5; 

        printf("You have %d attempts to guess the number.\n", maxAttempts);

        while (attempts < maxAttempts) {
            attempts++;
            printf("Attempt %d/%d - Enter a number: ", attempts, maxAttempts);
            scanf("%d", &guess);

            int difference = abs(secretNumber - guess);

            if (guess > secretNumber) {
                if (difference >= 15) {
                    printf("Much too high!\n");
                } else {
                    printf("Too high!\n");
                }
            } else if (guess < secretNumber) {
                if (difference >= 15) {
                    printf("Much too low!\n");
                } else {
                    printf("Too low!\n");
                }
            } else {
                printf("Correct! You guessed it in %d attempts!\n", attempts);
                break; 
            }
        }

        if (guess != secretNumber) {
            printf("Game over! The correct number was %d.\n", secretNumber);
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain); 

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
