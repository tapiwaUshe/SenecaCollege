// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 7
#include <iostream>
#include "Hero.h"
using namespace sict;

int main()
{
	Hero m("Mom", 20);
	m.display(std::cout);

	Hero d("Dad", 10);
	d.display(std::cout);

	m += 70;
	m.display(std::cout);

	d += 20;
	d.display(std::cout);

	if (m < d)
		std::cout << "Dad is stronger!" << std::endl;
	else
		std::cout << "Mom is stronger!" << std::endl;

	d -= 25;
	d.display(std::cout);

	m -= 200;
	m.display(std::cout);

	if (m < d)
		std::cout << "Dad is stronger!" << std::endl;
	else
		std::cout << "Mom is stronger!" << std::endl;
	return 0;
}
