#ifndef SICT_Perishable_H__
#define SICT_Perishable_H__
#include <iostream>
#include "NonPerishable.h"
#include "Date.h"
#include "Product.h"
namespace sict {
	class Perishable : public NonPerishable {

	private:
		Date m_expire;
		
	public:
		Perishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;
		void expiry(const Date & expiry);
	
	
	};
	Product* CreatePerishable();
}
#endif