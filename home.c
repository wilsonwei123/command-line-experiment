#include <stdio.h>
#include <stdlib.h>
#include "home.h"
#include "achievements.h"
#include "race_funcs.h"
#include "slots_funcs.h"

int bet, tokens = 100;
char response;

//home
void home(void) {
    int destination;

    while (tokens > 0) {
        printf("\n");

        int figletAvailable = system("which figlet > /dev/null 2>&1") == 0;
        if (figletAvailable) {
            system("figlet 'HOME'");
        } else {
            printf("HOME\n");
        }

        printf("\n");
        printf("\n1. Racing\t2. Slots\t3. Achievements\t4. Exit Casino\n\n");
        printf("Please enter the number (1, 2, 3 or 4) of where you would like to go: ");

        if (scanf("%d", &destination) != 1 || destination < 1 || destination > 4) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');
            continue;
        }

        if (destination == 1) {
            startRaceGamble();
            break;
        } else if (destination == 2) {
                startSlotsGamble();
                break;
        } else if (destination == 3) {
            printAchievements();
            break;
        } else if (destination == 4) {
            printf("You walk out with %d tokens in your pockets.\n", tokens);
            break;
        }
    }
}