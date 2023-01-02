/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir
	ID     : 153484209
	Email  : drahir-ahir@myseneca.ca
	Section: NBB
*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3
#include<stdio.h>
int main()
{
	int JAN = 1;
	int DEC = 12;
	int year, month, isValid, days;
	double Morning_Rating, Evening_Rating;
	double Morning_Total = 0;
	double Evening_Total = 0;
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

	for (days = 1; days < 4; days++)
	{
		switch (month) {
		case 1:
			printf("\n%d-JAN-%02d\n", year, days);
			break;
		case 2:
			printf("\n%d-FEB-%02d\n", year, days);
			break;
		case 3:
			printf("\n%d-MAR-%02d\n", year, days);
			break;
		case 4:
			printf("\n%d-APR-%02d\n", year, days);
			break;
		case 5:
			printf("\n%d-MAY-%02d\n", year, days);
			break;
		case 6:
			printf("\n%d-JUN-%02d\n", year, days);
			break;
		case 7:
			printf("\n%d-JUL-%02d\n", year, days);
			break;
		case 8:
			printf("\n%d-AUG-%02d\n", year, days);
			break;
		case 9:
			printf("\n%d-SEP-%02d\n", year, days);
			break;
		case 10:
			printf("\n%d-OCT-%02d\n", year, days);
			break;
		case 11:
			printf("\n%d-NOV-%02d\n", year, days);
			break;
		case 12:
			printf("\n%d-DEC-%02d\n", year, days);
			break;
		}
		do
		{
			isValid = 1;
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &Morning_Rating);
			if (Morning_Rating > 5.0 || Morning_Rating < 0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				isValid = 0;
			}
		} while (isValid == 0);
		Morning_Total = Morning_Total + Morning_Rating;// sum of all morning rating

		do
		{
			isValid = 1;
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &Evening_Rating);
			if (Evening_Rating > 5.0 || Evening_Rating < 0)
			{
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
				isValid = 0;
			}
		} while (isValid == 0);
		Evening_Total = Evening_Total + Evening_Rating;// sum of all evening rating
	}
	double Total = Morning_Total + Evening_Total;//total rating morning + evening

	double Morning_Average = Morning_Total / LOG_DAYS;// Avarage for morning rating

	double Evening_Average = Evening_Total / LOG_DAYS;// Average for evening rating

	double Total_Average = Morning_Average + Evening_Average;// Sum og morning and evening average

	double Average = Total_Average / 2; //total average of all days
	printf("\nSummary\n");
	printf("=======\n");

	printf("Morning total rating: %.3lf\n", Morning_Total);
	printf("Evening total rating: %.3lf\n", Evening_Total);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n", Total);
	printf("\nAverage morning rating:  %.1lf\n", Morning_Average);
	printf("Average evening rating:  %.1lf\n", Evening_Average);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1lf\n", Average);


	return 0;
}
