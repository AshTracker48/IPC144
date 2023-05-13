/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

#define MAXPATHLENGTH 70
#define MINPATHLENGTH 10

#define MAXLIVES 10
#define MINLIVES 1

#define MULTIPLE 5

#include <stdio.h>

// Structure PlayerInfo
struct PlayerInfo {
    int nlives;
    char symbol;
    int treasureCount;
    int positionHistory[MAXPATHLENGTH];
};

// Structure GameInfo
struct GameInfo {
    int nmoves;
    int pathLength;
    int bombs[MAXPATHLENGTH];
    int treasures[MAXPATHLENGTH];
};

int main(void)
{
    // Declaring variables
    int i, j, k; // Used in for loops
    int movesRemaining, livesRemaining, movePosition = MAXPATHLENGTH + 1;

    // Allocating memory for a player and a game
    struct PlayerInfo Player;
    struct GameInfo Game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");

    // Prompting for Player Configurations
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &Player.symbol);

    do {
        printf("Set the number of lives: ");
        scanf("%d", &Player.nlives);

        if (Player.nlives < MINLIVES || Player.nlives > MAXLIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
    } while (Player.nlives < MINLIVES || Player.nlives > MAXLIVES);

    printf("Player configuration set-up is complete\n");
    printf("\n");

    // Prompting for Game Configuration 
    printf("GAME Configuration\n");
    printf("------------------\n");

    // Path Length
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &Game.pathLength);

        if ((Game.pathLength < MINPATHLENGTH || Game.pathLength > MAXPATHLENGTH) || (Game.pathLength % MULTIPLE != 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while ((Game.pathLength < MINPATHLENGTH || Game.pathLength > MAXPATHLENGTH) || (Game.pathLength % MULTIPLE != 0));

    // Number of moves
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &Game.nmoves);

        if (Game.nmoves < Player.nlives || Game.nmoves >(int) (0.75 * Game.pathLength))
        {
            printf("    Value must be between %d and %d\n", Player.nlives, (int)(0.75 * Game.pathLength));
        }
    } while (Game.nmoves < Player.nlives || Game.nmoves >(int) (0.75 * Game.pathLength));
    printf("\n");

    // Bomb Placement
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.pathLength);

    // Prompting for Bomb Placement
    for (i = 0; i < Game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &Game.bombs[i], &Game.bombs[i + 1], &Game.bombs[i + 2], &Game.bombs[i + 3], &Game.bombs[i + 4]);
    }

    printf("BOMB placement set\n");
    printf("\n");

    //Treasure Placement
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Game.pathLength);

    // Prompting for Treasure Placement
    for (i = 0; i < Game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &Game.treasures[i], &Game.treasures[i + 1], &Game.treasures[i + 2], &Game.treasures[i + 3], &Game.treasures[i + 4]);
    }

    printf("TREASURE placement set\n");
    printf("\n");

    printf("GAME configuration set-up is complete...\n");
    printf("\n");

    // Displaying the treasure hunt configuration settings
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    // Player Details
    printf("Player:\n");
    printf("   Symbol     : %c\n", Player.symbol);
    printf("   Lives      : %d\n", Player.nlives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");

    // Game Details
    printf("Game:\n");
    printf("   Path Length: %d\n", Game.pathLength);

    // Bombs
    printf("   Bombs      : ");
    // Displaying bombs array
    for (j = 0; j < Game.pathLength; j++)
    {
        printf("%d", Game.bombs[j]);
    }
    printf("\n");

    // Treasures
    printf("   Treasure   : ");
    // Displaying treasures array
    for (k = 0; k < Game.pathLength; k++)
    {
        printf("%d", Game.treasures[k]);
    }
    printf("\n\n");

    // Starting the game
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    // Variable Declarations
    movesRemaining = Game.nmoves;
    livesRemaining = Player.nlives;
    Player.treasureCount = 0;
    int count = 0;

    char currentPosition[MAXPATHLENGTH];
    char positionItem[MAXPATHLENGTH];

    for (j = 0; j < Game.pathLength; j++)
    {
        Player.positionHistory[j] = 0;
    }

    for (k = 0; k < Game.pathLength; k++)
    {
        positionItem[k] = '-';
    }

    for (k = 0; k < Game.pathLength; k++)
    {
        currentPosition[k] = ' ';
    }

    // Core Mechanism of Game
    do {
        // First Line
        for (k = 0; k < Game.pathLength; k++)
        {
            if (currentPosition[k] == 'V')
            {
                count += 1;
            }
        }

        
        if (count == 0)
        {
            printf("\n");
        }
        else
        {
            printf("  ");
            for (k = 0; k < Game.pathLength; k++)
            {
                if (currentPosition[k] == 'V')
                {
                    printf("%c\n", currentPosition[k]);
                    break;
                }
                else
                {
                    printf("%c", currentPosition[k]);
                }
            }
        }

        // Tracking current position requires the previous pointer to dissapear
        for (k = 0; k < Game.pathLength; k++)
        {
            currentPosition[k] = ' ';
        }

        // Second Line
        printf("  ");
        for (k = 0; k < Game.pathLength; k++)
        {
            printf("%c", positionItem[k]);
        }
        printf("\n");

        // Third Line
        printf("  ");
        for (i = 1; i <= Game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", (int)i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        // Fourth Line
        printf("  ");
        for (i = 0; i < Game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");

        // Displaying Player Statistics
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", livesRemaining, Player.treasureCount, movesRemaining);
        printf("+---------------------------------------------------+\n");

        // Quit loop if the remaining lives are zero
        if (livesRemaining == 0)
        {
            break;
        }

        // Quit loop if the remaining moves are zero
        if (movesRemaining == 0)
        {
            break;
        }

        // Determining the next move
        do {
            printf("Next Move [1-20]: ");
            scanf("%d", &movePosition);

            if (movePosition < 1 || movePosition > Game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }

        } while (movePosition < 1 || movePosition > Game.pathLength);
        printf("\n");

        if (Player.positionHistory[movePosition - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n\n");
            currentPosition[movePosition - 1] = 'V';
            movesRemaining++; // so that the time when it decrements, there is no effect
        }

        else if (Game.bombs[movePosition - 1] == 1 && Game.treasures[movePosition - 1] == 1)
        {
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
            positionItem[movePosition - 1] = '&';
            currentPosition[movePosition - 1] = 'V';
            livesRemaining--;
            Player.treasureCount++;
        }

        else if (Game.bombs[movePosition - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
            positionItem[movePosition - 1] = '!';
            currentPosition[movePosition - 1] = 'V';
            livesRemaining--;
        }

        else if (Game.treasures[movePosition - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
            positionItem[movePosition - 1] = '$';
            currentPosition[movePosition - 1] = 'V';
            Player.treasureCount++;
        }

        // else if (game.treasureLocations[movePosition - 1] == 0 && game.bombLocations[movePosition - 1] == 0)
        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n\n");
            positionItem[movePosition - 1] = '.';
            currentPosition[movePosition - 1] = 'V';
        }

        // Storing the position in history array
        Player.positionHistory[movePosition - 1] = 1;

        // Decrementing the number of moves left
        movesRemaining--;

        if (livesRemaining == 0)
        {
            printf("No more LIVES remaining!\n\n");
        }
        if (movesRemaining == 0)
        {
            printf("No more MOVES remaining!\n\n");
        }

    } while (movesRemaining >= 0 && livesRemaining >= 0);

    // Printing the final table

    printf("\n");

    // Ending Lines
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");
    printf("\n");

    printf("You should play again and try to beat your score!\n");
    printf("\n");

    return 0;
}