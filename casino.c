#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "home.h"

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
