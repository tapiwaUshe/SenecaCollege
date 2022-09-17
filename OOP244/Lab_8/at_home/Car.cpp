// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 8
#include "Car.h"
namespace sict{

	void Car::speed(int value){
		speed_ = value;
		if (value > maxSpeed_){
			maxSpeed_ = value;
		}
		else{
			value = 0;
		}
	}
	int Car::maxSpeed()const{
		return maxSpeed_;
	}
	int Car::speed() const{
		return speed_;
	}
	Car::Car(int maxSpeed){
		maxSpeed_ = maxSpeed;
		speed_ = 0;
	}
	std::ostream& operator<<(std::ostream& os, Car& e){
		return e.display(os);
	}

}
