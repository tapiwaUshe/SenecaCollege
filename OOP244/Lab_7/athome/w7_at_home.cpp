// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 7
#include <iostream>
#include "SuperHero.h"
using namespace sict;

int main()
{
	SuperHero p;
	p.display(std::cout);

	SuperHero w("wimpy", -10,5);
	w.display(std::cout);

	SuperHero h("hercules", 100, 5 );
	h.display(std::cout);

	SuperHero hClone(h);
	hClone.display(std::cout);

	SuperHero sm("Superman", 130, 5);
	sm.display(std::cout);

	std::cout << "Superman battles Hercules clone!" << std::endl;
	sm *= hClone;

	sm.display(std::cout);
	hClone.display(std::cout);

	std::cout << "Hercules battles Superman!" << std::endl;
	h *= sm;

	sm.display(std::cout);
	hClone.display(std::cout);


	//reflection section
	Hero o = sm;  // Why does this compile?
	o.isEmpty();
	
	//uncomment to see what happens
	//Hero o2;
	//SuperHero sh = o2;

	return 0;
}


