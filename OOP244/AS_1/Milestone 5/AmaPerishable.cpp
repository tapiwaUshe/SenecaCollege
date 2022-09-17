// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 5
#include "AmaPerishable.h"
#include <cstring>
#include <string> 
using namespace std;
namespace sict{
	//getter function for Expiry
	const Date& AmaPerishable::expiry()const{
		return expiry_;
	}
	void AmaPerishable::expiry(const Date& date){
		expiry_ = date;
	}
	AmaPerishable::AmaPerishable(char fileTag){
		AmaProduct::fileTag(fileTag);
	}

	std::fstream& AmaPerishable::store(std::fstream& file, bool addNewLine)const{
		AmaProduct::store(file, false);
		file << ',' << expiry_.getYear() << '/' << expiry_.getMon() << '/' << expiry_.getDay()
			<< endl;
		return file;
	}
	std::fstream& AmaPerishable::load(std::fstream& file){
		AmaProduct::ex(true);
		AmaProduct::load(file);
		char buf[2000];
		int ibuf = 0;
		file.ignore(1, ',');
		file.get(buf, 5, '/');
		ibuf = std::stoi(buf, 0);
		expiry_.year(ibuf);
		file.ignore(1, '/');
		file.get(buf, 3, '/');
		ibuf = std::stoi(buf, 0);
		expiry_.mon(ibuf);
		file.ignore(1, '/');
		file.get(buf, 3, '/');
		ibuf = std::stoi(buf, 0);
		expiry_.day(ibuf);

		expiry_.read(file);
		return file;
	}
	std::ostream& AmaPerishable::write(std::ostream& os, bool linear)const{
		AmaProduct::write(os, linear);
		if (err_.isClear()){
			if (!linear){
				os << "Expiry date: ";
			}
			expiry().Date::write(os);
		}
		return os;
	}
	std::istream& AmaPerishable::read(std::istream& is){
		int tempErr = NO_ERROR;
		int numDays;
		char msgT[30] = "No Error";
		Date temp;
		AmaProduct::read(is);
		if (err_.isClear()){
			cout << "Expiry date (YYYY/MM/DD): ";
			temp.read(is);
			if (!is.fail()){
				is.setstate(ios::failbit);
				if (temp.getYear() < MIN_YEAR || temp.getYear() > MAX_YEAR){
					tempErr = YEAR_ERROR;
					strcpy(msgT, "Invalid Year in Date Entry");
				}
				else if (temp.getMon() < 1 || temp.getMon() > 12){
					tempErr = MON_ERROR;
					strcpy(msgT, "Invalid Month in Date Entry");
				}
				else{
					numDays = temp.mdays();
					if (temp.getDay() > numDays || temp.getDay() < 1){
						tempErr = DAY_ERROR;
						strcpy(msgT, "Invalid Day in Date Entry");
					}
				}
			}
			else{
				tempErr = CIN_FAILED;
				strcpy(msgT, "Invalid Date Entry");
			}
			if (tempErr != NO_ERROR){
				err_.message(msgT);
			}
		}
		expiry(temp);
		return is;
	}
}
