
// Name: Tapi Z. Ushe
// Class: OOP345
// Assignment #3
#include <cstdlib>
#include <iostream>
#include <std::string>
#include <vector>
#include <algorithm>

class Family{
private:
	int age;
	float height;
	std::std::string name;
	Family* leftChild;
	Family* rightChild;

public:
	Family();
	Family(int _age, float _height, std::string _name);
	void setData(int _age, float _height, std::string _name);
	void setAge(int _age) {
		age = _age;
	}
	void setHeight(float _height) {
		height = _height;
	}
	void setName(std::string _name) {
		name = _name;
	}
	void setLChild(Family* lC){
		leftChild = lC;
	}
	void setRChild(Family* rC){
		rightChild = rC;
	}

	int getAge() { return age; }
	float getHeight() { return height; }
	std::string getName() { return name; }

	Family* getLChild(){
		return leftChild;
	}
	Family* getRChild(){
		return rightChild;
	}
};

Family::Family() age(0), height(0), name({""}){}
Family::Family(int _theAge, float _theHeight, std::string _theName){ setData(_theAge, _theHeight, _theName); }
void Family::setData(int _theAge, float _theHeight, std::string _theName)
{
	age = _theAge;
	height = _theHeight;
	name = _theName;
}

void insertNode(Family** root, int _age, float _height, std::string _name);
Family* binarySearchTree(Family* root, std::string _name);
void deleteNode(Family** root, std::string _name);
void display(Family* root);

void insertNode(Family** root, int _age, float _height, std::string _name) {
	Family* nNode;
	Family* qNode = nullptr;
	Family* pNode = *root;

	while(pNode != nullptr) {
		if(_name.compare(pNode->getName()) == 0){
			std::cout << "Duplicate Names" << std::endl;
			return;
		}

		qNode = pNode;
		if(_name.compare(pNode->getName()) < 0){
			std::cout << "Move Left" << std::endl;
			pNode = pNode->getLChild();
		}else if(_name.compare(pNode->getName()) > 0){
			std::cout << "Move Right" << std::endl;
			pNode = pNode->getRChild();
		}
	}

	nNode = new Family;
	nNode->setData(_age, _height, _name);
	nNode->setLChild(nullptr);
	nNode->setRChild(nullptr);

	if(qNode != nullptr){
		if(_name.compare(qNode->getName()) < 0){
			std::cout << "Left Node Read. " << std::endl;
			qNode->setLChild(nNode);
		}
		else if(_name.compare(qNode->getName()) > 0){
			std::cout << "Right Node Read. " << std::endl;
			qNode->setRChild(nNode);
		}
	}
	else *root = nNode;
}

Family* binarySearchTree(Family* root, std::string _name)
{
	while (root != nullptr)
	{
		if(_name.compare(root->getName()) == 0) return root;
		else if(_name.compare(root->getName()) < 0) root = root->getLChild();
		else if(_name.compare(root->getName()) > 0) root = root->getRChild();
	}
	return root;
}



void deleteNode(Family** root, std::string _name)
{
	Family* parent = nullptr;
	Family* pNode = *root;
	Family* childNode;
	Family* nSuccessor, *pSuccessor;

	while((pNode != nullptr) && _name.compare(pNode->getName()) != 0){
		parent = pNode;
		if(_name.compare(pNode->getName()) < 0) pNode = pNode->getLChild();
		else pNode = pNode->getRChild();
	}

	if(pNode == nullptr){
		std::cout << "Name Not Found." << std::endl;
		return;
	}

	if((pNode->getLChild() == nullptr) && (pNode->getRChild() == nullptr)){
		if(parent != nullptr){
			if (parent->getLChild() == pNode) parent->setLChild(nullptr);
			else parent->setRChild(nullptr);
		}
		else root = nullptr;
	}
	else if((pNode->getLChild() == nullptr) || (pNode->getRChild() == nullptr)) {
		if(pNode->getLChild() != nullptr)
			childNode = pNode->getLChild();
		else childNode = pNode->getRChild();

		if(parent != nullptr){
			if(parent->getLChild() == pNode) parent->setLChild(childNode);
			else parent->setRChild(childNode);
		}
		else *root = childNode;
	}
	else{
		pSuccessor = pNode;
		nSuccessor = pNode->getLChild();

		while(nSuccessor->getRChild() != nullptr){
			pSuccessor = nSuccessor;
			nSuccessor = nSuccessor->getRChild();
		}

		if(pSuccessor->getLChild() == nSuccessor) pSuccessor->getLChild();
		else pSuccessor->setRChild(nSuccessor->getLChild());
		pNode->setData(nSuccessor->getAge(), nSuccessor->getHeight(), nSuccessor->getName());
		pNode = nSuccessor;
	}
	delete pNode;
}


