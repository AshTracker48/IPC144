/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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

//System Libraries
#include <stdio.h>
#include <string.h>

//User defined Libraries
#include "core.h"

//1. inputInt Prototype : Get user input and validate if it's an integer
int inputInt(void) {

    //Function scope variable declarations
    char newLine = 'x';
    int value = 0, keepGoing = 1;

    //Iterating user input until a valid integer is entered..
    do
    {
        //Prompt the user to input the integer
        scanf("%d%c", &value, &newLine);

        //Condition to validate the input as an integer
        if (newLine == '\n') {

            //Integer is validated and can be returned to the function output.
            keepGoing = 0;

        }
        else {

            //Clear the buffer
            clearInputBuffer();
            //Print the error message
            printf("Error! Input a whole number: ");
            keepGoing = 1;

        }

    } while (keepGoing == 1);

    return value;
}

//2. inputIntPositive Prototype : Get user input and validate if it's a positive value
int inputIntPositive(void) {

    //Function scope variable declarations
    int value = 0, keepGoing = 1;

    //Iterating user input until a positive integer is entered..
    do
    {
        //Prompt the user to input a positive integer
        scanf("%d", &value);

        //Validate input to be a positive integer
        if (value > 0) {

            //Integer is validated and can be returned to the function output.
            keepGoing = 0;
        }
        else {

            //Clear the buffer
            clearInputBuffer();
            //Print the error message
            printf("ERROR! Value must be > 0: ");
            keepGoing = 1;
        }

    } while (keepGoing == 1);

    return value;

}

//3. inputIntRange Prototype : Get user input and validate until it is between a specified range
int inputIntRange(int lower_bound, int upper_bound) {

    //Function scope variable declarations
    int value = 0, keepGoing = 1;
    char character = 'x';

    //Iterating user input until the integer entered is between the specified range..
    do 
    {

        //Prompt the user to input an integer
        scanf("%d%c", &value, &character);

        //Validate input to be within the range
        if (value < lower_bound || value > upper_bound) {

            //Print the error message
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
            keepGoing = 1;
        }
        else if(character != '\n') {

            //Clear the buffer
            clearInputBuffer();
            //Print the error message
            printf("Error! Input a whole number: ");
            keepGoing = 1;

        }
        else {
            keepGoing = 0;
        }
    } while (keepGoing == 1);

    return value;
}

//4. inputCharOption Prototype
char inputCharOption(char valid_chars[]) {
    
    int keepGoing = 1;
    char character = 'x';
    do
    {
        //Input the character..
        scanf("%c", &character);

        //Validating whether the character belongs to the provided characters..
        if (strchr(valid_chars, character) != NULL) {
            keepGoing = 0;
        }
        //If not, display corresponding error message..
        else {
            clearInputBuffer();
            printf("ERROR: Character must be one of [qwErty]: ");
            keepGoing = 1;
        }
    } while (keepGoing == 1);
    //Clear the input buffer..
    clearInputBuffer();

    //After checking the character is from the 'qwErty' family, return the character..
    return character;
}

//5. inputCString Prototype : Get user input and validate the string if it's exactly the length as required..
void inputCString(char *C_String, int lower_bound, int upper_bound) {


    char ch = 'a';
    int flag = 1;
    
    //Iterating the input of the user and validating the input alongside..
    while (flag) {

        //Declare the length variable..
        int length = 0;
        
        //Prompt the user to enter the character..and calculate the length of the string..
        while (ch != '\n' && length <= upper_bound) {
            scanf("%c", &ch);
            C_String[length] = ch;
            length++;
        }

        //If there's no enter pressed by the user..
        if (ch == '\n' && length <= (upper_bound + 1)) {
            length--;
            C_String[length] = '\0';
        }
        //Otherwise..
        else {
            C_String[upper_bound] = '\0';
            clearInputBuffer();
        }

        //If max no. of characters is equal to the min no. of characters..
        if (upper_bound == lower_bound && length != lower_bound) {
            printf("ERROR: String length must be exactly %d chars: ", lower_bound);
            ch = 'a';
        }
        //else if length is not within the limit of min chars and max chars..
        else if (length < lower_bound || length > upper_bound) {

            //If length is lower than the min no. of chars..
            if (length < lower_bound) {
                printf("ERROR: String length must be between %d and %d chars: ", lower_bound, upper_bound);
                ch = 'a';
            }
            //else if length is greater than max. no. of chars..
            else if (length > upper_bound) {
                printf("ERROR: String length must be no more than %d chars: ", upper_bound);
                ch = 'a';
            }
        }
        //Otherwise, exit the loop..
        else {
            flag = 0;
        }

    }
}

//6. displayFormattedPhone Prototype
void displayFormattedPhone(const char* phn_no) {

    //Variable and flag declarations..
    int flag = 1, i = 0;
    int length = 0, length_of_phn_no = 10;

    //If phone number is not NULL and if the last character of the phone number is not EOL..
    while (phn_no != NULL && phn_no[length] != '\n' && flag == 1) {
        
        if (phn_no[length] >= '0' && phn_no[length] <= '9'){

            length++;
            flag = 1;

        }
        else {
            flag = 0;
        }

    }


    //If length of the entered string is equal to the length of a usual phone number..
    if(length == length_of_phn_no){
        
        //Displaying the phone number in an orderly sequence as required..
        printf("(");

        while (i < 3) {
            printf("%c", phn_no[i]);
            i++;
        }

        printf(")");

        while (i < 6) {
            printf("%c", phn_no[i]);
            i++;
        }

        printf("-");

        while (i < length_of_phn_no) {
            printf("%c", phn_no[i]);
            i++;
        }

    }
    else {
        printf("(___)___-____");
    }

}

//7. Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

//8. Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

