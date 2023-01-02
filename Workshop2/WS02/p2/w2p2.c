/*
	==================================================
	Workshop #2 (Part-2):
	==================================================
	Name   :Devang Ramubhai Ahir Ahir 
	ID     :153484209
	Email  :drahir-ahir@myseneca.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	double money;
	int result;
	double Tonnies, Loonies, Quarter, Dime, Nickel, Penny;
	double Balance, Discount;


	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &money);
	
	printf("Service fee (5.0 percent): 0.50\n");

	Discount = money * 0.05;
	Balance = money - Discount;
	printf("Balance to dispense: $%.2lf\n", Balance);
	printf("\n");

	result = Balance / 2.00;
	Tonnies = Balance - (result * 2);
	printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", result, Tonnies);

	result = Tonnies / 1.00;
	Loonies = Tonnies - (result * 1);
	printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", result, Loonies);

	result = Loonies / 0.25;
	Quarter = Loonies - (result * 0.25);
	printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", result, Quarter);
	
	result = Quarter/ 0.10;
	Dime = Quarter - (result * 0.10);
	printf("$0.10 Dimes    X %d (remaining: $%.2lf)\n", result, Dime);

	result = Dime / 0.05;
	Nickel = Dime - (result * 0.05);
	printf("$0.05 Nickels  X %d (remaining: $%.2lf)\n", result, Nickel);

	result = Nickel / 0.01;
	Penny = Nickel - (result * 0.01);
	printf("$0.01 Pennies  X %d (remaining: $%.2lf)\n", result, Penny);
	printf("\n");
	printf("All coins dispensed!\n");

	return 0;
}