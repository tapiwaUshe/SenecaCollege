// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 4
#ifndef SICT_PRODUCT_H__
#define SICT_PRODUCT_H__
#include "general.h"
#include "Streamable.h"
namespace sict{
	class Product : public Streamable{
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		virtual ~Product();
		Product();
		Product(const char* sku,const char* name, double price = 0, int qtyNeeded = 0, bool taxed = true);
		void copy(const Product& p);
		Product& operator=(const Product& p);

		void sku(const char* theSku);
		void price(double thePrice);
		void name(const char* theName);
		void taxed(bool tax);
		void quantity(int q);
		void qtyNeeded(int q);
		
		const char* sku()const;
		double price()const;
		const char* name()const;
		bool taxed()const;
		int quantity()const;
		int qtyNeeded()const;
		
		double cost()const;
		
		bool isEmpty()const;

		bool operator==(char* p);
		int operator+=(int p);
		int operator-=(int p);


		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& is);
	};
	double operator+=(double& value,const Product& p);
	std::ostream& operator<<(std::ostream& os, const Product& b);
	std::istream& operator>>(std::istream& is, Product& b);

}
#endif
