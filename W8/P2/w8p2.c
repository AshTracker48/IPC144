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

#define _CRT_SECURE_NO_WARNINGS


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number) {
	int input;

	do {
		scanf("%d", &input);

		if (input <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (input <= 0);

	if (number != NULL) {
		*number = input;
	}

	return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number) {
	double input = 0.0;

	do {
		scanf("%lf", &input);

		if (input <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (input <= 0);

	if (number != NULL) {
		*number = input;
	}

	return input;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(int nproducts) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", nproducts);
	printf("NOTE: A 'serving' is %dg\n\n", SUGGESTEDSERVING);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_number) {

	struct CatFoodInfo Food;

	//SKU_NUMBER
	printf("Cat Food Product #%d\n", sequence_number + 1);
	printf("--------------------\n");

	printf("SKU           : ");
	do {
		getIntPositive(&Food.sku_number);

		if (Food.sku_number <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Food.sku_number <= 0);

	//PRODUCT_PRICE
	printf("PRICE         : $");
	do {
		getDoublePositive(&Food.product_price);

		if (Food.product_price <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Food.product_price <= 0);

	//PRODUCT_WEIGHT_IN_LBS
	printf("WEIGHT (LBS)  : ");
	do {
		getDoublePositive(&Food.product_weight_in_lbs);

		if (Food.product_weight_in_lbs <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Food.product_weight_in_lbs <= 0);

	//CALORIES_PER_SERVING
	printf("CALORIES/SERV.: ");

	do {
		getIntPositive(&Food.calories_per_serving);

		if (Food.calories_per_serving <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Food.calories_per_serving <= 0);

	printf("\n");

	return Food;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku, double* price, int calories, double* weight) {

	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);

}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* Lbs_to_be_converted, double* Result_in_Kgs) {
	double result;

	result = (*Lbs_to_be_converted) / LBS_KGS;

	if (Result_in_Kgs != NULL) {
		*Result_in_Kgs = result;
	}

	return result;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* Lbs_to_be_converted, int* Result_in_Gs) {
	int result;

	result = (int)(((*Lbs_to_be_converted) / LBS_KGS) * 1000);

	if (Result_in_Gs != NULL) {
		*Result_in_Gs = result;
	}

	return result;
}

// 10. convert lbs: kg and g
void convertLbs(const double* Lbs_to_be_converted, double* Result_Lbs_Kgs, int* Result_Lbs_Gs) {
	double Lbs_Kgs;
	int Lbs_Gs;

	Lbs_Kgs = (*Lbs_to_be_converted) / LBS_KGS;
	Lbs_Gs = (int)(((*Lbs_to_be_converted) / LBS_KGS) * 1000);

	if (Result_Lbs_Kgs != NULL && Result_Lbs_Gs != NULL) {
		*Result_Lbs_Kgs = Lbs_Kgs;
		*Result_Lbs_Gs = Lbs_Gs;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int serving_size_in_Gs,const int Total_Gs, double* total_servings) {
	double servings;

	servings = ((double)Total_Gs) / serving_size_in_Gs;

	if (total_servings != NULL) {
		*total_servings = servings;
	}
	return servings;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* product_price, const double* total_servings, double* cost_per_serving) {
	double result;

	result = (*product_price) / (*total_servings);

	if (cost_per_serving != NULL) {
		*cost_per_serving = result;
	}
	return result;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* product_price, const double* total_calories, double* cost_per_cal) {
	double result;

	result = (*product_price) / (*total_calories);

	if (cost_per_cal != NULL) {
		*cost_per_cal = result;
	}
	return result;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo Food) {

	struct ReportData Report;

	//First 4 values assigned from CatFoodInfo to ReportData
	Report.sku_number = Food.sku_number;
	Report.product_price = Food.product_price;
	Report.weight_in_lbs = Food.product_weight_in_lbs;
	Report.calories = Food.calories_per_serving;

	//Calculating remaining values
	Report.weight_in_kgs = convertLbsKg(&Report.weight_in_lbs, &Report.weight_in_kgs);
	Report.weight_in_grams = convertLbsG(&Report.weight_in_lbs, &Report.weight_in_grams);
	Report.total_servings = calculateServings(SUGGESTEDSERVING, Report.weight_in_grams, &Report.total_servings);
	
	//Calculating Total Calories
	double total_calories = 0.00;
	total_calories = Report.calories * Report.total_servings;

	Report.cost_per_serving = calculateCostPerServing(&Report.product_price, &Report.total_servings, &Report.cost_per_serving);
	Report.cost_per_calorie = calculateCostPerCal(&Report.product_price, &total_calories, &Report.cost_per_calorie);

	return Report;

}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SUGGESTEDSERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData Report,const int cheapest_option) {
	
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", Report.sku_number, Report.product_price, Report.weight_in_lbs, Report.weight_in_kgs, Report.weight_in_grams, Report.calories,Report.total_servings, Report.cost_per_serving, Report.cost_per_calorie);
	
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(struct CatFoodInfo Food) {
	printf("Final Analysis\n");
	printf("--------------\n");

	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", Food.sku_number, Food.product_price);

	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	//Variables used throughout the function
	int i = 0, cheapest_option = 0;


	//Structs declarations
	struct CatFoodInfo Food[MAXPRODUCTS] = { {0} };
	struct ReportData Report[MAXPRODUCTS] = { {0} };

	//Opening Message
	openingMessage(MAXPRODUCTS);

	//Prompting the user to enter Cat Food Info
	for (i = 0; i < MAXPRODUCTS; i++) {
		Food[i] = getCatFoodInfo(i);
		Report[i] = calculateReportData(Food[i]);
	}


	//Display Cat Food Header
	displayCatFoodHeader();

	//Display Cat Food Data
	for (i = 0; i < MAXPRODUCTS; i++) {
		displayCatFoodData(Food[i].sku_number, &Food[i].product_price, Food[i].calories_per_serving, &Food[i].product_weight_in_lbs);
	}

	printf("\n");

	//Determining the cheapest option among all the Cat Food Options
	double cheapestProductPrice = Report[0].cost_per_serving;
	for (i = 0; i < MAXPRODUCTS; i++)
	{
		if (Report[i].cost_per_serving <= cheapestProductPrice)
		{
			cheapestProductPrice = Report[i].cost_per_serving;
			cheapest_option = i;
		}
	}

	//Display Report Header
	displayReportHeader();

	//Display Report Data
	for (i = 0; i < MAXPRODUCTS; i++) {

		displayReportData(Report[i], cheapest_option);

		if (cheapest_option == i) {
			printf(" ***\n");
		}
		else {
			printf("\n");
		}

	}

	printf("\n");


	//Display Final Analysis
	for (i = 0; i < MAXPRODUCTS; i++) {
		if (i == cheapest_option) {
			displayFinalAnalysis(Food[i]);
		}
	}

	//END
}
