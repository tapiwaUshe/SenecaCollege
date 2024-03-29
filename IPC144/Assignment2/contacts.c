// Name: Tapi Z. Ushe
// Class: IPC144
// Assignment 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
void getName(struct Name *name)
{
	//char option[2] = ("n");
	int opt;

	printf("Please enter the contact's first name: ");
	scanf("%30s", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	opt = yes();
	//scanf("\n%c", option);

	//if ((*option == 'n') || (*option == 'N')) {
	if (opt == 0) {
	     name->middleInitial[0] = '\0';
	}
	else {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", name->middleInitial);
	}
	clearKeyboard();

	printf("Please enter the contact's last name: ");
	scanf("%35s", name->lastName);
	clearKeyboard();
}
///////////////////////////////////////////////////////////////////////////////////


// getAddress:
///////////////////////////////////////////////////////////////////////////////////
void getAddress(struct Address *address)
{
	//char option[2] = ("n");

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	//scanf("%d", &address->streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%[^\n]40s", address->street);   //using this way to avoid the problem of missing 'space' in names like "Keele Street"  
	//scanf(" %40s[^\n]", address->street); 
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	int opt = yes();
	//scanf("\n%c", option);

	//if ((*option == 'n') || (*option == 'N')) {
	if (opt == 0){
		address->apartmentNumber = 0;
	}
	else {
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		//scanf("%d", &address->apartmentNumber);
	}
	//clearKeyboard();

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf("%40s", address->city);
}
///////////////////////////////////////////////////////////////////////////////////


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
///////////////////////////////////////////////////////////////////////////////////
void getNumbers(struct Numbers *numbers)
{
	//char option[2] = ("n");
	int optYesNo;

	//CELL
	/*printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		numbers->cell[0] = '\0';
	}
	else {*/
		printf("Please enter the contact's cell phone number: ");
		scanf(" %20[^\n]", numbers->cell);
	//}

	//HOME
	printf("Do you want to enter a home phone number? (y or n): ");
	optYesNo = yes();
	//scanf("\n%c", option);

	//if ((*option == 'n') || (*option == 'N')) {
	if (optYesNo == 0){
		numbers->home[0] = '\0';
	}
	else {
		printf("Please enter the contact's home phone number: ");
		scanf(" %20[^\n]", numbers->home);
	}

	//BUSINESS
	printf("Do you want to enter a business phone number? (y or n): ");
	optYesNo = yes();
	//scanf("\n%c", option);

	//if ((*option == 'n') || (*option == 'N')) {
	if (optYesNo == 0) {
		numbers->business[0] = '\0';
	}
	else {

		printf("Please enter the contact's business phone number: ");
		scanf(" %20[^\n]", numbers->business);
	}
	//printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
///////////////////////////////////////////////////////////////////////////////////
void getContact(struct Contact *contact)
{
	struct Contact locContact;

	 getName(&locContact.name);
	 getAddress(&locContact.address);
	 getNumbers(&locContact.numbers);

	 *contact = locContact;
	// Use an open and close curly brace with a blank line
}
///////////////////////////////////////////////////////////////////////////////////
