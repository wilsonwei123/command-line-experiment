#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int tokens = 100;
char response;
int bet;

void home(void);

//achievements
struct Achievements {
    int slotsProfit;
    int raceProfit;
    int raceGained;
    int slotsGained;
    int raceTotal;
    int raceWins;
    int slotsTotal;
    int slotsWins;
};

struct Achievements achievements = {0, 0, 0, 0, 0, 0, 0, 0};

/*
winKtokens, 20Ktokens, winTen, winThirty
raceProfit, slotsProfit, raceTotal, raceWins, slotsTotal, slotsWins
raceProfit and slotsProfit are equivalent to raceWinTokens and slotsWinTokens, but im too lazy to change
*/

int stats[] = {0, 0, 0, 0, 0, 0};
int raceAchievements[] = {0, 0, 0, 0};
int slotsAchievements[] = {0, 0, 0, 0};

int totalAddict = 0;

//functions
void checkAchievements(void) {
    int completion = 0;
    int figletAvailable = system("which figlet > /dev/null 2>&1") == 0;
    stats[0] = achievements.raceGained;
    stats[1] = achievements.slotsGained;
    stats[2] = achievements.raceTotal;
    stats[3] = achievements.raceWins;
    stats[4] = achievements.slotsTotal;
    stats[5] = achievements.slotsWins;

    if (achievements.raceProfit >= 1000) {
        if (raceAchievements[0] != 1) {
            printf("You have achieved\t");
            if (figletAvailable) {
                system("figlet 'winKtokens (race)'");
            } else {
                printf("winKtokens (race)\n\n");
            }
        raceAchievements[0] = 1;
        }
    }
        if (achievements.raceProfit >= 20000) {
            if (raceAchievements[1] != 1) {
                printf("You have achieved\t");
                if (figletAvailable) {
                    system("figlet 'win20Ktokens (race)'");
                } else {
                    printf("win20Ktokens (race)\n\n");
                }
        raceAchievements[1] = 1;
        }
    }
    if (achievements.raceWins >= 10) {
        if (raceAchievements[2] != 1) {
            printf("You have achieved\t");
            if (figletAvailable) {
                system("figlet 'winTen (race)'");
            } else {
                printf("winTen (race)\n\n");
            }
            raceAchievements[2] = 1;
        }
        if (raceAchievements[3] != 1) {
            if (achievements.raceWins >= 30) {
                printf("You have achieved\t");
                if (figletAvailable) {
                    system("figlet 'winThirty (race)'");
                } else {
                    printf("winThirty (race)\n\n");
                }
                raceAchievements[3] = 1;
            }
        }
    }
    if (achievements.slotsProfit >= 1000) {
        if (slotsAchievements[0] != 1) {
            printf("You have achieved\t");
            if (figletAvailable) {
                system("figlet 'winKtokens (slots)'");
            } else {
                printf("winKtokens (slots)\n\n");
            }
        slotsAchievements[0] = 1;
        }
    }
        if (achievements.slotsProfit >= 20000) {
            if (slotsAchievements[1] != 1) {
                printf("You have achieved\t");
                if (figletAvailable) {
                    system("figlet 'win20Ktokens (slots)'");
                } else {
                    printf("win20Ktokens (slots)\n\n");
                }
        slotsAchievements[1] = 1;
        }
    }
    if (achievements.slotsWins >= 10) {
        if (slotsAchievements[2] != 1) {
            printf("You have achieved\t");
            if (figletAvailable) {
                system("figlet 'winTen (slots)'");
            } else {
                printf("winTen (slots)\n\n");
            }
            slotsAchievements[2] = 1;
        }
        if (slotsAchievements[3] != 1) {
            if (achievements.slotsWins >= 30) {
                printf("You have achieved\t");
                if (figletAvailable) {
                    system("figlet 'winThirty (slots)'");
                } else {
                    printf("winThirty (slots)\n\n");
                }
                slotsAchievements[3] = 1;
            }
        }
    }
    if (totalAddict != 1) {
        for (int i = 0; i < sizeof(raceAchievements)/sizeof(int); i++) {
            if (raceAchievements[i] == 1) {
                completion++;
            }
            if (slotsAchievements[i] == 1) {
                completion++;
            }
        }
        if (completion == 8) {
            totalAddict = 1;
            printf("You have achieved\t");
            if (figletAvailable) {
                system("figlet 'TOTAL ADDICT'");
            } else {
                printf("TOTAL ADDICT\n\n");
            }
        }
    }
}

