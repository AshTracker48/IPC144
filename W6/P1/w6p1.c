/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

#define MIN_ITEMS 1
#define MAX_ITEMS 10


int main(void) {

	double income = 0;
	const double MIN_INCOME = 500, MAX_INCOME = 400000, min_item_cost = 100;

	int i = 0, num_items = 0, priority[MAX_ITEMS];
	double cost[MAX_ITEMS];
	char finance[MAX_ITEMS];

	double total_cost = 0;

	int MAX_PRIORITY = 3;
	int MIN_PRIORITY = 1;


	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	// Prompting the user for monthly income
	while ((income < MIN_INCOME) || (income > MAX_INCOME)) {

		printf("Enter your monthly NET income: $");
		scanf("%lf", &income);

		if (income < MIN_INCOME) {
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_INCOME);
		}
		else if (income > MAX_INCOME) {
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME);
		}

	}

	printf("\n");

	// Prompted the user for number of list items to forecast
	while ((num_items > MAX_ITEMS) || (num_items < MIN_ITEMS)) {

		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &num_items);

		if ((num_items > MAX_ITEMS) || (num_items < MIN_ITEMS)) {
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		}

	}

	printf("\n");

	//Prompted  user for item details

	for (i = 0; i < num_items; i++) {

		printf("Item-%d Details:\n", i + 1);

		while (cost[i] < min_item_cost) {
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);

			if (cost[i] < min_item_cost) {
				printf("      ERROR: Cost must be at least $%.2lf\n", min_item_cost);
			}
		}


		while ((priority[i] < MIN_PRIORITY) || (priority[i] > MAX_PRIORITY)) {

			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);


			if ((priority[i] < MIN_PRIORITY) || (priority[i] > MAX_PRIORITY)) {
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		}


		while ((finance[i] != 'y') && (finance[i] != 'n')) {

			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finance[i]);

			if ((finance[i] != 'y') && (finance[i] != 'n')) {
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		}

		printf("\n");

	}

	// Final Calculation

	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	printf("%3d %6d %8c %14.2lf\n", 1, priority[0], finance[0], cost[0]);
	printf("%3d %6d %8c %14.2lf\n", 2, priority[1], finance[1], cost[1]);
	printf("%3d %6d %8c %14.2lf\n", 3, priority[2], finance[2], cost[2]);

	total_cost = cost[0] + cost[1] + cost[2];

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total_cost);



	printf("Best of luck in all your future endeavours!\n\n");






	return 0;
}