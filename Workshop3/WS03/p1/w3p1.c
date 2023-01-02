/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir
	ID     : 153484209
	Email  : drahir-ahir@myseneca.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#include<stdio.h>
int main()
{
	int JAN = 1;
	int DEC = 12;
	int year, month, isValid;
	printf("General Well-being Log\n");
	printf("======================\n");
	do 
	{
		isValid = 1;
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);
		if (year < MIN_YEAR || year > MAX_YEAR)
		{	
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
			isValid = 0;
		}
		if (month < JAN || month > DEC)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
			isValid = 0;
		}
	} while (isValid == 0);

	printf("\n*** Log date set! ***\n");
	switch (month) {
	case 1:
		printf("\nLog starting date: %d-JAN-01\n", year);
		break;
	case 2:
		printf("\nLog starting date: %d-FEB-01\n", year);
		break;
	case 3:
		printf("\nLog starting date: %d-MAR-01\n", year);
		break;
	case 4:
		printf("\nLog starting date: %d-APR-01\n", year);
		break;
	case 5:
		printf("\nLog starting date: %d-MAY-01\n", year);
		break;
	case 6:
		printf("\nLog starting date: %d-JUN-01\n", year);
		break;
	case 7:
		printf("\nLog starting date: %d-JUL-01\n", year);
		break;
	case 8:
		printf("\nLog starting date: %d-AUG-01\n", year);
		break;
	case 9:
		printf("\nLog starting date: %d-SEP-01\n", year);
		break;
	case 10:
		printf("\nLog starting date: %d-OCT-01\n", year);
		break;
	case 11:
		printf("\nLog starting date: %d-NOV-01\n", year);
		break;
	case 12:
		printf("\nLog starting date: %d-DEC-01\n", year);
		break;
	}
	return 0;
}

