// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project
#include <iomanip>
#include <iostream>
#include "Date.h"
#include "general.h"
using namespace std;
namespace sict{
	int Date::value()const{
		return year_ * 372 + mon_ * 31 + day_;
	}
	int Date::mdays()const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}


	Date::Date(){

		year_ = 0;
		mon_ = 0;
		day_ = 0;
		readErrorCode_ = NO_ERROR;


	}

	Date::Date(int year, int month, int day){

		year_ = year;
		mon_ = month;
		day_ = day;
		readErrorCode_ = NO_ERROR;


	}

	bool Date::operator==(const Date& D)const{

		if (year_ == D.year_&&mon_ == D.mon_&&day_ == D.day_){
			return true;
		}
		else {
			return false;
		}
	}

	bool Date::operator!=(const Date& D)const{

		if (year_ == D.year_&&mon_ == D.mon_&&day_ == D.day_){
			return false;
		}
		else {
			return true;
		}
	}

	bool Date::operator<(const Date& D)const{
		bool answer = false;

		if (year_ == D. year_ && mon_ == D.mon_ && day_ < D.mon_){
			answer = true;
		}

		else if (mon_ < D.mon_ && year_ == D.year_){
			answer = true;
		}

		else if (year_ < D.year_){
			answer = true;
		}
		else if (day_ < D.year_){
			answer = true;
		}

		return answer;

	}

	bool Date::operator>(const Date& D)const{
		bool answer = false;

		if (year_ == D.year_&&mon_ == D.mon_&&day_ > D.mon_){
			answer = true;
		}

		else if (mon_ > D.mon_ && year_ == D.year_){
			answer = true;
		}

		else if (year_ > D.year_){
			answer = true;
		}

		return answer;

	}

	bool Date::operator>=(const Date& D)const{
		bool answer = false;

		if (year_ == D.year_&&mon_ == D.mon_&&day_ >= D.mon_){
			answer = true;
		}

		else if (mon_ >= D.mon_ && year_ == D.year_){
			answer = true;
		}

		else if (year_ >= D.year_){
			answer = true;
		}

		return answer;
	}

	bool Date::operator<=(const Date& D)const{
		bool answer = false;

		if (year_ == D.year_&&mon_ == D.mon_&&day_ <= D.mon_){
			answer = true;
		}

		else if (mon_ <= D.mon_ && year_ == D.year_){
			answer = true;
		}

		else if (year_ <= D.year_){
			answer = true;
		}

		return answer;

	}

	int Date::errCode()const{
		return readErrorCode_;
	}

	bool Date::bad()const{
		if (readErrorCode_ != 0){
			return true;
		}
		else{
			return false;
		}

	}

	std::istream& Date::read(std::istream& istr){
		char character;
		std::cin >> year_ >> character >> mon_ >> character >> day_;

		if (istr.fail() != true){

			if (year_ < MAX_YEAR && year_ > MIN_YEAR && mon_ < MAX_MON && mon_ > MIN_MON && day_ < MAX_DAY && day_ > MIN_DAY){
				return istr;
			}

			if (year_ > MAX_YEAR || year_ < MIN_YEAR){
					readErrorCode_ = YEAR_ERROR;
			}
			else if (mon_ > MAX_MON || mon_ < MIN_MON){
					readErrorCode_ = MON_ERROR;
			}
			else if (day_ > MAX_DAY || day_ < MIN_DAY){
					readErrorCode_ = DAY_ERROR;
			}
		}
		else{
			readErrorCode_ = CIN_FAILED;
		}
		return istr; 
	}

	std::ostream& Date::write(std::ostream& ostr)const{
		cout << year_ << "/";
		cout.width(2);
		cout.fill('0');
		cout << mon_ <<  "/";
		cout.width(2);
		cout.fill('0');
		cout << day_;
		return ostr;
	}

	ostream& operator<<(std::ostream& os, const Date& b){
		b.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Date& b){
		b.read(is);
		return is;
	}

}


