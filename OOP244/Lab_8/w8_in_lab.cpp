#include <iostream>
#include "SportCar.h"
#include "PickupTruck.h"
using namespace std;
using namespace sict;

void drive(Car& car){
	car.accelerate();
	car.brake();
	car.display(cout)<<endl;
}
void stop(Car& car){
	while (car.speed() > 0){
		car.brake();
	}
	car.display(cout)<<endl;
}

int main()
{
  SportCar Tesla(240, 2);
  PickupTruck Ford;
  Tesla.display(cout) << endl;
  Ford.display(cout) << endl;
  Ford.load("Bricks", 3500);
  drive(Tesla);
  drive(Ford);
  stop(Tesla);
  stop(Ford);
  Ford.unload();
  Tesla.display(cout) << endl;
  Ford.display(cout) << endl;
  return 0;
}
/* output
This sport car is carrying 2 passengers and is parked.
This pickup truck is not carrying any load and is parked.
This sport car is carrying 2 passengers and is traveling at a speed of 30 km/h.
This pickup truck is carrying 3500 kgs of Bricks, traveling at the speed of 15 km/h.
This sport car is carrying 2 passengers and is parked.
This pickup truck is carrying 3500 kgs of Bricks and is parked.
This sport car is carrying 2 passengers and is parked.
This pickup truck is not carrying any load and is parked.
*/