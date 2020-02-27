// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iostream>

#ifndef SICT_DATE_H
#define SICT_DATE_H
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
#define min_year 2000
#define max_year 2030

using namespace std;

namespace sict {
	
	class Date {

	private:
		int m_year;
		int m_month;
		int m_day;
		int m_readErrorCode;
		int mdays(int month, int year)const;
		void errCode(int errorCode);
		int value() const;
	public:
		Date();
		Date(int year, int mon, int day);
		bool operator==(const Date& rhs)const;
		bool operator!=(const Date& rhs)const;
		bool operator<(const Date& rhs)const;
		bool operator>(const Date& rhs)const;
		bool operator<=(const Date& rhs)const;
		bool operator>=(const Date& rhs)const;

		int errCode() const;
		bool bad() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};


	std::istream& operator>>(std::istream& istr, Date& rhs);
	std::ostream& operator<<(std::ostream& ostr, const Date& rhs);


}
#endif