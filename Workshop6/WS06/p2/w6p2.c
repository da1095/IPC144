/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir
	ID     : 153484209
	Email  : drahir-ahir@myseneca.ca
	Section: NBB
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include<stdio.h>

// User-Defined Libraries
#include "w6p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num1)
{
	int NUM1;
	do
	{
		scanf("%d", &NUM1);
		if (NUM1 <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (NUM1 <= 0);
	if (num1 != NULL)
		*num1 = NUM1;
	return NUM1;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num2)
{
	double NUM2;
	do
	{
		scanf("%lf", &NUM2);
		if (NUM2 <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (NUM2 <= 0);
	if (num2 != NULL)
		*num2 = NUM2;
	return NUM2;

}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for 3 dry food bags of product data for analysis.\nNOTE: A 'serving' is %dg\n", NumberOfGrams);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int product_info)
{
	struct CatFoodInfo foodinfo = { 0 };
	printf("\nCat Food Product #%d\n", product_info);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&foodinfo.ProductSKU);
	printf("PRICE         : $");
	getDoublePositive(&foodinfo.ProductPrice);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&foodinfo.ProductWeight);
	printf("CALORIES/SERV.: ");
	getIntPositive(&foodinfo.ProductCalories);

	return foodinfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int ProductSKU, const double ProductPrice, const int ProductCalories, const double ProductWeight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", ProductSKU, ProductPrice, ProductWeight, ProductCalories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* LB, double* weightKG)
{
		double kilogram;
		kilogram = *LB / KG;
		if (weightKG != NULL)
			*weightKG = kilogram;
	return kilogram;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* LB, int* grams)
{
	int Grams;
	Grams = convertLbsKg(LB, 0) * 1000;
	if (grams != NULL)
		*grams = Grams;
	return Grams;
}

// 10. convert lbs: kg and g
void convertLbs(const double* LB, double* weightKG, int* grams)
{
	convertLbsKg(LB, weightKG);
	convertLbsG(LB, grams);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int volume, const int sum, double* total_servings)
{
	double result;
	result = (double)sum / (double)volume;
	if (total_servings != NULL)
		*total_servings = result;
	return result;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* total_servings, double* cost_per_serving)
{
	double Price;
	Price = *price / *total_servings;
	if (cost_per_serving != NULL)
		*cost_per_serving = Price;
	return Price;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* cost_per_cal_per_serving)
{
	double Price;
	Price = *price / *calories;
	if (cost_per_cal_per_serving != NULL)
		*cost_per_cal_per_serving = Price;
	return Price;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo Info)
{
	double CALorie;
	struct ReportData report;
	report.SKU = Info.ProductSKU;
	report.price = Info.ProductCalories;
	report.LB = Info.ProductWeight;
	report.calories = Info.ProductCalories;

	//For kg
	report.weightKG = convertLbsKg(&Info.ProductWeight, &report.weightKG);

	//for g
	report.grams = convertLbsG(&Info.ProductWeight, &report.grams);

	report.total_servings = calculateServings(NumberOfGrams, report.grams, &report.total_servings);
	report.cost_per_serving = calculateCostPerServing(&report.price, &report.total_servings, &report.cost_per_serving);
	CALorie = report.calories * report.total_servings;
	report.cost_per_cal_per_serving = calculateCostPerCal(&report.price, &CALorie, &report.cost_per_cal_per_serving);
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NumberOfGrams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int a)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.SKU, report.price, report.LB, report.weightKG, report.grams, report.calories, report.total_servings, report.cost_per_serving, report.cost_per_cal_per_serving);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheaper_Item)

{
	printf("\n");
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", cheaper_Item.ProductSKU, cheaper_Item.ProductPrice);
	printf("Happy shopping!\n");
}


// ----------------------------------------------------------------------------

// 7. Logic entry point
void  start()
{
	struct CatFoodInfo Info[NumberOfProduct] = { {0} };
	openingMessage(NumberOfProduct);
	int i, cheaper_item;
	for (i = 0; i < NumberOfProduct; i++)
	{
		Info[i] = getCatFoodInfo(i + 1);
	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < NumberOfProduct; i++)
	{
		displayCatFoodData(Info[i].ProductSKU, Info[i].ProductPrice, Info[i].ProductCalories, Info[i].ProductWeight);
	}

	struct ReportData report[NumberOfProduct];
	displayReportHeader();
	for (i = 0; i < NumberOfProduct; i++)
	{	
		report[i] = calculateReportData(Info[i]);
		if (report[i].cost_per_serving < report[i -1].cost_per_serving)
		{
			cheaper_item = i;
		}
	}

	int j;
	for (j = 0; j < NumberOfProduct; j++)
	{
		struct ReportData x = { 0 };
		x = report[j];
		displayReportData(x, cheaper_item);
		if (cheaper_item == j)
		{
			printf(" ***");
		}
		printf("\n");
	}
	displayFinalAnalysis(Info[cheaper_item]);
}
