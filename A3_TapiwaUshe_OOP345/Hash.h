// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 0457687132

#pragma once
#include <vector>
#include "Person.h"
class Hash{
	int CONTAINER;
    std::vector<Person> *table;
	public:
		Hash(int max);
		void insertItem(Person);
		void searchItem(int);
		void deleteItem(int);
		void searchingCost(void);
		int hashFunction(int);
		void displayHash(void);
};
