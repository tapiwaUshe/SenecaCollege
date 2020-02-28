// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 045787132

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include "BSTNode.h"
#include "BSTHash.h"
#include "Person.h"

int main()
{
    // Declare Variables.
	BSTHashtable table(MAX_HASH_TABLE);
    int cinID, choice;
    std::string cinName;
    Person cinPerson;
    
	while (1)
    {
		std::cout << "-----MENU------" << std::endl;
		std::cout << "1. Insert Record" << std::endl;
		std::cout << "2. Search Node" << std::endl;
		std::cout << "3. Display Record" << std::endl;
		std::cout << "4. Delete" << std::endl;
		std::cout << "5. Searching Cost" << std::endl;
		std::cout << "6. Exit" << std::endl;
		std::cout << "----------------" << std::endl;
		std::cout << "SELECT MENU: ";
		std::cin >> choice;

		switch(choice)
		{
		case 1:
			std::cout << std::endl;
			std::cout << "Enter The ID: ";
			std::cin >> cinID;
			cinPerson.setID(cinID);

			std::cin.ignore();

			std::cout << "Enter The Name: ";
                getline(std::cin, cinName);
			std::cout << std::endl;

			cinPerson.setName(cinName);
			table.insert(cinPerson);
			break;

		case 2:
            std::cin.ignore();
            std::cout << std::endl;
            std::cout << "Enter The ID For Searching: ";
            std::cin >> cinID;
			cinPerson.setID(cinID);
			if (table.contains(cinPerson) == 0){
				std::cout << "Data " << cinID <<  " not found in the hash table" << std::endl;
				std::cout << std::endl;
				continue;
			}
			break;

		case 3:
			std::cout << "Display Data: " << std::endl;
			std::cout << "------------------" << std::endl;
			table.display();
			break;

		case 4:
            std::cin.ignore();
            std::cout << std::endl;
            std::cout << "Enter The Name For Deleting: ";
            getline(std::cin, cinName);
            cinPerson.setName(cinName);
            table.del(cinPerson);
            std::cout << cinName << " Deleted" << std::endl;
            std::cout << std::endl;
			break;

		case 5:
            table.searchingCost();
            break;

		case 6:
            exit(1);

		default:
            std::cout << "Invalid Selection, Please Try Again" << std::endl;
		}
	}
	return 0;
}
