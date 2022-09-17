// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 8
#ifndef SICT_VEHICLE_
#define SICT_VEHICLE_
#include <iostream>
namespace sict{
  class Vehicle  {
  public:
	  virtual void accelerate() = 0;
	  virtual void brake() = 0;
	  virtual std::ostream& display(std::ostream& ostr) const = 0;
  };
}
#endif
