/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir
	ID     : 153484209
	Email  : drahir-ahir@myseneca.ca
	Section: NBB
*/

// ----------------------------------------------------------------------------
// defines/macros
#define NumberOfProduct 3
#define NumberOfGrams 64
#define KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int ProductSKU;
	double ProductPrice;
	int ProductCalories;
	double ProductWeight;
};

struct ReportData
{
	int SKU;
	double price;
	int calories;
	double LB;
	double weightKG;
	int grams;
	double total_servings;
	double cost_per_serving;
	double cost_per_cal_per_serving;
};// I prefer to code like this in struct. Its easy for me to look at the code.

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* num1);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* num2);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_product);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int product_info);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int ProductSKU, const double ProductPrice, const int ProductCalories, const double ProductWeight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* LB, double* weightKG);

// 9. convert lbs: g
int convertLbsG(const double* LB, int* grams);


// 10. convert lbs: kg / g
void convertLbs(const double* LB, double* weightKG, int* grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int volume, const int sum, double* total_servings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* total_servings, double* cost_per_serving);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* cost_per_cal_per_serving);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo Info);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int a);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheaper_Item);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
