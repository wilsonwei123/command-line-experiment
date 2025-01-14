#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "race_funcs.h"
#include "home.h"
#include "achievements.h"

// structures section
struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[21];
  char firstPlaceRaceCarColor[21];
};

struct RaceCar {
  int totalRaceTime;
  char driverName[21];
  char raceCarColor[21];
};

// print functions section
void printIntro(void) {
  printf("\nWelcome to the digital place where people drive fast cars!\n");
  printf("Now, please make sure your computer has sufficient battery to proceed, as we are starting.\n");
}

void printCountDown(void) {
  printf("\nStarting in...\n");
  printf("5\n");
  printf("4\n");
  printf("3\n");
  printf("2\n");
  printf("1\n");
  printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
  printf("\nAfter lap number %d of %d\n", race.currentLap, race.numberOfLaps);
  printf("In first place, it's %s in the %s car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulations(struct Race race) {
  printf("\nCongratulations to %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
  printf("Goodbye everybody, and hope to see you again at the next race!\n");
}
// logic functions section
int calculateTimeToCompleteLap(void) {
  int speed = rand() % 3 + 1;
  int acceleration = rand() % 3 + 1;
  int nerves = rand() % 3 + 1;
  return ((speed + acceleration + nerves) * 2);
}

void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalRaceTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalRaceTime <= raceCar2->totalRaceTime) {
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
  } else {
    strcpy(race->firstPlaceDriverName, raceCar2->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
  }
}

int startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};
  for (int i = 1; i <= race.numberOfLaps; i++) {
    race.currentLap = i;
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
  }
  printCongratulations(race);

  if (strcmp(race.firstPlaceDriverName, raceCar1->driverName) == 0) {
    return 1;
  } else {
    return 2;
  }
}

//main function for racing
void startRaceGamble(void) {
    int raceWinner;

    while (tokens > 0) {

        printf("Do you want to start this round? y for yes, any other character to return to home. You have %d tokens.\n", tokens);
        scanf(" %c", &response);


        if (response == 'y') {
            char a[21];
            char b[21];
            char c[21];
            char d[21];
            char guess[21];
            int num;

            printf("Enter the first racer's name (20 characters max): ");
            scanf("%s", a);
            printf("Enter the first racer's car color (20 characters max): ");
            scanf("%s", b);
            printf("Enter the second racer's name (20 characters max): ");
            scanf("%s", c);
            printf("Enter the second racer's car color (20 characters max): ");
            scanf("%s", d);

            struct RaceCar racer1 = {0, "", ""};
            struct RaceCar racer2 = {0, "", ""};
            strcpy(racer1.driverName, a);
            strcpy(racer1.raceCarColor, b);
            strcpy(racer2.driverName, c);
            strcpy(racer2.raceCarColor, d);

            do {
                bet = 0;
                printf("Enter your bet (pays one-to-one, must be a positive integer): ");

                if (scanf("%d", &bet) != 1) {
                    printf("Invalid input, try again\n");
                    while (getchar() != '\n');
                    continue;
                } else {
                    if (bet > tokens) {
                        printf("You don't have that many tokens.\n");
                    } else if (bet <= 0) {
                        printf("Bet must be positive.\n");
                    }
                }
            } while (bet > tokens || bet <= 0);

            do {
                printf("Enter the name of the driver of which car you think will win (20 characters max): ");
                scanf("%20s", guess);

                if (strcmp(guess, racer1.driverName) != 0 && strcmp(guess, racer2.driverName) != 0) {
                    printf("That name does not belong to one of the two folks driving today.\n");
                }

            } while (strcmp(guess, racer1.driverName) != 0 && strcmp(guess, racer2.driverName) != 0);

            if (strcmp(guess, racer1.driverName) == 0) {
                num = 1;
            } else {
                num = 2;
            }

            printIntro();
            printCountDown();
            printf("\n");

            raceWinner = startRace(&racer1, &racer2);

            if (raceWinner == num) {
                achievements.raceGained += bet;
                achievements.raceProfit += bet;
                achievements.raceWins++;
                achievements.raceTotal++;
                printf("Good guess!\n");
                tokens += bet;
            } else {
                achievements.raceGained -= bet;
                achievements.raceTotal++;
                printf("Bad guess.\n");
                tokens -= bet;
            }
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