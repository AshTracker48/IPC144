/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : AYUSHKUMAR VIPULBHAI PATEL
Student ID#:114473226
Email      :apatel574@myseneca.ca
Section    :G
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

    double s = 17.96;
    double m = 26.96;
    double l = 35.97;
    int i = 8;

    printf("Set Shirt Prices\n");
    printf("================\n");


    printf("Enter the price for a SMALL shirt: $%.2lf\n", s);
    printf("Enter the price for a MEDIUM shirt: $%.2lf\n", m);
    printf("Enter the price for a LARGE shirt: $%.2lf\n\n", l);


    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", s);
    printf("MEDIUM : $%.2lf\n", m);
    printf("LARGE  : $%.2lf\n\n", l);



    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: %d\n\n", i);

    double st = s * i;
    double taxes = st * TAX;
    double total = taxes + st;
    double roundedtaxes = ((int)(taxes * 100 + 0.5) / 100.0);
    double roundedtotal = ((int)(total * 100 + 0.5) / 100.0);



    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", i);
    printf("Sub-total: $%.4lf\n", st);
    printf("Taxes    : $ %.4lf\n", roundedtaxes);
    printf("Total    : $%.4lf\n", roundedtotal);



    return 0;
}