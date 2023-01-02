//==============================================
// Name:           Devang Ramubhai Ahir Ahir
// Student Number: 153484209
// Email:          drahir-ahir@myseneca.ca
// Section:        NBB
// Date:           
//==============================================
// Assignment:     2
// Milestone:      3
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-----------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2     |
// |        function definitions below...                |
// |                                                     |
// | HINT:  Update the getNumbers function to use the    |
// |        new helper function "getTenDigitPhone"       |
// |        where applicable                             |
// +-----------------------------------------------------+

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getName:
void getName(struct Name* name)
{
	
	int opt;

	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]s", name->firstName);


	printf("Do you want to enter a middle initial(s)? (y or n): ");
	opt = yes();
	
	if (opt == 0) 
	{
		name->middleInitial[0] = '\0';
	}
	else 
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]s", name->middleInitial);
	}
	clearKeyboard();

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]s", name->lastName);
	clearKeyboard();
}


// getAddress:
void getAddress(struct Address* address)
{
	
	int isValid = 0;
	printf("Please enter the contact's street number: ");
	do 
	{
		address->streetNumber = getInt();
		if (address->streetNumber < 0)
		{
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		}
		else
		{
			isValid = 1;
		}
	} while (!isValid);
	isValid = 0;
	

	printf("Please enter the contact's street name: ");
	scanf("%[^\n]40s", address->street);   
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	int opt = yes();
	
	if (opt == 0)
	{
		address->apartmentNumber = 0;
	}
	else
	{
		printf("Please enter the contact's apartment number: ");
		do
		{
			address->apartmentNumber = getInt();
			if (address->apartmentNumber < 0) 
			{
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			}
			else 
			{
				isValid = 1;
			}
		} while (!isValid);
		isValid = 0;
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]s", address->city);
	clearKeyboard();
}

// getNumbers:


void getNumbers(struct Numbers* numbers)
{
	
	int optYesNo;

	
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	
	printf("Do you want to enter a home phone number? (y or n): ");
	optYesNo = yes();
	
	if (optYesNo == 0)
	{
		strcpy(numbers->home, "\0");
	}
	else
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}

	//BUSINESS
	printf("Do you want to enter a business phone number? (y or n): ");
	optYesNo = yes();
	

	
	if (optYesNo == 0)
	{
		strcpy(numbers->business, "\0");
	}
	else 
	{

		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	
}


// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}



