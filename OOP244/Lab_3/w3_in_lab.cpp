// // Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 3
#include <iostream>
#include "Weather.h"
using namespace std; using namespace sict;
int main(){
  int i; //  loop counter
  int n; //the count of days worth of weather
  // initialize the weather pointer here
  Weather* weather = nullptr;

  cout << "Weather Data" << endl
    << "=====================" << endl
    << "Days of Weather: ";
  cin >> n;
  cin.ignore();

  // allocate dynamic memory here
  weather = new Weather[n];

  for (i = 0; i < n; i++){
    char date_description[7];
    double high;
    double low;

    // ... add code to accept the user input
	cout << "Enter date: ";
	cin >> date_description;
	cout << "Enter high: ";
	cin >> high;
	cout << "Enter low : ";
	cin	>> low;
		           
    // for the weather array
	weather[i].set(date_description , high, low);

  }
  cout << endl
    << "Weather report:" << endl
    << "Date        high  low" << endl
    << "======================" << endl;
  
  for (i = 0; i < n; i++){
    weather[i].display();
  }
  
  // deallocate dynamic memory here
  delete [] weather;
  weather = nullptr;

  getchar();
  getchar();

  return 0;
}
