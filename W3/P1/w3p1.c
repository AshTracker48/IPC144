/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : AYUSHKUMAR VIPULBHAI PATEL
Student ID#: 114473226
Email      : apatel574@myseneca.ca
Section    : G
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    int P1ID = 111;
    int P2ID = 222;
    int P3ID;
    P3ID = P1ID;

    char P1TAX = 'Y';
    char P2TAX = 'N';
    char P3TAX;
    P3TAX = P2TAX;

    double P1PRICE = 111.4900;
    double P2PRICE = 222.9900;
    double P3PRICE = 334.4900;
    double AVGPRICE = 222.9900;

    printf("Product Information\n");
    printf("===================\n");


    printf("Product-1 (ID:%d)\n", P1ID);
    printf("  Taxed: %c\n", P1TAX);
    printf("  Price: $%.4lf\n\n", P1PRICE);

    printf("Product-2 (ID:%d)\n", P2ID);
    printf("  Taxed: %c\n", P2TAX);
    printf("  Price: $%.4lf\n\n", P2PRICE);

    printf("Product-3 (ID:%d)\n", P3ID);
    printf("  Taxed: %c\n", P3TAX);
    printf("  Price: $%.4lf\n\n", P3PRICE);

    printf("The average of all prices is: $%.4lf\n\n", AVGPRICE);



    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");

    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");



    printf("Some Data Analysis...\n");
    printf("=====================\n");


    printf("1. Is product 1 taxable? -> ");
    printf("%d\n\n", (P1TAX == 'Y'));


    printf("2. Are products 2 and 3 both NOT taxable (N)? -> ");
    printf("%d\n\n", (P2TAX == 'N') && (P3TAX == 'N'));


    printf("3. Is product 3 less than testValue ($%.2lf)? -> ", testValue);
    printf("%d\n\n", (P3PRICE < testValue));


    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> ");
    printf("%d\n\n", P3PRICE > (P1PRICE + P2PRICE));


    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  ");
    printf("%d ", P1PRICE >= (P3PRICE - P2PRICE));
    printf("(price difference: $%.2lf)\n\n", (P3PRICE - P2PRICE));

    printf("6. Is the price of product 2 equal to or more than the average price? -> ");
    printf("%d\n\n", P2PRICE >= AVGPRICE);


    printf("7. Based on product ID, product 1 is unique -> ");
    printf("%d\n\n", (P1ID != P2ID) && (P1ID != P3ID));

    printf("8. Based on product ID, product 2 is unique -> ");
    printf("%d\n\n", (P2ID != P1ID) && (P2ID != P3ID));

    printf("9. Based on product ID, product 3 is unique -> ");
    printf("%d\n\n", (P3ID != P1ID) && (P3ID != P2ID));



    return 0;
}