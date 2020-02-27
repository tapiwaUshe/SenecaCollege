#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Perishable.h"
#include "Date.h"
#include "ErrorMessage.h"
#include "NonPerishable.h"
#include "Product.h"


using namespace std;

namespace sict {




	Perishable::Perishable() :NonPerishable('P') {

	}

	std::fstream & Perishable::store(std::fstream & file, bool newLine) const
	{
		NonPerishable::store(file, false);
		file << "," << m_expire << endl;

		return file;
	}



	std::fstream& Perishable::load(std::fstream& file) {
		

		char waste;
		int yy, mm, dd;
		NonPerishable::load(file); 
		file >> waste >> yy >> waste >> mm >> waste >> dd;
		file.ignore();
		Date temp(yy, mm, dd);
		expiry(temp); 
		file.ignore();
		return file;

	}



	std::ostream& Perishable::write(std::ostream& os, bool linear)const {
		NonPerishable::write(os, linear);
		if (isClear() && !isEmpty()) {
			if (linear == true) {
				m_expire.write(os);
			}
			else {
				os << endl << "Expiry date: ";
				m_expire.write(os);
			}
		}
		return os;
	}

	std::istream& Perishable::read(std::istream& is) {
		Date temp;

		NonPerishable::read(is);
	
			cout << "Expiry date (YYYY/MM/DD): ";
			 temp.read(is);
			if (temp.errCode() == CIN_FAILED) {
				message("Invalid Date Entry");
				is.setstate(ios::failbit);
			}
			else if (temp.errCode() == YEAR_ERROR) {
				message("Invalid Year in Date Entry");
				is.setstate(ios::failbit);
			}
			else if (temp.errCode() == MON_ERROR) {
				message("Invalid Month in Date Entry");
				is.setstate(ios::failbit);
			}
			else if (temp.errCode() == DAY_ERROR) {
				message("Invalid Day in Date Entry");
				is.setstate(ios::failbit);
			}
			else {
				m_expire = temp;
			}
			
			
		return is;
	}


	const Date& Perishable::expiry() const {
		return m_expire;
	}

	Product * CreatePerishable()
	{

		Perishable *p = new Perishable;
		return p;
	}

	void Perishable::expiry(const Date & expiry)
	{
		
		m_expire = expiry;
	}
}