// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 045787132
#include "Person.h"
#include "Hash.h"
#include <iostream>
#include <ctime>
Hash::Hash(int max)
{
	this->CONTAINER = max;
    table = new std::vector<Person>[CONTAINER];
}

void Hash::insertItem(Person p)
{
	int index = hashFunction(p.getID());
	table[index].push_back(p);
}

void Hash::searchItem(int iD)
{
	int index = hashFunction(iD);
    std::vector<Person>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if ((*i).getID() == iD) break;
	}

	if(i != table[index].end())
		std::cout << "Item Found (ID: " << (*i).getID() << "Name: " << (*i).getName().c_str();
	else std::cout << "No Item Found" << std::endl;

}
void Hash::deleteItem(int iD)
{
	int index = hashFunction(iD);
    std::vector<Person>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if((*i).getID() == iD) break;
	}
	if(i != table[index].end()) table[index].erase(i);
}

void Hash::searchingCost(void)
{
	clock_t wBegin = clock();
	std::cout << "Calculate Worst Case ";
	for (int i = 0; i < CONTAINER; i++){
        std::vector<Person>::iterator itr;
		for (itr = table[i].begin(); itr != table[i].end(); itr++) std::cout << "*";
	}
	clock_t wEnd = clock();
	double wElapsed_Secs = double(wEnd - wBegin) / CLOCKS_PER_SEC;

	std::cout << wElapsed_Secs << "Sec" << std::endl;

	clock_t aBegin = clock();

	std::cout << "Calculate Aveage Case ";
	int avgContainer = CONTAINER / 2;
	for (int i = 0; i < avgContainer; i++) {
        std::vector<Person>::iterator itr;
		for (itr = table[i].begin(); itr != table[i].end(); itr++) {
			std::cout << "*";
		}
	}
	clock_t aEnd = clock();
	double aElapsed_Secs = double(aEnd - aBegin) / CLOCKS_PER_SEC;

	std::cout << aElapsed_Secs << "Sec" << std::endl;
}

int Hash::hashFunction(int x)
{
	return (x % CONTAINER);
}

void Hash::displayHash()
{
	for(int i = 0; i < CONTAINER; i++){
        std::cout << (i + 1);
		for(auto x : table[i])
            std::cout << " --> (ID: " << x.getID() << ", Name: " << x.getName().c_str() << ")";
        std::cout << std::endl;
        
    }
}
