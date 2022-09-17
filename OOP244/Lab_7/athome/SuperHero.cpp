// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 7
#include <iostream>
#include <cstring>
#include "SuperHero.h"
#define _CRT_SECURE_NO_WARNINGS 
namespace sict{
	SuperHero::SuperHero(){
		name_[0] = 0;
		strength_ = 0;
		multiplier_ = 0;
	}

	SuperHero::SuperHero(const char* name, double strength, double multi){
		strcpy(name_,name);
		strength_ = strength;
		multiplier_ = multi;
	}

	double SuperHero::getStrength(){
		return strength_ * multiplier_;
	}

	void SuperHero::operator*=(SuperHero &b){
		if (getStrength() < b.getStrength()){
			b.strength_ = b.strength_ + strength_;
			strength_ = Empty();
		}
		else{
			strength_ = strength_ + b.strength_;
			b.strength_ = b.Empty();
		}
	}
	
	void SuperHero::display(std::ostream& ostr) const{
		if (strength_ < 1){
			std::cout << "deceased superhero!" << "\n";
		}
		else{
			std::cout << "living superhero!" << name_ << " - " << strength_ << "\n";
		}
	}

}
