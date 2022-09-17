// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 7
#ifndef SICT_SUPERHERO_H_
#define SICT_SUPERHERO_H_
#include <iostream>
#include "Hero.h"
namespace sict{

	class SuperHero : public Hero{

	private:
		char name_[21];
		double strength_;
		double multiplier_;
	public:
		SuperHero();
		SuperHero(const char* name, double strength, double multi);
		double getStrength();
		void operator*=(SuperHero &b);
		void display(std::ostream&) const;
	};

};
#endif
