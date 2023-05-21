/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Ayushkumar Vipulbhai Patel
Student ID#: 114473226
Email      : apatel574@myseneca.ca
Section    : NGG
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // variable declaration
    int appleCartQuantity, orangeCartQuantity, pearCartQuantity, tomatoeCartQuantity, cabbageCartQuantity, loop_condition = 1, appleSelected = 0, orangeSelected = 0, pearSelected = 0, tomatoeSelected = 0, cabbageSelected = 0;;

    while (loop_condition == 1)
    {
        // Shopping List
        printf("Grocery Shopping\n================\n");

        //While number of [fruit / vegetable] < 0, show error statement and prompt user to enter the quantity again until it's > 0.
        // apples
        printf("How many APPLES do you need? : ");
        scanf("%d", &appleCartQuantity);
        while (appleCartQuantity < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many APPLES do you need? : ");
            scanf("%d", &appleCartQuantity);
        }
        printf("\n");

        // oranges
        printf("How many ORANGES do you need? : ");
        scanf("%d", &orangeCartQuantity);
        while (orangeCartQuantity < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many ORANGES do you need? : ");
            scanf("%d", &orangeCartQuantity);
        }
        printf("\n");

        // pears
        printf("How many PEARS do you need? : ");
        scanf("%d", &pearCartQuantity);
        while (pearCartQuantity < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many PEARS do you need? : ");
            scanf("%d", &pearCartQuantity);
        }
        printf("\n");

        // tomatoes
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoeCartQuantity);
        while (tomatoeCartQuantity < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoeCartQuantity);
        }
        printf("\n");

        // cabbage
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbageCartQuantity);
        while (cabbageCartQuantity < 0)
        {
            printf("ERROR: Value must be 0 or more.\n");
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbageCartQuantity);
        }
        printf("\n");

        // pick products
        printf("--------------------------\nTime to pick the products!\n--------------------------\n\n");

        // picking apples
        while (appleCartQuantity > 0)
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &appleSelected);

            if (appleSelected > appleCartQuantity)
            {
                printf("You picked too many... only %d more APPLE(S) are needed.\n", appleCartQuantity);
            }
            else if (appleSelected <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((appleSelected < appleCartQuantity) && (appleSelected > 0))
            {
                printf("Looks like we still need some APPLES...\n");
                appleCartQuantity = appleCartQuantity - appleSelected;
            }
            else if (appleCartQuantity == appleSelected)
            {
                printf("Great, that's the apples done!\n\n");
                break; // once the cartquantity matches the number of items selected, break out of the logic
            }
        }

        // picking oranges
        while (orangeCartQuantity > 0)
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &orangeSelected);

            if (orangeSelected > orangeCartQuantity)
            {
                printf("You picked too many... only %d more ORANGE(S) are needed.\n", orangeCartQuantity);
            }
            else if (orangeSelected <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((orangeSelected < orangeCartQuantity) && (orangeSelected > 0))
            {
                printf("Looks like we still need some ORANGES...\n");
                orangeCartQuantity = orangeCartQuantity - orangeSelected;
            }
            else if (orangeCartQuantity == orangeSelected)
            {
                printf("Great, that's the oranges done!\n\n");
                break;
            }
        }

        // picking pears
        while (pearCartQuantity > 0)
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pearSelected);

            if (pearSelected > pearCartQuantity)
            {
                printf("You picked too many... only %d more PEAR(S) are needed.\n", pearCartQuantity);
            }
            else if (pearSelected <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((pearSelected < pearCartQuantity) && (pearSelected > 0))
            {
                printf("Looks like we still need some PEARS...\n");
                pearCartQuantity = pearCartQuantity - pearSelected;
            }
            else if (pearCartQuantity == pearSelected)
            {
                printf("Great, that's the pears done!\n\n");
                break;
            }
        }

        // picking tomatoes
        while (tomatoeCartQuantity > 0)
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &tomatoeSelected);

            if (tomatoeSelected > tomatoeCartQuantity)
            {
                printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoeCartQuantity);
            }
            else if (tomatoeSelected <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((tomatoeSelected < tomatoeCartQuantity) && (tomatoeSelected > 0))
            {
                printf("Looks like we still need some TOMATOES...\n");
                tomatoeCartQuantity = tomatoeCartQuantity - tomatoeSelected;
            }
            else if (tomatoeCartQuantity == tomatoeSelected)
            {
                printf("Great, that's the tomatoes done!\n\n");
                break;
            }
        }

        // picking cabbage
        while (cabbageCartQuantity > 0)
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &cabbageSelected);

            if (cabbageSelected > cabbageCartQuantity)
            {
                printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbageCartQuantity);
            }
            else if (cabbageSelected <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            else if ((cabbageSelected < cabbageCartQuantity) && (cabbageSelected > 0))
            {
                printf("Looks like we still need some CABBAGES...\n");
                cabbageCartQuantity = cabbageCartQuantity - cabbageSelected;
            }
            else if (cabbageCartQuantity == cabbageSelected)
            {
                printf("Great, that's the cabbages done!\n\n");
                break;
            }
        }

        printf("All the items are picked!\n\n");

        // Logic to turn off the shopping prompt (ie when loop_condition is 0, while loop ends)
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &loop_condition);
        printf("\n");
    }

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}