// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 045787132
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "BSTNode.h"
#include "Person.h"

const int MAX_HASH_TABLE = 10;
class BSTHashtable{
	int size;
	std::vector<BSTNode*>* bucket;
	int hash(int x)
	{
		return (x % MAX_HASH_TABLE);
	}

	public:
		BSTHashtable(int vectorSize)
		{
			size = vectorSize;
            bucket = new std::vector<BSTNode*>(size);
		}

		void insert(Person& s)
		{
			int index = hash(s.getID());
			if (bucket->at(index) == nullptr) bucket->at(index) = new BSTNode(s);
			else bucket->at(index)->add(s);
		}

		void del(Person& s)
		{
			int index = hash(s.getID());
			if (bucket->at(index) == nullptr) 
				std::cout << "Invalid Data Entered, Please Enter The Name Again" << std::endl;
			else{
                std::vector<BSTNode*>::iterator it;
				for (it = bucket->begin(); it != bucket->end(); it++){
					if((*it) == nullptr) continue;
					if ((*it)->getPerson().getName() == s.getName()) break;
				}
				if(it != bucket->end()) bucket->erase(it);
			}
		}

		bool contains(Person& s)
		{
			int index = hash(s.getID());
			if (bucket->at(index) == nullptr) return false;
			std::cout << "ID: " << s.getID() << ", Name: " << s.getName() << " found at index: " << index << std::endl;
			std::cout << std::endl;
			return bucket->at(index)->contains(s);
		}

	void display()
	{
		for (unsigned int i = 0; i < bucket->size(); i++)
		{
            std::cout << std::endl;
            std::cout << i << ". ";
            std::cout << std::endl;

			if (bucket->at(i) != nullptr){
				BSTNode *node = bucket->at(i);
				displayTable(node);
			}
			std::cout << std::endl;
		}
	}


	void displayTable(BSTNode *node)
	{
		if (node != nullptr){
			displayTable(node->left);
			std::cout << "ID: ";
			std::cout << node->value.getID();
			std::cout << ", Name: ";
			std::cout << node->value.getName();
			displayTable(node->right);
		}
	}

	void searchingCost()
	{
		clock_t wBegin = clock();
		std::cout << std::endl;
		std::cout << "Calculate Worst Case " << std::endl;
		for (int i = 0; i < MAX_HASH_TABLE; i++) {
            std::vector<BSTNode*>::iterator it;
			for (it = bucket->begin(); it != bucket->end(); it++) {
				std::cout << "*";
			}
		}
		clock_t wEnd = clock();
		double wElapsed_Secs = double(wEnd - wBegin) / CLOCKS_PER_SEC;

		std::cout << std::endl;
		std::cout << wElapsed_Secs << "Sec" << std::endl;
		std::cout << std::endl;

		clock_t aBegin = clock();

		std::cout << "Calculate Aveage Case " << std::endl;
		int avgContainer = MAX_HASH_TABLE / 2;
		for (int i = 0; i < avgContainer; i++) {
            std::vector<BSTNode*>::iterator it;
			for (it = bucket->begin(); it != bucket->end(); it++) {
				std::cout << "*";
			}
		}

		clock_t aEnd = clock();
		double aElapsed_Secs = double(aEnd - aBegin) / CLOCKS_PER_SEC;
		std::cout << std::endl;
		std::cout << aElapsed_Secs << "Sec" << std::endl;
		std::cout << std::endl;
	}
};


