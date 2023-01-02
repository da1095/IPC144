//==============================================
// Name:           Devang Ramubhai Ahir Ahir
// Student Number: 153484209
// Email:          drahir-ahir@myseneca.ca
// Section:        NBB
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:

void getName(struct Name* name)
{

	int opt;

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]%*c", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	opt = yes();

	if (opt == 0) 
	{
		name->middleInitial[0] = '\0';
	}
	else 
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]%*c", name->middleInitial);
	}


	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]%*c", name->lastName);


}

// getAddress:

void getAddress(struct Address* address) 
{

	//char option[2] = ("n");
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
	//scanf("%d", &address->streetNumber);
	printf("Please enter the contact's street name: ");
	scanf("%[^\n]40s", address->street);   //using this way to avoid the problem of missing 'space' in names like "Keele Street"  
	//scanf(" %40s[^\n]", address->street);
	clearKeyboard();


	printf("Do you want to enter an apartment number? (y or n): ");
	int opt = yes();
	if (opt == 1) 
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
	else
	{
		address->apartmentNumber = 0;
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
	int option;
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();
	if (option != 0)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else
	{
		numbers->home[0] = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();
	if (option != 0)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else
	{
		numbers->business[0] = '\0';
	}
}

// getContact:

void getContact(struct Contact* contact) 
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
