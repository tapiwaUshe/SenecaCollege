// OOP345 Assignment_2
// Name: Tapi Z. Ushe
// Stu: 045787132

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "myFriends.h"

int main()
{
	int select;
	char input[10];

	initialize();

	while(1)
	{
		std::cout << "-------------------" << std::endl;
		std::cout << "Friend Contact List" << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "Please Select Menu" << std::endl;
		std::cout << "1. Register" << std::endl; //Insert Firends Information
		std::cout << "2. Delete" << std::endl; // Delete Friends Information
		std::cout << "3. Display" << std::endl; // Display All Friends Information
		std::cout << "4. Search" << std::endl; // Searching Friends Information
		std::cout << "Select Menu: ";
		std::cin >> select;

		switch(select)
		{
			case 0:
				std::cout << "Goodbye.\n";
			break;

			case 1:
				insert();
			break;

			case 2:
				deleteData();
			break;

			case 3:
				display();
			break;

			case 4:
				std::cout << std::endl;
				std::cout << "Friend(s) Search: " << std::endl;
				std::cout << "Enter Your Friend's Name: ";
				std::cin >> input;
				std::cout << std::endl;
				search(input);
			break;

			case 9:
			return 0;

			default:
				std::cout << std::endl;
				std::cout << "Invalid Menu Selected" << std::endl;
				std::cout << "Select between " << std::endl;
				std::cout << std::endl;
			break;
		}
	}
	return 0;
}