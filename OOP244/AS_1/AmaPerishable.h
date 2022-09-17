// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project
#ifndef SICT_AMAPERISHABLE_H__
#define SICT_AMAPERISHABLE_H__
#include "AmaProduct.h"
#include "Date.h"
namespace sict{
	class AmaPerishable : public AmaProduct {
	private:
		Date expiry_;
	public:
		AmaPerishable(char fileTag ='P');
		const Date& expiry()const;
		void expiry(const Date &date); 
		std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& is);
	};
}
#endif
