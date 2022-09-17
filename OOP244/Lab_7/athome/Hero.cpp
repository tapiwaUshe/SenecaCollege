// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 7
#include <iostream>
#include <cstring>
#include "Hero.h"
#define _CRT_SECURE_NO_WARNINGS 
namespace sict{

	Hero::Hero(){
		name_[0] = 0;
		strength_ = 0;
	}

	Hero::Hero(const char* name, double strength){
		strcpy(name_, name);
		strength_ = strength;
	}

	double Hero::getStrength() const{
		if (isEmpty()){
			return 0;
		}
		else{
			return strength_;
		}
	}

	bool Hero::isEmpty() const{
		if (name_[0] == '\0' && strength_ == 0){
			return true;
		}
		else{
			return false;
		}
	}

	void Hero::display(std::ostream& ostr) const{
		double temp = 0;
		if (!isEmpty()){
			temp = strength_;
			if (temp < 1){
				temp = 0;
			}
			std::cout << name_ << " - " << temp << '\n';
		}
	}

	void Hero::operator-=(double strength){
		strength_ = strength_ - strength;
	}

	void Hero::operator+=(double strength){
		strength_ = strength_ + strength;
	}

	bool operator<(const Hero& a, const Hero& b){
		if (a.getStrength() < b.getStrength()){
			return true;
		}
		else{
			return false;
		}
	}
	double Hero::Empty(){
		if (isEmpty()){
			strength_ = 0;
		}
		return strength_;
	}

}
