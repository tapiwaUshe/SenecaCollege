// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 3
#include <iostream>
#include <cstring>
#include "Weather.h"
using namespace std;
using namespace sict;

double findLow(const char* date, const Weather *data, int dataSize);

int main(){
	int i; //  loop counter
	int n; //the count of days worth of weather
	// create the weather pointer here
	Weather* weather = nullptr;

	cout << "Weather Data\n";
	cout << "=====================" << endl;
	cout << "Days of Weather: ";
	cin >> n;
	cin.ignore();

	// allocate dynamic memory here
	weather = new Weather[n];

	for (i = 0; i < n; i++){
		char date_description[7];
		double high;
		double low;

		cout << "Enter date: ";
		cin >> date_description;
		cout << "Enter high: ";
		cin >> high;
		cout << "Enter low : ";
		cin >> low;

		// for the weather array
		weather[i].set(date_description, high, low);

	}
	cout << endl
		<< "Weather report:" << endl
		<< "Date        high  low" << endl
		<< "======================" << endl;

	for (i = 0; i < n; i++){
		weather[i].display();
	}

	char query[7];
	cout << endl << "Enter the date you are looking for: ";
	//accept user input for the date to find
	//(in this example stored in char query[7])
	// and display the found low temprature.
	cin >> query;
	//cin.getline(query, 7, '\n');
	
	double low = findLow(query, weather, n);
	cout << "Low temperature: " << low << endl;

	// deallocate dynamic memory here
	delete[] weather;
	weather = nullptr;

	getchar();
	getchar();

	return 0;

}

double findLow(const char* date, const Weather *data, int dataSize){
	//double low = findLow(query, weather, n);
	int i;
	double temp = 0;

	//cout << date;	

	for (i = 0; i < dataSize; i++){
		if (strcmp(date, data[i].date()) == 0){
		//cout << correct << endl;
			temp = data[i].low();
		//	cout << temp << endl;
		}
	}
	
	return temp;
}
