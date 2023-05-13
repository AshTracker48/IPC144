/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main() {
    char loopchar;
    int loopnum;

    printf("D = do/while | W = while | F = for | Q = quit\n");
    printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
    scanf(" %c%d", &loopchar, &loopnum);
    while (loopchar != 'Q' || loopnum != 0) {
        if (loopchar == 'D') {
            if (loopnum >= 3 && loopnum <= 20) {
                printf("DO-WHILE: ");
                int i = 0;
                do {
                    printf("D");
                    i++;
                } while (i < loopnum);
                printf("\n");
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else if (loopchar = 'W') {
            if (loopnum >= 3 && loopnum <= 20) {
                printf("WHILE : ");
                int i = 0;
                while (i < loopnum) {
                    printf("W");
                    i++;
                }
                printf("\n");
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else if (loopchar = 'F') {
            if (loopnum >= 3 && loopnum <= 20) {
                printf("FOR : ");
                for (int i = 0; i < loopnum; i++) {
                    printf("F");
                }
                printf("\n");
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else {
            printf("ERROR: Invalid entered value(s)!\n");
        }
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopchar, &loopnum);
    }
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}
