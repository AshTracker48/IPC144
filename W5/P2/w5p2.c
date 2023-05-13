/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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

#define LOG_DAYS 3
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year = 2013, month = 2;
    int noofdays = 0;
    double morningrating = 0, eveningrating = 0;

    const double lowestrating = 0.0, highestrating = 5.0;
    double morningtotalrating = 0, eveningtotalrating = 0;
    double avgmorningrating = 0, avgeveningrating = 0;


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


    for (noofdays = 1; noofdays <= LOG_DAYS; noofdays = noofdays + 1) {

        printf("2022-FEB-%02d\n", noofdays);

        

        
        while ( (lowestrating <= morningrating) || (highestrating >= morningrating)) {

            printf("   Morning rating (%.1lf-%.1lf): ", lowestrating, highestrating);
            scanf("%lf", &morningrating);

            if ((morningrating <= highestrating) && (morningrating >= lowestrating)) {

                morningtotalrating += morningrating;

                break;
            }
            
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            

        }


        while ((eveningrating >= lowestrating) || (eveningrating <= highestrating)) {

            printf("   Evening rating (%.1lf-%.1lf): ", lowestrating, highestrating);
            scanf("%lf", &eveningrating);

            if ((eveningrating <= highestrating) && (eveningrating >= lowestrating)) {

                printf("\n");

                eveningtotalrating += eveningrating;

                break;
            }
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            

        }


    }

    
    printf("Summary\n");
    printf("=======\n");


    printf("Morning total rating:%7.3lf\n", morningtotalrating);
    printf("Evening total rating:%7.3lf\n", eveningtotalrating);
    printf("----------------------------\n");
    printf("Overall total rating:%7.3lf\n\n", morningtotalrating + eveningtotalrating);


    avgmorningrating = morningtotalrating / LOG_DAYS;
    avgeveningrating = eveningtotalrating / LOG_DAYS;

    printf("Average morning rating:%5.1lf\n", avgmorningrating);
    printf("Average evening rating:%5.1lf\n", avgeveningrating);
    printf("----------------------------\n");
    printf("Average overall rating:%5.1lf\n", (avgmorningrating + avgeveningrating) / 2);



    return 0;
}