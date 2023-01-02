/*
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir
	ID     : 153484209
	Email  : drahir-ahir@myseneca.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#define LEAST 500
#define NMORE 400000
#define LOW 100
#include<stdio.h> 

int main()
{
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	int Valid, Wish;
	int i = 1;
	int e = 1;
	double Netmonthly;
	double cost[MAX], totalcost = 0;
	int value[MAX];
	char YES = 'y';
	char No = 'n';
	char resp[MAX];
	do
	{
		Valid = 1;
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &Netmonthly);

		if (Netmonthly < LEAST)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
			Valid = 0;
		}
		if (Netmonthly > NMORE)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
			Valid = 0;
		}

	} while (Valid == 0);


	do
	{
		Valid = 1;
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &Wish);
		if (Wish < 1 || Wish > MAX)
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
			Valid = 0;
		}

	} while (Valid == 0);



	for (i = 1; i <= Wish; i++)
	{
		printf("\nItem-%d Details:", i);

		do
		{
			Valid = 1;
			printf("\n   Item cost: $");
			scanf("%lf", &cost[i]);
			if (cost[i] < LOW)
			{
				printf("      ERROR: Cost must be at least $100.00");
				Valid = 0;
			}

		} while (Valid == 0);
		totalcost = totalcost + cost[i];

		do
		{
			Valid = 1;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &value[i]);
			if (value[i] < 1 || value[i] > 3)
			{
				printf("      ERROR: Value must be between 1 and 3\n");
				Valid = 0;
			}

		} while (Valid == 0);

		do
		{
			Valid = 1;
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &resp[i]);
			if (resp[i] != YES && resp[i] != No)
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
				Valid = 0;
			}

		} while (Valid == 0);
	}

	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (e = 1; e <= Wish; e++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", e, value[e], resp[e], cost[e]);
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalcost);
	int option;
	do
	{
		printf("How do you want to forecast your wish list?\n 1. All items (no filter)\n 2. By priority\n 0. Quit/Exit\nSelection: ");
		scanf("%d", &option);
		if (option == 1) { // All items (no filter)
			int time = 0;
			time = totalcost / Netmonthly;
			int years = 0;
			int months = 0;
			int finance = 0;
			while (time >= 12)
			{
				years = years + 1;
				time = time - 12;
			}
			while (time > 0)
			{
				months = months + 1;
				time = time - 1;
			}
			months++;
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", totalcost);
			printf("Forecast: %d years, %d months\n", years, months);
			for (i = 1; i < Wish; i++) {
				if (resp[i] == 'y') {
					finance = 1;
				}
			}
			if (finance == 1) {
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}

			printf("====================================================\n\n");
		}
		else if (option == 2) { // By priority
			int choice;
			double Price = 0;
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &choice);
			for (i = 1; i <= Wish; i++) {
				if (value[i] == choice) {
					Price = Price + cost[i];
				}
			}
			int time = Price / Netmonthly;
			int years = 0;
			int months = 0;
			int finance = 0;
			while (time >= 12) {
				years = years + 1;
				time = time - 12;
			}
			while (time > 0) {
				months = months + 1;
				time = time - 1;
			}
			months++;
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", choice);
			printf("Amount:   $%.2lf\n", Price);
			printf("Forecast: %d years, %d months\n", years, months);
			for (i = 1; i < Wish; i++) {
				if (value[i] == choice) {
					if (resp[i] == 'y') {
						finance = 1;
					}
				}
			}
			if (finance == 1) {
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n\n");
		}
		else if (option == 0) {
			Valid = 0;
		}
		else if (option > 2) { // Invalid Selection (too high)
			printf("\nERROR: Invalid menu selection.\n\n");
			Valid = 1;
		}
		else if (option < 0) { // Invalid Selection (too low)
			printf("\nERROR: Invalid menu selection.\n\n");
			Valid = 1;
		}
	} while (Valid == 1);
	printf("\nBest of luck in all your future endeavours!\n");
	return 0;
}