void printAchievements(void) {
    printf("\nFor winK and win20K, the tokens you lost playing do not count towards it. However, in the stats section, it will be the total tokens GAINED.\n");
    printf("Achievements:\n\n");
    printf("Unachieved:\n");

    if (raceAchievements[0] == 0) {
        printf("\twinKtokens (racing)");
    }
    if (raceAchievements[1] == 0) {
        printf("\twin20Ktokens (racing)");
    }
    if (raceAchievements[2] == 0) {
        printf("\twinTen (racing)");
    }
    if (raceAchievements[3] == 0) {
        printf("\twinThirty (racing)");
    }
    if (slotsAchievements[0] == 0) {
        printf("\twinKtokens (slots)");
    }
    if (slotsAchievements[1] == 0) {
        printf("\twin20Ktokens (slots)");
    }
    if (slotsAchievements[2] == 0) {
        printf("\twinTen (slots)");
    }
    if (slotsAchievements[3] == 0) {
        printf("\twinThirty (slots)");
    }

    printf("\n\nAchieved:\n");

    if (raceAchievements[0] == 1) {
        printf("\twinKtokens (racing)");
    }
    if (raceAchievements[1] == 1) {
        printf("\twin20Ktokens (racing)");
    }
    if (raceAchievements[2] == 1) {
        printf("\twinTen (racing)");
    }
    if (raceAchievements[3] == 1) {
        printf("\twinThirty (racing)");
    }
    if (slotsAchievements[0] == 1) {
        printf("\twinKtokens (slots)");
    }
    if (slotsAchievements[1] == 1) {
        printf("\twin20Ktokens (slots)");
    }
    if (slotsAchievements[2] == 1) {
        printf("\twinTen (slots)");
    }
    if (slotsAchievements[3] == 1) {
        printf("\twinThirty (slots)");
    }

    printf("\n\nYour stats:\n\n");
    printf("Total racing profit: %d\n", stats[0]);
    printf("Total slots profit: %d\n", stats[1]);
    printf("Total racing bets: %d\n", stats[2]);
    printf("Total racing wins: %d\n", stats[3]);
    printf("Total slots bets: %d\n", stats[4]);
    printf("Total slots wins: %d\n\n", stats[5]);
    printf("Total Addict unlocked (complete all other achievements)?\n");

    if (totalAddict == 0) {
        printf("No\n\n");
    } else {
        printf("Yes, congratulations!\n\n");
    }

    home();
}

//start of racing section

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

void printCountDown() {
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
            int num, valid;

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
                printf("Enter your bet (pays one-to-one, must be a positive integer): ");
                valid = scanf("%d", &bet);

                if (valid != 1) {
                    printf("Invalid input, try again\n");
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

//start of slots section

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
    int valid;
    intro();

    while (tokens > 0) {
        printf("Would you like a spin? y for yes, anything other character to return to home screen (you have %d tokens): ", tokens);
        scanf(" %c", &response);

        if (response == 'y') {
            do {
                printf("Enter your bet (positive integer): ");
                valid = scanf("%d", &bet);
                printf("\n");

                if (valid != 1) {
                    printf("Invalid input, try again\n");
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


int main() {
    char uselessChar;
    int figletAvailable = system("which figlet > /dev/null 2>&1") == 0;
    if (!figletAvailable) {
        printf("\n\nThis program works best with figlet installed. Enter any key to continue.\n");
        scanf("%c", &uselessChar);
    }

    srand(time(0));
    home();

    if (tokens <= 0) {
        printf("You walk out with %d tokens in your pockets.\n", tokens);
    }
}
