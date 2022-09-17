// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project
#include "AmaPerishable.h"
#include <cstring>
using namespace std;
namespace sict{
	const Date& AmaPerishable::expiry()const{
		return expiry_;
	}
	void AmaPerishable::expiry(const Date& date){
		expiry(date);
	}
	AmaPerishable::AmaPerishable(char fileTag){
		setFileTag(fileTag);
	}
	std::fstream& AmaPerishable::store(std::fstream& file, bool addNewLine)const{
		AmaProduct::store(file, false);
		return file;
	}
	std::fstream& AmaPerishable::load(std::fstream& file){
		AmaProduct::load(file);
		expiry_.read(file);
		return file;
	}
	std::ostream& AmaPerishable::write(std::ostream& os, bool linear)const{
		AmaProduct::write(os, linear);
		if (err_.isClear()){
			if (!linear){
				os << "Expiry date: ";
			}
		}
		return expiry().Date::write(os);
	}
	std::istream& AmaPerishable::read(std::istream& is){
		int tempErr = NO_ERROR;
		int numDays;
		char msgT[25]="No Error";
		Date temp;
		AmaProduct::read(is);
		if (err_.isClear()){
			cout << "Expriy date (YYYY/MM/DD): ";
			temp.Date::read(is);
			if (!is.fail()){
				is.setstate(ios::failbit);
				if (temp.year_ < MIN_YEAR || temp.year_ > MAX_YEAR){
					tempErr = YEAR_ERROR;
					strcpy(msgT, "Invalid Year in Date Entry");
				}
				else if (temp.mon_ < 1 || temp.mon_ > 12){
					tempErr = MON_ERROR;
					strcpy(msgT, "Invalid Month in Date Entry");
				} else{
					numDays = temp.mdays();
					if (temp.day_ > numDays || temp.day_ < 1){
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
