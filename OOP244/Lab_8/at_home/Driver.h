// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 8
#ifndef SICT_DRIVER_H_
#define SICT_DRIVER_H_
#include "Car.h"
namespace sict{
  class Driver{
	  char name_[31];
	  Car& car_;

  public:
	  Driver(const char* name, Car& cRef);
	  void drive();
	  void stop();
	  void showStatus();
  };
}
#endif
