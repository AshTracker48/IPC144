/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
        printf("\n");
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt) {

    //Declaration of variables and structs
    int i = 0, eligibility = 0;
    
    //If format is table, then only display the header
    if (fmt == FMT_TABLE) {
        //Display the patient table header
        displayPatientTableHeader();
    }

    //Iterate to display the data of all patients
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            eligibility = 1;
        }
    }

    //If no data was displayed..
    if (!eligibility) {

        //In case, no records are found
        printf("*** No records found ***\n\n");

    }

    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {

    //Declaration of variables and structs
    int selection;

    //Selection options for user
    do {
        //Display the search options
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");

        //Prompt the user for selection
        selection = inputIntRange(0, 2);
        printf("\n");

        if (selection == 1) {
            //If the user wants to search the patient by patient number
            searchPatientByPatientNumber(patient, max);
            suspend();
        }
        else if (selection == 2) {
            //If the user wants to search the patient by patient's phone number
            searchPatientByPhoneNumber(patient, max);
            suspend();
        }
    } while (selection != 0);

}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {

    //Declaration of variables and structs
    int i, npatients = 0;

    //Iterate through the array to get the number of patients already there
    //in the list
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            npatients++;
        }
    }

    if (npatients < max) 
    {
        //If eleigible, ask for the patient details and store it..
        patient[npatients].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[npatients]);
        printf("*** New patient record added ***\n\n");
    }
    else {
        //In case, patient listing is full
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {

    //Declaration of variables and structs
    int patientNum, index;

    //Ask the user for patient number
    printf("Enter the patient number: ");
    patientNum = inputInt();
    printf("\n");

    //Get the index from the patient number
    index = findPatientIndexByPatientNum(patientNum, patient, max);

    if (index != -1) {
        //If index is not equal to zero, display the edit patient menu
        menuPatientEdit(&patient[index]);
    }
    else {
        //In case, no records were found
        printf("*** No records found ***\n");
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    
    //Declaration of variables and structs
    int patientNum = 0, index = 0;
    char selection;
    
    //Prompt the user for the patient number
    printf("Enter the patient number: ");
    patientNum = inputInt();
    printf("\n");

    //Get the index number of the patient
    index = findPatientIndexByPatientNum(patientNum, patient, max);

    if (index != -1) {
        //Display Patient data
        displayPatientData(&patient[index], FMT_FORM);

        //Ask if the user really want to remove the patient data from the system
        printf("Are you sure you want to remove this patient record? (y/n): ");
        selection = inputCharOption("ynYN");

        if (selection == 'n' || selection == 'N') {
            //Abort the operation of removing the patient data
            printf("Operation aborted.\n\n");
        }
        else {
            //If selection == 'y' or selection == 'Y', remove the patient record
            //and assign it to a safe empty state, so that the other funtion 
            //can't access it
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
        }
    }
    else {
        //If patient record is not found..
        printf("ERROR: Patient record not found!\n\n");
    }
    

}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    
    //Declaration of variables and structs
    int patientNum = 0, index = 0;

    //Prompt the user for patient number
    printf("Search by patient number: ");
    patientNum = inputInt();
    printf("\n");

    //Get the index number...
    index = findPatientIndexByPatientNum(patientNum, patient, max);

    if (index != -1) {
        //Display the patient data if found..
        displayPatientData(&patient[index], FMT_FORM);
    }
    else {
        //If no records are found
        printf("*** No records found ***\n\n");
    }

}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {

    //Declaring the variables and structs
    int i = 0, match = 0;
    char phnNum[PHONE_LEN + 1];

    //Prompt the user for the patient number
    printf("Search by phone number: ");
    inputCString(phnNum, 0, PHONE_LEN + 1);
    printf("\n");

    //Display Patient Table Header
    displayPatientTableHeader();

    //Iterate through the array to find the matching phone number
    for (i = 0; i < max + 1; i++) 
    {
        //If the phone number matches, call displayPatientData
        if (strcmp(patient[i].phone.number, phnNum) == 0) 
        {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);

            match++;
        }
    }

    printf("\n");

    //In case, no records are found, display the error message
    if (match == 0) {
        printf("*** No records found ***\n\n");
        // clearInputBuffer();
    }
    // else {
    //     clearInputBuffer();
    // }


}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {

    //Declaration of variables and structs
    int nextPtNum = 0, maxNum = patient[0].patientNumber, i = 0;

    //Iterate through the array to find the max patient number
    for (i = 0; i < max; i++) {

        //If the next patient number is greater than the maxNum, 
        //it is assigned to maxNum
        if (patient[i].patientNumber > maxNum) 
        {
            maxNum = patient[i].patientNumber;
        }
    }

    //The next patient number is the maxNum + 1
    nextPtNum = maxNum + 1;

    //Return the next Patient number
    return nextPtNum;

}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max) {

    //Declaration of variables and structs
    int i;

    //Iterate through the array to find the patient number
    for (i = 0; i < max; i++) 
    {
        //If patient number is found, return the index
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }

    //If not found, -1 is returned
    return -1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {

    //Declaration of variables and structs
    // char patientName[NAME_LEN];

    //Display Patient data input header
    printf("Patient Data Input\n");
    printf("------------------\n");

    //Prompt the user for patient name
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 0, NAME_LEN);

    printf("\n");

    //Get patient's phone number
    inputPhoneData(&patient->phone);
    
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {

    //Declaration of variables and structs
    int selection = 0;

    //Display the phone information header
    printf("Phone Information\n");
    printf("-----------------\n");

    //Display the ways of contacting the patient menu
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");

    //Asking the user to select their next movement..
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    printf("\n");

    //If the user's phone number is a CELL phone number
    if (selection == 1) 
    {
        //Storing the description 
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);

        //Displaying the description
        printf("Contact: %s\n", phone->description);

        
        //Asking the user for a number as input...
        printf("Number : ");
        inputCString(phone->number, 0, PHONE_LEN + 1);

        printf("\n");
        // clearInputBuffer();
    }
    //If the user's phone number is a HOME phone number
    else if (selection == 2) {

        //Storing the description in the struct
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);

        //Displaying the description 
        printf("Contact: %s\n", phone->description);


        //Asking the user for a number as input and storing it in struct
        printf("Number : ");
        inputCString(phone->number, 0, PHONE_LEN + 1);

        printf("\n");
        // clearInputBuffer();
    }
    //If the user's phone number is a WORK phone number
    else if (selection == 3) {

        //Storing the description in the struct
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);

        // Displaying description
        printf("Contact: %s\n", phone->description);


        // Asking the user for a number as input and storing it in struct
        printf("Number : ");
        inputCString(phone->number, 0, PHONE_LEN + 1);

        printf("\n");
        // clearInputBuffer();
    }
    //If the user's phone number is To Be Discussed...
    else if (selection == 4) {

        // Storing the description in the struct
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);

        *phone->number = 0;

    }
    //Else print the error message..
    else {
        printf("Error:\n");
    }

}
