#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5

int main() {
    srand(time(NULL)); 
    int player_balance = 1000;
    int bet_amount, guess, num_guesses = 0;

    printf("Welcome to the number guessing game!\n");
    printf("You have $%d to start with.\n", player_balance);

    while (player_balance > 0) {
        printf("Enter your bet amount (minimum $10): ");
        scanf("%d", &bet_amount);

        if (bet_amount < 10) {
            printf("Minimum bet amount is $10. Please try again.\n");
            continue;
        }

        if (bet_amount > player_balance) {
            printf("You don't have enough money to make that bet. Please try again.\n");
            continue;
        }

        printf("I'm thinking of a number between 1 and 100. Can you guess it in %d tries?\n", MAX_GUESSES);

        int number = rand() % 100 + 1;

        while (num_guesses < MAX_GUESSES) {
            printf("Guess #%d: ", num_guesses + 1);
            scanf("%d", &guess);

            if (guess == number) {
                printf("Congratulations, you guessed it in %d tries!\n", num_guesses + 1);
                player_balance += bet_amount;
                break;
            } else if (guess < number) {
                printf("Too low!\n");
            } else {
                printf("Too high!\n");
            }

            num_guesses++;
        }

        if (num_guesses == MAX_GUESSES) {
            printf("Sorry, you didn't guess the number in time. The number was %d.\n", number);
            player_balance -= bet_amount;
        }

        printf("Your new balance is $%d.\n", player_balance);

        if (player_balance < 10) {
            printf("Sorry, you're out of money! Game over.\n");
            break;
        }

        char play_again;
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);

        if (play_again == 'n' || play_again == 'N') {
            printf("Thanks for playing!\n");
            break;
        }

        num_guesses = 0;
    }

    return 0;
}