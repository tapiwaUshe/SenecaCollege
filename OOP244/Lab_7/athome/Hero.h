// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 7
#ifndef SICT_HERO_H_
#define SICT_HERO_H_
#include <iostream>
namespace sict{


	class Hero {

	private:
		char name_[21];
		double strength_;
	public:
		Hero();
		Hero(const char* name, double strength);
		double getStrength() const;
		bool isEmpty() const;
		void display(std::ostream& ostr) const;
		void operator-=(double strength);
		void operator+=(double strength);
		double Empty();
	};
	bool operator<(const Hero &a, const Hero &b);
};
#endif
