#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// game settings struct
typedef struct {
    int minRange;
    int maxRange;
    int maxAttempts;
    int difficulty;
} GameSettings;

// player stats struct
typedef struct {
    int totalGuesses;
    int gamesWon;
    int bestScore;
} PlayerStats;

int main() {
    char playAgain;
    PlayerStats player = {0, 0, 999}; // Initialize player stats

    do {
        srand(time(0));

        // game settings
        GameSettings settings;
        printf("\nChoose difficulty: \n");
        printf("(1) Easy - 10 attempts\n(2) Medium - 7 attempts\n(3) Hard - 5 attempts\n");
        scanf("%d", &settings.difficulty);

        // Assign max attempts based on difficulty
        settings.maxAttempts = (settings.difficulty == 1) ? 10 :
                               (settings.difficulty == 2) ? 7 : 5;

        // range selection
        printf("Enter the minimum number: ");
        scanf("%d", &settings.minRange);
        printf("Enter the maximum number: ");
        scanf("%d", &settings.maxRange);

        // Generate secret number within the range
        int secretNumber = rand() % (settings.maxRange - settings.minRange + 1) + settings.minRange;
        int guess, attempts = 0;

        printf("You have %d attempts to guess a number between %d and %d.\n",
               settings.maxAttempts, settings.minRange, settings.maxRange);

        // Game loop
        while (attempts < settings.maxAttempts) {
            attempts++;
            printf("Attempt %d/%d - Enter a number: ", attempts, settings.maxAttempts);
            scanf("%d", &guess);

            if (guess > secretNumber) {
                printf((guess - secretNumber >= 15) ? "Much too high!\n" : "Too high!\n");
            } else if (guess < secretNumber) {
                printf((secretNumber - guess >= 15) ? "Much too low!\n" : "Too low!\n");
            } else {
                printf("Correct! You guessed it in %d attempts!\n", attempts);
                player.gamesWon++;

                // Update best score
                if (attempts < player.bestScore) {
                    player.bestScore = attempts;
                    printf("New best score: %d attempts!\n", player.bestScore);
                }
                break;
            }
        }

        if (guess != secretNumber) {
            printf("Game over! The correct number was %d.\n", secretNumber);
        }

        // Update total guesses
        player.totalGuesses += attempts;

        // Ask to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    // Display final stats
    printf("\nFinal Stats:\n");
    printf("Total games won: %d\n", player.gamesWon);
    printf("Best score: %d attempts\n", player.bestScore);
    printf("Total guesses made: %d\n", player.totalGuesses);
    printf("Thanks for playing!\n");

    return 0;
}
