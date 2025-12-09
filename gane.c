#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame() {
    int randomNumber, guess, attempts = 0;
    srand(time(0));  // Seed the random number generator
    randomNumber = rand() % 100 + 1; // Generate a number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have picked a number between 1 and 100. Can you guess it?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
    } while (guess != randomNumber);
}

int main() {
    char choice;
    do {
        playGame();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}
