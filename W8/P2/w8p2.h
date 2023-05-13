/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : AYUSHKUMAR VIPULBHAI PATEL
Student ID#: 114473226
Email      : apatel574@myseneca.ca
Section    : G

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros
#define MAXPRODUCTS 3
#define SUGGESTEDSERVING 64
#define LBS_KGS 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku_number;
    double product_price;
    int calories_per_serving;
    double product_weight_in_lbs;
};

struct ReportData {
    int sku_number;
    double product_price;
    int calories;
    double weight_in_lbs;
    double weight_in_kgs;
    int weight_in_grams;
    double total_servings;
    double cost_per_serving;
    double cost_per_calorie;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int calories, double* weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* Lbs_to_be_converted, double* Result_in_Kgs);

// 9. convert lbs: g
int convertLbsG(const double* Lbs_to_be_converted, int* Result_in_Gs);

// 10. convert lbs: kg / g
void convertLbs(const double* Lbs_to_be_converted, double* Result_Lbs_Kgs, int* Result_Lbs_Gs);

// 11. calculate: servings based on gPerServ
double calculateServings(const int serving_size_in_Gs, const int Total_Gs, double* total_servings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* product_price, const double* total_servings, double* cost_per_serving);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* product_price, const double* total_calories, double* cost_per_cal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo Food);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData Report,const int cheapest_option);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo Food);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
