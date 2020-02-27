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
#include <iomanip>
#include "Date.h"
using namespace std;
namespace sict {

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) {
		m_readErrorCode = errorCode;
	}

	Date::Date() {
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_readErrorCode = 0;
	}

	Date::Date(int year, int month, int day) {
		if (min_year <= year && year <= max_year) {
			if (1 <= month  && month <= 12) {
				if (1 <= day && day <= mdays(month, year)) {

					m_year = year;
					m_month = month;
					m_day = day;
					m_readErrorCode = 0;
				}
				else {
					m_year = 0;
					m_month = 0;
					m_day = 0;
					m_readErrorCode = 0;
				}
			}
			else {
				m_year = 0;
				m_month = 0;
				m_day = 0;
				m_readErrorCode = 0;
			}
		}
		else {
			m_year = 0;
			m_month = 0;
			m_day = 0;
			m_readErrorCode = 0;
		}
	}

	int Date::value()const
	{
		return m_year * 372 + m_month * 31 + m_day;
	}



	bool Date::operator==(const Date & rhs) const
	{
		return this->value() == rhs.value();
	}

	bool Date::operator!=(const Date & rhs) const
	{
		return this->value() != rhs.value();
	}

	bool Date::operator<(const Date & rhs) const
	{
		return this->value() < rhs.value();
	}

	bool Date::operator>(const Date & rhs) const
	{
		return this->value() > rhs.value();
	}

	bool Date::operator<=(const Date & rhs) const
	{
		return this->value() <= rhs.value();
	}

	bool Date::operator>=(const Date & rhs) const
	{
		return this->value() >= rhs.value();
	}

	int Date::errCode() const {

		return m_readErrorCode;
	}

	bool Date::bad() const {

		return errCode() != NO_ERROR;
	}

	std::istream & Date::read(std::istream & istr)
	{
		errCode(NO_ERROR);
		char s;

		istr >> this->m_year >> s >> this->m_month >> s >> this->m_day;

		if (istr.fail())
		{
			this->errCode(CIN_FAILED);
		}
		else if (min_year > this->m_year || this->m_year >= max_year)
		{
			this->errCode(YEAR_ERROR);
		}
		else if (1 > this->m_month || this->m_month >= 12)
		{
			this->errCode(MON_ERROR);
		}
		else if (this->m_day > this->mdays(m_month, m_year) || this->m_day <= 1)
		{
			this->errCode(DAY_ERROR);
		}
		else {
			this->errCode(NO_ERROR);
		}
		if (m_readErrorCode != 0)
		{
			m_year = 0;
			m_month = 0;
			m_day = 0;
		}
		return istr;
	}

	std::ostream & Date::write(std::ostream & ostr) const
	{
		ostr << setfill('0') << setw(1) << m_year << '/'
			<< setfill('0') << setw(2) << m_month << '/'
			<< setfill('0') << setw(2) << m_day;

		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Date& rhs) {
		rhs.read(istr);

		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& rhs) {
		rhs.write(ostr);
		return ostr;
	}
}