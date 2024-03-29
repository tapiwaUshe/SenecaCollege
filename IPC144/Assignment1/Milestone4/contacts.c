// Name: Tapi Z. Ushe
// Class: IPC144
// Assignment 1: MS4
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contacts.h"
void getName(struct Name *name)
{
	char option[2] = ("n");

	printf("Please enter the contact's first name: ");
	scanf("%30s", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		name->middleInitial[0] = '\0';
	}
	else {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6s", name->middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf("%35s", name->lastName);
}
///////////////////////////////////////////////////////////////////////////////////

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
///////////////////////////////////////////////////////////////////////////////////
void getAddress(struct Address *address)
{
	char option[2] = ("n");

	printf("Please enter the contact's street number: ");
	scanf("%d", &address->streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%40s", address->street);

	printf("Do you want to enter an appartment number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		address->apartmentNumber = -1;
	}
	else {
		printf("Please enter the contact's appartment number: ");
		scanf("%d", &address->apartmentNumber);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf("%40s", address->city);
}
///////////////////////////////////////////////////////////////////////////////////

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
///////////////////////////////////////////////////////////////////////////////////
void getNumbers(struct Numbers *numbers)
{
	char option[2] = ("n");

	//CELL
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		numbers->cell[0] = '\0';
	}
	else {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %20[^\n]", numbers->cell);
	}

	//HOME
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		numbers->home[0] = '\0';
	}
	else {
		printf("Please enter the contact's home phone number: ");
		scanf(" %20[^\n]", numbers->home);
	}

	//BUSINESS
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("\n%c", option);

	if ((*option == 'n') || (*option == 'N')) {
		numbers->business[0] = '\0';
	}
	else {

		printf("Please enter the contact's business phone number: ");
		scanf(" %20[^\n]", numbers->business);
	}
	printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////
