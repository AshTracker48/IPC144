/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
#define MAX_SELECTION 2
#define MIN_SELECTION 0


int main(void)
{

	double income = 0;
	const double MIN_INCOME = 500, MAX_INCOME = 400000, min_item_cost = 100;

	int i = 0, num_items = 0, priority[MAX_ITEMS];
	double cost[MAX_ITEMS];
	char finance[MAX_ITEMS];

	double total_cost = 0, calchelp = 0;

	int MAX_PRIORITY = 3;
	int MIN_PRIORITY = 1;
	int selection = 0, nyears = 0, nmonths = 0, keepGoing = 1;
	int priority_preference = 0;

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

	for (i = 0; i < num_items; i++) {
		printf("%3d %6d %8c %14.2lf\n", i + 1, priority[i], finance[i], cost[i]);

		total_cost += cost[i];
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total_cost);



	 //Displaying result based on the User's selection


	do
	{

		//Asking user about how they want to forecase their wish list..
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");

		printf("Selection: ");
		scanf("%d", &selection);

		printf("\n");

		//If User selects 1 as the option
		if (selection == 1) {

			printf("====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", total_cost);

			calchelp = total_cost / income;

			nyears = (int)(calchelp / 12);
			nmonths = ((int)calchelp % 12) + 1;

			printf("Forecast: %d years, %d months\n", nyears, nmonths);

			//Checking whether there is a financing option available on any items..
			int finance_option = 0, h = 0;
			for (h = 0; h < num_items; h++)
			{

				if (finance[h] == 'y') {
					
					finance_option = 1;

				}
			}
			if (finance_option != 0) 
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}

			printf("====================================================\n\n");


		}

		//If User selects 2 as the option
		else if (selection == 2) 
		{

			printf("What priority do you want to filter by? [1-3]: ");
			scanf("%d", &priority_preference);

			printf("\n");

			printf("====================================================\n");
			printf("Filter:   by priority (%d)\n", priority_preference);

			//If priority value matches multiple items, then the total cost will be...
			double total_cost_by_priority = 0;
			int k = 0;
			for (k = 0; k < num_items; k++) {

				if (priority[k] == priority_preference) {
					total_cost_by_priority += cost[k];
				}
				else {
					keepGoing = 1;
				}

			}
			printf("Amount:   $%.2lf\n", total_cost_by_priority);
			
			calchelp = total_cost_by_priority / income;

			nyears = calchelp / 12;
			nmonths = ((int)calchelp % 12) + 1;

			//Number of years and months it will take to gather the amount of money as of the item(s)
			printf("Forecast: %d years, %d months\n", (int)nyears, (int)nmonths);

			//Checking whether there is a financing option available on any items
			int finance_yes = 0, n = 0;
			for (n = 0; n < num_items; n++) {

				if ((finance[n] == 'y') && (priority[n] == priority_preference)) {
					
					finance_yes = 1;

				}

			}
			if (finance_yes != 0) {

				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
				printf("====================================================\n\n");

			}
			else {
				printf("====================================================\n\n");
			}



		}

		//If User selects 0 as the option
		if (selection == 0) 
		{

			keepGoing = 0;

		}

		//If User selects a number other than 0,1,2
		if ((selection < MIN_SELECTION) || (selection > MAX_SELECTION)) 
		{
			printf("ERROR: Invalid menu selection.\n\n");
			keepGoing = 1;

		}

	}while (keepGoing == 1);

	printf("Best of luck in all your future endeavours!\n\n");

    return 0;
}