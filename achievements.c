#include <stdio.h>
#include <stdlib.h>
#include "home.h"
#include "achievements.h"

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