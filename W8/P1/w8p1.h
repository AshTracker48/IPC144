/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : AYUSHKUMAR VIPULBHAI PATEL
Student ID#: 114473226
Email      : apatel574@myseneca.ca
Section    : G

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


#define MAXPRODUCTS 3
#define SUGGESTEDSERVING 64

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo {
    int sku_number;
    double product_price;
    int calories_per_serving;
    double product_weight_in_lbs;
};



// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int nproducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int sequence_number);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int calories, double* weight);

// 7. Logic entry point
void start();