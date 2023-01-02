// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

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
// |        contents below...                        |
// +-------------------------------------------------+
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration

struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration

struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes below...             |
// +-------------------------------------------------+

// getName:

void getName(struct Name*);

// getAddress:

void getAddress(struct Address*);

// getNumbers:

void getNumbers(struct Numbers*);

// getContact:

void getContact(struct Contact*);




// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_
