// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 8
#ifndef SICT_SPORTCAR_H_
#define SICT_SPORTCAR_H_
#include "Car.h"
namespace sict{
  class SportCar : public Car{
	  int noOfPassengers_;
  public:
	  SportCar();
	  SportCar(int maxSpeed, int noOfPassengers);
    // implementations of Vehicle's pure virtual methods
	  void accelerate();
	  void brake();
	  std::ostream& display(std::ostream& ostr) const;
  };
}
#endif
