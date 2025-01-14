#include <stdio.h>
#include <stdlib.h>
#include "achievements.h"
#include "home.h"

void intro(void) {
    printf("Welcome to the slots! Here, you get a spin of the wheels. If you get a double, you win 4x your bet. A triple is worth 7x your bet, and 777 is worth 25x.\n\n");
}

int getNum(void) {
    int num = rand() % 10;
    return num;
}

int spinSlots(void) {
    int num1 = getNum();
    int num2 = getNum();
    int num3 = getNum();

    printf("%d%d%d\n\n", num1, num2, num3);

    if ((num1 == num2) && (num1 == num3) && (num1 == 7)) {
        printf("JACKPOT! You win 25x your bet.\n");
        return 25;
    } else if ((num1 == num2) && (num1 == num3)) {
        printf("Amazing! You win 7x your bet for getting triples.\n");
        return 7;
    } else if ((num1 == num2) || (num1 == num3) || (num2 == num3)) {
        printf("Nice! You won 4x your bet for getting doubles.\n");
        return 4;
    } else {
        printf("Nothing this time.\n");
        return 0;
    }
}

void calcWinningsAndExecute(void) {
    tokens -= bet;
    achievements.slotsGained -= bet;
    achievements.slotsTotal++;
    int x = spinSlots();
    tokens += x * bet;
    achievements.slotsGained += x * bet;
    achievements.slotsProfit += x * bet;
    if (x != 0) {
        achievements.slotsWins++;
    }
}

//main function for slots
void startSlotsGamble(void) {
    intro();

    while (tokens > 0) {
        printf("Would you like a spin? y for yes, anything other character to return to home screen (you have %d tokens): ", tokens);
        scanf(" %c", &response);

        if (response == 'y') {
            do {
                bet = 0;
                printf("Enter your bet (positive integer): ");

                if (scanf("%d", &bet) != 1) {
                    printf("Invalid input, try again\n");
                    while (getchar() != '\n');
                    continue;
                } else {
                    if (bet <= 0) {
                        printf("Please enter a positive integer.\n");
                    } else if (bet > tokens) {
                        printf("You do not own that many tokens.\n");
                    }
                }
            } while (bet <= 0 || bet > tokens);

            calcWinningsAndExecute();
            checkAchievements();
        } else {
            break;
        }
    }
    if (tokens <= 0) {
        printf("No tokens left.\n");
    } else {
        home();
    }
}