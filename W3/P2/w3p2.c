/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    //COFFEE
    char typeone = 0, typetwo = 0, typethree = 0 ;
    int bagweightone = 0, bagweighttwo = 0, bagweightthree = 0;
    char creamone = 0, creamtwo = 0, creamthree = 0;

    //USER INPUT VARIABLES
    char type = 0;
    int bagweight = 0;
    char cream = 0;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");



    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &typeone);

    printf("Bag weight (g): ");
    scanf(" %d", &bagweightone);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamone);

    printf("\n");



    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &typetwo);

    printf("Bag weight (g): ");
    scanf(" %d", &bagweighttwo);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamtwo);

    printf("\n");



    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &typethree);

    printf("Bag weight (g): ");
    scanf(" %d", &bagweightthree);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &creamthree);

    printf("\n");

    //TABLE
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich |  (G) | Lbs     | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");

    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (typeone == 'L' || typeone == 'l'), (typeone == 'M' || typeone == 'm'), (typeone == 'R' || typeone == 'r'), bagweightone, (bagweightone / GRAMS_IN_LBS), ((creamone == 'Y') || (creamone == 'y')));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (typetwo == 'L' || typetwo == 'l'), (typetwo == 'M' || typetwo == 'm'), (typetwo == 'R' || typetwo == 'r'), bagweighttwo, (bagweighttwo / GRAMS_IN_LBS), ((creamone == 'N') || (creamone == 'n')));
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", (typethree == 'L' || typethree == 'l'), (typethree == 'M' || typethree == 'm'), (typethree == 'R' || typethree == 'r'), bagweightthree, (bagweightthree / GRAMS_IN_LBS), ((creamone == 'N') || (creamone == 'n')));









    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");


    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &type);

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream);

    printf("Typical number of daily servings: ");
    scanf(" %d", bagweight);

    //TABLE

    printf("The below table shows how your preferences align to the available products:");

    printf("--------------------+-------------+-------+");
    printf("  |     Coffee      |  Packaged   | With  |");
    printf("ID|      Type       | Bag Weight  | Cream |");
    printf("--+-----------------+-------------+-------+");

    printf(" 1|       %d         |      %d      |   %d   |\n", (type == 'L' || type == 'l'), ((bagweight >= 1) || (bagweight <= 4)), ((cream == 'Y') || (cream == 'y')));
    printf(" 2|       %d         |      %d      |   %d   |\n", (type == 'M' || type == 'm'), ((bagweight >= 5) || (bagweight <= 9)), ((cream == 'N') || (cream == 'n')));
    printf(" 3|       %d         |      %d      |   %d   |\n", (type == 'R' || type == 'r'), (bagweight >= 10), ((cream == 'N') || (cream == 'n')));










    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");


    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &type);

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream);

    printf("Typical number of daily servings: ");
    scanf(" %d", bagweight);

    //TABLE

    printf("The below table shows how your preferences align to the available products:");

    printf("--------------------+-------------+-------+");
    printf("  |     Coffee      |  Packaged   | With  |");
    printf("ID|      Type       | Bag Weight  | Cream |");
    printf("--+-----------------+-------------+-------+");

    printf(" 1|       %d         |      %d      |   %d   |\n", (type == 'L' || type == 'l'), ((bagweight >= 1) || (bagweight <= 4)), ((cream == 'Y') || (cream == 'y')));
    printf(" 2|       %d         |      %d      |   %d   |\n", (type == 'M' || type == 'm'), ((bagweight >= 5) || (bagweight <= 9)), ((cream == 'N') || (cream == 'n')));
    printf(" 3|       %d         |      %d      |   %d   |\n", (type == 'R' || type == 'r'), (bagweight >= 10), ((cream == 'N') || (cream == 'n')));




    printf("Hope you found a product that suits your likes!");




    return 0;
}


/*
Provided formatting parts for printf statements:
As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",
*/