void display(Family* root)
{
	if(root != nullptr){
		display(root->getLChild());
		std::cout << root->getName() << ": " << root->getAge() << ": " << root->getHeight() << std::endl;
		display(root->getRChild());
	}
}

int main() {
	int uChoice, m_Age;
	float m_Height;
	std::string name_a;

	Family* root = nullptr;
	Family* locatedNode = nullptr;

	while (1){
		std::cout << std::endl;
		std::cout << "**************************" << std::endl;
		std::cout << "1. Insert Family Data" << std::endl;
		std::cout << "2. Update Family Data" << std::endl;
		std::cout << "3. Search Family Data" << std::endl;
		std::cout << "4. Display Family Data" << std::endl;
		std::cout << "5. Delete Family Data" << std::endl;
		std::cout << "6. Exit The Program" << std::endl;
		std::cout << "**************************" << std::endl;
		std::cout << "Choose Options (1-6): ";
		std::cin >> uOption;

		switch (uOptions) {
		case 1:
			std::cout << std::endl;
			std::cout << "Enter Age: ";
			std::cin >> m_Age;

			std::cin.ignore();

			std::cout << "Enter The Height: ";
			std::cin >> m_Height;

			std::cin.ignore();

			std::cout << "Enter The Name: ";
			getline(std::cin, name_a);
			std::cout << std::endl;

			insertNode(&root, m_Age, m_Height, name_a);
			break;
		case 2:
			std::cin.ignore();
			std::cout << std::endl;
			std::cout << "Enter The Name For Update: ";
			getline(std::cin, name_a);
			locatedNode = binarySearchTree(root, name_a);

			if (locatedNode != nullptr){
				std::cout << "Name: " << locatedNode->getName() << std::endl;
				std::cout << "Age: " << locatedNode->getAge() << std::endl;
				std::cout << "Height: " << locatedNode->getHeight() << std::endl;

				std::cout << "Update Age: ";
				std::cin >> m_Age;
				std::cin.ignore();

				std::cout << "Update Height: ";
				std::cin >> m_Height;

				locatedNode->setAge(m_Age);
				locatedNode->setHeight(m_Height);

				std::cout << "Update Complete." << std::endl;
				std::cout << std::endl;
			}
			else std::cout << "Cannot find a Data" << std::endl;
		break;

		case 3:
			std::cin.ignore();
			std::cout << std::endl;
			std::cout << "Enter The Name For Searching: ";
			getline(std::cin, name_a);
			locatedNode = binarySearchTree(root, name_a);

			if(locatedNode != nullptr) {
				std::cout << "[Found a data]" << std::endl;
				std::cout << "Name : " << locatedNode->getName() << std::endl;
				std::cout << "Age : " << locatedNode->getAge() << std::endl;
				std::cout << "Height : " << locatedNode->getHeight() << std::endl;
			}
			else std::cout << "Cannot find a Data" << std::endl;

		break;

		case 4:
			std::cout << "------------------" << std::endl;
			std::cout << "Displayed:" << std::endl;
			std::cout << "Name: Age: Height: " << std::endl;
			display(root);
		break;

		case 5:
			std::cin.ignore();
			std::cout << std::endl;
			std::cout << "Enter The Name For Deleting: ";
			getline(std::cin, name_a);
			deleteNode(&root, name_a);
		break;

		case 6:
			exit(1);
		break;

		default:
			std::cout << std::endl;
			std::cout << "Choose (1-6)." << std::endl;
			std::cout << std::endl;
		break;
		}
	}
	return 0;
}
