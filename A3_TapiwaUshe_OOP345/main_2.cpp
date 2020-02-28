// Name: Tapi Z. Ushe
// Class: OOP345
// Assignment #3
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <std::string>
#include <algorithm>

const int TABLE_MAX = 20;

// Create HashNode class to initialize hNode object with resources.
class HashNode
{
public:
	int sID;
	std::string name;
	float marksOOP345;

	HashNode(int stuID, std::string _name, float _grade345)
	{
		this->sID = stuID;
		this->name = _name;
		this->marksOOP345 = _grade345;
	}
};

// Child class of HashNode carries the information of a deleted node.
class DeletedNode: public HashNode
{
	static DeletedNode* value;
	DeletedNode(): HashNode(-1, "", -1.0f){}

	public:
		static DeletedNode* getNode(){
			if (value == nullptr) value = new DeletedNode();
			return value;
		}
};

// Global initialization of resource 'value' of the class "DeletedNode" to nullptr.;
DeletedNode* DeletedNode::value = nullptr;

class HashMap
{
	HashNode** pureHash;

	public:
		HashMap(){
			pureHash = new HashNode * [TABLE_MAX];
			for(int i = 0; i < TABLE_MAX; i++) pureHash[i] = nullptr;
		}

		~HashMap(){
			for(auto i = 0; i < TABLE_MAX; i++)
				if(pureHash[i] != NULL && pureHash[i] != DeletedNode::getNode()) delete pureHash[i];
			delete[] pureHash;
		}

		int hasher(int stuID){
			return stuID % TABLE_MAX;
		}

	void InsertHash(int stuID, std::string _name, float _markOOP345){
		int myHashValue = hasher(stuID), area = -1, removeIndex = -1;
		while (myHashValue != area && (pureHash[myHashValue] == DeletedNode::getNode() || pureHash[myHashValue] != NULL && pureHash[myHashValue]->studentID != stuID)){
			if(area == -1) area = myHashValue;
			if(pureHash[myHashValue] == DeletedNode::getNode())removeIndex = myHashValue;
			myHashValue = hasher(myHashValue + 1);
		}

		if(pureHash[myHashValue] == nullptr || myHashValue == area){
			if(removeIndex != -1) pureHash[removeIndex] = new HashNode(stuID, _name, _markOOP345);
			else pureHash[myHashValue] = new HashNode(stuID, _name, _markOOP345);
		}

		if(area != myHashValue){
			if(pureHash[myHashValue] != DeletedNode::getNode()){
				if (pureHash[myHashValue] != nullptr){
					if (pureHash[myHashValue]->studentID == stuID){
						pureHash[myHashValue]->name = _name;
						pureHash[myHashValue]->marksOOP345 = _markOOP345;
					}
				}
			}else pureHash[myHashValue] = new HashNode(stuID, _name, _markOOP345);
		}
	}

	int searchHash(int stuID)
	{
		int myHashValue = hasher(stuID), area = -1;

		while (myHashValue != area && (pureHash[myHashValue] == DeletedNode::getNode() || pureHash[myHashValue] != nullptr && pureHash[myHashValue]->studentID != stuID))
		{
			if (area == -1) area = myHashValue;
			myHashValue = hasher(myHashValue + 1);
		}

		if(pureHash[myHashValue] == nullptr || myHashValue == area) return -1;
		else return myHashValue;
	}

	void removeHash(int stuID)
	{
		int myHashValue = hasher(stuID), area = -1;

		while (myHashValue != area && (pureHash[myHashValue] == DeletedNode::getNode() || pureHash[myHashValue] != NULL && pureHash[myHashValue]->studentID != stuID))
		{
			if (area == -1) area = myHashValue;
			myHashValue = hasher(myHashValue + 1);
		}

		if(myHashValue != area && pureHash[myHashValue] != nullptr){
			delete pureHash[myHashValue];
			pureHash[myHashValue] = DeletedNode::getNode();
		}
	}

	void displayHash()
	{
		for(int i = 0; i < TABLE_MAX; i++)
		{
			std::cout << i;
			if(pureHash[i] != nullptr){
				std::cout << std::endl;
				std::cout << "ID: " << pureHash[i]->sID << ", ";
				std::cout << "Name: " << pureHash[i]->name << ", ";
				std::cout << "Grade: " << pureHash[i]->marksOOP345;
			}
			std::cout << std::endl;
		}
	}

	std::string getStuName(int stuID)
	{
		return pureHash[stuID]->name;
	}

	float getMarks(int stuID)
	{
		return pureHash[stuID]->marksOOP345;
	}
};


int main()
{
	HashMap myHash;
	int sID, uSelect, retVal;
	std::string name_a;
	float marksOOP345;

	while(1)
	{
		std::cout << std::endl;
		std::cout << "-------------------------------" << std::endl;
		std::cout << "I. Insert Student Data" << std::endl;
		std::cout << "II. Search Student Data" << std::endl;
		std::cout << "III. Delete Student Data" << std::endl;
		std::cout << "IV. Display Student Data" << std::endl;
		std::cout << "V. Exit." << std::std::endl;
		std::cout << "-------------------------------" << std::endl;
		std::cout << "Enter Option: ";

		std::cin >> uSelection;
		switch (uSelection)
		{
		case 1:

			std::cout << std::endl;
			std::cout << "Enter StudentID #: ";
			std::cin >> sID;
			std::cin.ignore();

			std::cout << "Enter Name: ";
			getline(std::cin, name_a);

			std::cout << "Enter Grade OOP345: ";
			std::cin >> marksOOP345;
			std::cout << std::endl;

			myHash.InsertHash(sID, name_a, marksOOP345);
			break;
		case 2:
			std::cin.ignore();
			std::cout << std::endl;
			std::cout << "Enter sID to Search: ";
			std::cin >> sID;

			if(myHash.searchHash(sID) == -1){
				std::cout << "Nothing returned for stuID: " << sID << std::endl;
				continue;
			}else{
				std::cout << "sID: " << sID << std::endl;
				retVal = myHash.searchHash(sID);
				std::cout << "StudentID: " << myHash.getStuName(retVal) << std::endl;
				std::cout << "OOP345 Grades: " << myHash.getMarks(retVal) << std::endl;
			}
			break;

		case 3:
			std::cin.ignore();
			std::cout << std::std::endl;
			std::cout << "Enter studentID to Delete: ";
			std::cin >> sID;
			myHash.removeHash(sID);
			break;

		case 4:
			myHash.displayHash();
			break;

		case 5:
			exit(1);
			break;

		default:
			std::cout << std::endl;
			std::cout << "Enter An Integer (1 - 5).\n";
		}
	}
	return 0;
}
