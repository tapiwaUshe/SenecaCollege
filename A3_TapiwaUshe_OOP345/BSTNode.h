// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 045787132
#pragma once
#include "Person.h"

class BSTNode{
	Person value;
	BSTNode *left, *right;

	public:
		BSTNode(Person value)
		{
			this->value = value;
			left = nullptr;
			right = nullptr;
		}

	void add(Person& refVal)
	{
		if(refVal.getID() < this->value.getID()){
			if(left) left->add(value);
			else left = new BSTNode(value);
		}else if (this->value.getID() < refVal.getID()){
			if(right) right->add(value);
			else right = new BSTNode(value);
		}
	}

	bool contains(Person& refVal)
	{
		if (refVal.getID() < this->value.getID()){
			if(left) return left->contains(value);
			else return false;
		}else if (this->value.getID() < refVal.getID()){
			if(right) return right->contains(refVal);
			else return false;
		}else{ return true; }
	}

	Person getPerson() { return value; }
	friend class BSTHashtable;
};
