/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Ayushkumar Vipulbhai Patel
Student ID#: 114473226
Email      : apatel574@myseneca.ca
Section    : NGG
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // Variables
    int iteration_num = 0;
    int loop_condition = 1;
    char loop_type;
    
    // Heading
    printf("+----------------------+\nLoop application STARTED\n+----------------------+\n\n");

    // Start running the while loop.
    while (loop_condition == 1)
    {
        // Take user input
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loop_type, &iteration_num);

        // Check if type of loop is valid
        if (loop_type == 'D' || loop_type == 'W' || loop_type == 'F')
        {
            // Check if requested number of iteration is greater than equal to 3 and less than equal to 20
            if (iteration_num >= 3 && iteration_num <= 20)
            {
                // run do-while loop
                if (loop_type == 'D')
                {
                    printf("DO-WHILE: ");
                    do
                    {
                        printf("D");
                        iteration_num--;
                    } while (iteration_num > 0);
                    printf("\n");
                }
                // run for loop
                else if (loop_type == 'F')
                {
                    printf("FOR     : ");
                    for (int i = iteration_num; i > 0; i--)
                    {
                        printf("F");
                    }
                    printf("\n");
                }
                // run while loop
                else if (loop_type == 'W')
                {
                    printf("WHILE   : ");
                    while (iteration_num > 0)
                    {
                        printf("W");
                        iteration_num--;
                    }
                    printf("\n");
                }
            }
            // when number of iterations used in loops are out of bounds.
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else
        {
            // Option to quit
            if (loop_type == 'Q')
            {
                if (iteration_num == 0)
                {
                    loop_condition = 0;
                }
                // when number of iterations to quit are out of bounds.
                else
                {
                    printf("ERROR: To quit, the number of iterations should be 0!\n");
                }
            }
            // when user input is invalid
            else
            {
                printf("ERROR: Invalid entered value(s)!\n");
            }
        }
        printf("\n");
    }
    // Footer
    printf("+--------------------+\nLoop application ENDED\n+--------------------+\n\n");

    return 0;
}