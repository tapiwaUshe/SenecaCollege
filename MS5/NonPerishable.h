
#ifndef SICT_NONPERISHABLE_H_
#define SICT_NONPERISHABLE_H_
#pragma once
#include "Product.h"
#include "ErrorMessage.h"

const int MMNL = 10;
const int MSL = 7;
const int MUL = 10;
const int MNL = 75;
const double TR = 1.13;

namespace sict {
	class NonPerishable :
		public Product
	{

	private:
		char m_type;
		char m_sku[MSL + 1];
		char* m_name;
		char m_unit[MUL + 1];
		int m_quantity;
		int m_Needquantity;
		double m_beforeTax;
		bool m_taxable;
		ErrorMessage m_err;

	protected:
		void name(const char*);
		const char* name()const;
		double cost()const;
		void message(const char*);
		bool isClear() const;

	public:
		char setType() const;
		char * setsku() const;
		double setTax() const;
		void setUnit(const char* unit);
		void price(double price);
		bool taxed(bool sd);
		void setSku(const char* sad);

		void quantityNeeded(int qtyNeeded);

		NonPerishable();
		NonPerishable(char as);
		NonPerishable(const char*, const char*, const char*, int = 0, bool = true, double = 0, int = 0);
		NonPerishable(const NonPerishable&);
		NonPerishable& operator=(const NonPerishable& cr);
		~NonPerishable();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear)const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool taxed() const;

		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		int operator+=(int);
		bool operator>(const Product&) const;
		
	};
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator >> (std::istream&, Product&);
	double operator+=(double&, const Product&);
	Product* CreateProduct();

}
#endif
