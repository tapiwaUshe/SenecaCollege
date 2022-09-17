// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 8
#ifndef SICT_TRUCK_H_
#define SICT_TRUCK_H_
#include "Car.h"

namespace sict{
  class PickupTruck : public Car{
	  int loadAmount_;
	  char loadedMaterial_[31];
  public:
	  PickupTruck();
	  void load(const char* loadedMaterial, int loadAmount);
	  void unload();
	  bool isEmpty()const;
    // implementations of Vehicle's pure virtual methods
	  void accelerate();
	  void brake();
	  std::ostream& display(std::ostream& ostr) const;

  };
}
#endif
