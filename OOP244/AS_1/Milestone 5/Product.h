// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 5
#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_
#include "Streamable.h"
#include "general.h"
namespace sict{
	class Product : public Streamable{
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		~Product();
		Product();
		Product(const char* sku, const char* name, bool taxed = true, double price = 0, int qtyNeeded = 0);
		Product(const Product& p);
		Product& operator=(Product& p);

		void sku(const char* theSku);
		void price(double thePrice);
		void name(const char* theName);
		void taxed(bool tax);
		void quantity(int q);
		void qtyNeeded(int q);

		const char* sku()const;
		double price()const;
		char* name()const;
		bool taxed()const;
		int quantity()const;
		int qtyNeeded()const;

		double cost()const;

		bool isEmpty()const;

		bool operator==(const char* p);
		int operator+=(int p);
		int operator-=(int p);

	};
	double operator+=(double& value, const Product& p);
	std::ostream& operator<<(std::ostream& os, Product& b);
	std::istream& operator>>(std::istream& is, Product& b);

}
#endif
