#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include "home.h"

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

void checkAchievements(void);
void printAchievements(void);

extern struct Achievements achievements;

#endif