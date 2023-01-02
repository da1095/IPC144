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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:

int getInt(void)
{
	int value;
	char NL = 'x';

	scanf(" %d%c", &value, &NL);

	while (NL != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf(" %d%c", &value, &NL);

	}
	//printf("Integer entered: %d", value);
	return value;
}


// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	{
		int Value = getInt();
		while (Value < min || Value > max)
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
			Value = getInt();
		}

		return Value;
	}
}

// yes function definition goes here:
int yes(void)
{
	char lChar = 'x';
	char lChar2 = 'x';
	int response = -1;

	scanf(" %c%c", &lChar, &lChar2);

	while (!((lChar2 == '\n') && ((lChar == 'Y') || (lChar == 'y') ||
		(lChar == 'n') || (lChar == 'N'))))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		//scanf(" %c%*c[^\n]", &lChar, &lChar2);
		scanf(" %c%c", &lChar, &lChar2);

	}

	if ((lChar == 'Y') || (lChar == 'y')) {
		response = 1;
	}
	else if ((lChar == 'N') || (lChar == 'n')) {
		response = 0;
	}

	return response;
}

// menu function definition goes here:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	return getIntInRange(0, 6);
	printf("\n");
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int a;
	do {
		a = menu();
		switch (a)
		{
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			int opt = yes();
			if (opt == 1) {
				printf("\nContact Management System: terminated\n");
				return;
			}
			else { printf("\n"); }

			break;
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;
		default:
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> ");
			break;
		}

	} while ((a >= 0) || (a <= 6));

	return;
}






// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1) 
    {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
        {
            needInput = 0;
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
// Put empty function definition below:



// displayContactFooter
// Put empty function definition below:



// displayContact:
// Put empty function definition below:



// displayContacts:
// Put empty function definition below:



// searchContacts:
// Put empty function definition below:



// addContact:
// Put empty function definition below:



// updateContact:
// Put empty function definition below:



// deleteContact:
// Put empty function definition below:



// sortContacts:
// Put empty function definition below:
