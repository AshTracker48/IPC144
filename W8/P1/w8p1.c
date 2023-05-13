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

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"


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
		scanf("%d", &Food.sku_number);

		if (Food.sku_number <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Food.sku_number <= 0);

	//PRODUCT_PRICE
	printf("PRICE         : $");
	do {
		scanf("%lf", &Food.product_price);

		if (Food.product_price <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Food.product_price <= 0);

	//PRODUCT_WEIGHT_IN_LBS
	printf("WEIGHT (LBS)  : ");
	do {
		scanf("%lf", &Food.product_weight_in_lbs);

		if (Food.product_weight_in_lbs <= 0) {
			printf("ERROR: Enter a positive value: ");
		}
	} while (Food.product_weight_in_lbs <= 0);

	//CALORIES_PER_SERVING
	printf("CALORIES/SERV.: ");
	
	do {
		scanf("%d", &Food.calories_per_serving);

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

// 7. Logic entry point
	void start() {
		int i = 0;
		struct CatFoodInfo Food[MAXPRODUCTS] = { {0} };
		openingMessage(MAXPRODUCTS);
		
		for (i = 0; i < MAXPRODUCTS; i++) {
			Food[i] = getCatFoodInfo(i);
		}

		displayCatFoodHeader();

		for (i = 0; i < MAXPRODUCTS; i++) {
			displayCatFoodData(Food[i].sku_number, &Food[i].product_price, Food[i].calories_per_serving, &Food[i].product_weight_in_lbs);
		}

	}
