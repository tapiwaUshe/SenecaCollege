// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 3
#define NUMBEROFELEMENTS 3
namespace sict{
	// sict namespace
	class Weather{
		// member variables
		char _date[8];
		double _highTemp;
		double _lowTemp;
	public:
		// member function
		void set(const char* date, double hTemp, double lTemp);
		void display() const;
		const char* date() const;
		double low() const;
	};
}
