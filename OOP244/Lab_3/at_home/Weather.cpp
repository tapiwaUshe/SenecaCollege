// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 3
#include <iostream>
#include <cstring>
#include "Weather.h"

using namespace std;
// sict namespace
namespace sict{
	// set
	void Weather::set(const char* date, double hTemp, double lTemp){
		//store the date then the low temperture and lastly high temp
		strcpy(_date, date);
		_highTemp = hTemp;
		_lowTemp = lTemp;


	}
	// display
	void Weather::display() const{

		cout.setf(ios::left);
		cout.width(6);
		cout.fill('_');
		cout << _date;
		cout.setf(ios::right);
		cout.width(10);
		cout.fill('_');
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << _highTemp;
		cout.width(6);
		cout.fill('_');
		cout.setf(ios::fixed);
		cout.precision(1);
		cout << _lowTemp;
		cout << endl;


		//cout << _date << "______" << _highTemp << "__" << _lowTemp << endl;
	}

	const char* sict::Weather::date() const{
		return _date;
	}
	double sict::Weather::low() const{
		return _lowTemp;
	}
}
