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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents here...                         |
// +-------------------------------------------------+

#include "contacts.h"
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+

// Clear the standard input buffer
// clearKeyboard:

void clearKeyboard(void);

// pause:
void pause(void);

// getInt:
int getInt(void);

// getIntInRange:
int getIntInRange(int min, int max);

// yes:
int yes(void);

// menu:
int menu(void);

// contactManagerSystem:
void contactManagerSystem(void);

// getTenDigitPhone
void getTenDigitPhone(char phoneNum[]);

// findContactIndex
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// displayContactHeader
void displayContactHeader(void);

// displayContactFooter
void displayContactFooter(int count);

// displayContact
void displayContact(const struct Contact* contact);

// displayContacts
void displayContacts(const struct Contact contacts[], int size);

// searchContacts
void searchContacts(const struct Contact contacts[], int size);

// addContact
void addContact(struct Contact contacts[], int size);

// updateContact
void updateContact(struct Contact contacts[], int size);

// deleteContact
void deleteContact(struct Contact contacts[], int size);

// sortContacts
void sortContacts(struct Contact contacts[], int size);