/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : AYUSHKUMAR VIPULBHAI PATEL
Student ID#: 114473226
Email      : apatel574@myseneca.ca
Section    : G
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct PlayerInfo {
    int nlives;
    char symbol;
    int ntreasures;

};

struct GameInfo {
    int nmoves;
    int pathlength;
    int bombs[35];
    int treasure[35];
};

int main(void)
{

    struct PlayerInfo Player;
    struct GameInfo Game;


    int multiple = 5;
    int maxlives = 10, minlives = 1;
    int maxmoves = 26, minmoves = 3;
    int minpathlength = 10, maxpathlength = 70;

    Player.ntreasures = 35;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");


    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf("%c%*c", &Player.symbol);


   /* while ((Player.nlives < minlives) || (Player.nlives > maxlives)) {
        printf("Set the number of lives: ");
        scanf("%d", &Player.nlives);


        if ((Player.nlives < minlives) || (Player.nlives > maxlives)) {
            printf("     Must be between 1 and 10!\n");
        }
    }*/

    do {
        printf("Set the number of lives: ");
        scanf("%d", &Player.nlives);


        if ((Player.nlives < minlives) || (Player.nlives > maxlives)) {
            printf("     Must be between 1 and 10!\n");
        }
    } while ((Player.nlives < minlives) || (Player.nlives > maxlives));

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");


    do {
        printf("Set the path length (a multiple of 5 between %d-%d): ", minpathlength, maxpathlength);
        scanf("%d", &Game.pathlength);

        if (Game.pathlength < minpathlength || Game.pathlength > maxpathlength || (Game.pathlength % multiple != 0)) {
            printf("     Must be a multiple of 5 and between %d-%d!!!\n", minpathlength, maxpathlength);
        }
    } while ((Game.pathlength < minpathlength) || (Game.pathlength > maxpathlength) || (Game.pathlength % multiple != 0));

    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &Game.nmoves);

        if (Game.nmoves < minmoves || Game.nmoves > maxmoves) {
            printf("    Value must be between 3 and 26\n");
        }
    } while (Game.nmoves < minmoves || Game.nmoves > maxmoves);

    printf("\n");

    printf("BOMB Placement\n--------------\n");

    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Player.ntreasures);

    int i = 0;
    for (i = 0; i < Player.ntreasures; i += 5) {

        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &Game.bombs[i], &Game.bombs[i + 1], &Game.bombs[i + 2], &Game.bombs[i + 3], &Game.bombs[i + 4]);

    }

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n------------------\n");

    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Player.ntreasures);

    int j = 0;
    for (j = 0; j < Player.ntreasures; j += 5) {

        printf("   Positions [%2d-%2d]: ", j + 1, j + 5);
        scanf("%d %d %d %d %d", &Game.treasure[j], &Game.treasure[j + 1], &Game.treasure[j + 2], &Game.treasure[j + 3], &Game.treasure[j + 4]);

    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");

    printf("   Symbol     : %c\n", Player.symbol);
    printf("   Lives      : %d\n", Player.nlives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");


    printf("Game:\n");

    printf("   Path Length: %d\n", Game.pathlength);
    printf("   Bombs      : ");

    int k = 0;
    for (k = 0; k < Player.ntreasures; k++) {
        printf("%d", Game.bombs[k]);
    }

    printf("\n");

    printf("   Treasure   : ");

    int l = 0;
    for (l = 0; l < Player.ntreasures; l++) {
        printf("%d", Game.treasure[l]);
    }


    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}