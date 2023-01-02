/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Devang Ramubhai Ahir Ahir
	ID     : 153484209
	Email  : drahir-ahir@myseneca.ca
	Section: NBB
*/

// ----------------------------------------------------------------------------
// structures

#define NumberOfProduct 3
#define NumberOfGrams 64

struct CatFoodInfo
{
	int ProductSKU;
	double ProductPrice;
	int ProductCalories;
	double ProductWeight;
};
// ----------------------------------------------------------------------------
// function prototypes

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
void displayCatFoodHeader();



// 6. Display a formatted record of cat food data
void displayCatFoodData(const int ProductSKU, const double ProductPrice, const int ProductCalories, const double ProductWeight);




// 7. Logic entry point
void start();



