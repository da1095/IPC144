/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir 
	ID     : 153484209
	Email  :drahir-ahir@myseneca.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	double money, Tonnies, Loonies;
	int result;
	double Quarter ;
 

	printf("Change Maker Machine\n");
	printf("====================\n");
	printf("Enter dollars and cents amount to convert to coins: $");
	scanf("%lf", &money);
	printf("\n");

	
	
		result = money / 2.00;
		Tonnies = money - (result * 2);
		printf("$2.00 Toonies  X %d (remaining: $%.2lf)\n", result, Tonnies);

		result = Tonnies / 1.00;
		Loonies = Tonnies - (result * 1);
		printf("$1.00 Loonies  X %d (remaining: $%.2lf)\n", result, Loonies);

		result = Loonies / 0.25;
		Quarter = Loonies - (result * 0.25);
		printf("$0.25 Quarters X %d (remaining: $%.2lf)\n", result, Quarter);
		printf("\n");
		

		printf("Machine error! Thank you for letting me keep $%.2lf!\n", Quarter);
		
	return 0;
}