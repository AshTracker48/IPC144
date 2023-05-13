/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year = 2013, month = 2;


    printf("General Well-being Log\n");
    printf("======================\n");


    

    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if ((year > MAX_YEAR || year < MIN_YEAR) && (month > DEC || month < JAN)) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        else if (month > DEC || month < JAN) {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        else if (year > MAX_YEAR || year < MIN_YEAR) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
    } while ((MIN_YEAR > year) || (year > MAX_YEAR) || (JAN > month) || (month > DEC));

    printf("\n");

    printf("*** Log date set! ***\n");

    printf("\n");

    printf("Log starting date: %d-", year);

    switch (month) {
    case 1:
        printf("JAN-01");
        break;

    case 2:
        printf("FEB-01");
        break;

    case 3:
        printf("MAR-01");
        break;

    case 4:
        printf("APR-01");
        break;

    case 5:
        printf("MAY-01");
        break;

    case 6:
        printf("JUN-01");
        break;

    case 7:
        printf("JUL-01");
        break;

    case 8:
        printf("AUG-01");
        break;

    case 9:
        printf("Sep-01");
        break;

    case 10:
        printf("OCT-01");
        break;

    case 11:
        printf("NOV-01");
        break;

    case 12:
        printf("DEC-01");
        break;
    }
    printf("\n\n");
    return 0;
}