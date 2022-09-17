// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 4
#include "Product.h"
#include <cstring>
namespace sict{

	Product::Product(){
		sku_[0] = 0;
		name_ = 0;
		price_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(const char* sku,const char* name, double price, int qtyNeeded, bool taxed){
		strcpy(sku_, sku);
		name_ = new char[DISPLAY_LINES];
		strcpy(name_, name);
		quantity_ = 0;
		price_ = price;
		qtyNeeded_ = qtyNeeded;
		taxed_ = taxed;
	}

	Product::~Product(){
		name_ = nullptr;
		delete[] name_;
	}

	void Product::copy(const Product& p){
		strcpy(sku_, p.sku_);
		name_ = new char[DISPLAY_LINES];
		strcpy(name_, p.name_);
		quantity_ = p.quantity_;
		price_ = p.price_;
		qtyNeeded_ = p.qtyNeeded_;
		taxed_ = p.taxed_;
		p.~Product();
	}
	Product& Product::operator=(const Product& p){
		copy(p);
		return *this;
	}

	void Product::sku(const char* theSku){
		strcpy(sku_,theSku);
	}

	void Product::price(double thePrice){
		price_ = thePrice;
	}
	void Product::name(const char* theName){
		name_ = new char[DISPLAY_LINES];
		if (name_ != nullptr){
			strcpy(name_, theName);
		}
	}

	void Product::taxed(bool tax){
		taxed_ = tax;
	}

	void Product::quantity(int q){
		quantity_ = q;
	}

	void Product::qtyNeeded(int q){
		qtyNeeded_ = q;
	}

	const char* Product::sku()const{
		return sku_;
	}

	double Product::price()const{
		return price_;
	}

	const char* Product::name()const{
		return name_;
	}

	bool Product::taxed()const{
		return taxed_;
	}

	int Product::quantity()const{
		return quantity_;
	}
	int Product::qtyNeeded()const{
		return qtyNeeded_;
	}
	double Product::cost()const{
		if (taxed_){
			return price_ * TAX;
		}
		else{
			return price_;
		}
	}

	bool Product::isEmpty()const{
		if (sku_[0] == 0 && name_ == nullptr && price_ == 0 && quantity_ == 0 && qtyNeeded_ == 0){
			return true;
		}
		else{
			return false;
		}
	}

	bool Product::operator==(char* sku){
		return strcmp(sku_, sku) == 0;
	}
	int Product::operator+=(int p){
		return quantity_ + p;
	}
	int Product::operator-=(int p){
		return quantity_ - p;
	}

	double operator+=(double& value, const Product& p){
		double temp = 0;
		temp = p.quantity() * p.cost();
		return temp;
	}

	std::ostream& operator<<(std::ostream& os, const Product& b){
		return b.write(os,true);
	}
	std::istream& operator>>(std::istream& is, Product& b){
		return b.read(is);
	}

	std::ostream& Product::write(std::ostream& os, bool linear)const{
		return isEmpty() ? os : (os << sku() << ": " << name() << ", qty: "
			<< quantity() << ", qtyNeeded:" << qtyNeeded()
			<< ", Cost: "  << cost());
	}

	std::istream& Product::read(std::istream& is){
		char buf[2000];
		double dbuf;
		int ibuf;
		std::cout << "Sku: ";
		is >> buf;
		sku(buf);
		std::cout << "Name (no spaces): ";
		is >> buf;
		name(buf);
		std::cout << "Qty: ";
		is >> ibuf;
		quantity(ibuf);
		std::cout << "Qty Needed: ";
		is >> ibuf;
		qtyNeeded(ibuf);
		std::cout << "Is taxed? (1/0): ";
		is >> ibuf;
		taxed(bool(ibuf));
		std::cout << "Price: ";
		is >> dbuf;
		price(dbuf);
		return is;
	}
}
