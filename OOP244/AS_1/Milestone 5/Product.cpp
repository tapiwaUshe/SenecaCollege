// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 5
#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"
using namespace std;
namespace sict{
	Product::Product(){
		sku_[0] = 0;
		name_ = nullptr;
		price_ = 0;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(const char* SKU, const char* NAME, bool TAXED, double PRICE, int QTYNEED){
		sku(SKU);
		name_ = new char[DISPLAY_LINE];
		name(NAME);
		price(PRICE);
		quantity(0);
		qtyNeeded(QTYNEED);
		taxed(TAXED);
	}

	Product::~Product(){
		name_ = nullptr;
		delete[] name_;
	}

	Product::Product(const Product& p){
		sku(p.sku());
		name(p.name());
		price(p.price());
		quantity(p.quantity());
		qtyNeeded(p.qtyNeeded());
		taxed(p.taxed());
	}
	Product& Product::operator=(Product& p){
		sku(p.sku());
		name(p.name());
		price(p.price());
		quantity(p.quantity());
		qtyNeeded(p.qtyNeeded());
		taxed(p.taxed());
		return *this;
	}

	void Product::sku(const char* theSku){
		strcpy(sku_, theSku);
	}

	void Product::price(double thePrice){
		price_ = thePrice;
	}
	void Product::name(const char* theName){
		name_ = new char[DISPLAY_LINE];
		strcpy(name_, theName);
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

	char* Product::name()const{
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
		double temp = 0;
		if (taxed_){
			temp = price_ * ( 1 + TAX);
			return temp;
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

	bool Product::operator==(const char* sku){
		return strcmp(sku_, sku) == 0;
	}
	int Product::operator+=(int p){
		quantity(quantity() + p);
		return quantity();
	}
	int Product::operator-=(int p){
		quantity(quantity() - p);
		return quantity();
	}

	double operator+=(double& value, const Product& p){
		value = p.quantity() * p.cost();
		return value;
	}

	std::ostream& operator<<(std::ostream& os, Product& b){
		return b.write(os, true);
	}
	std::istream& operator>>(std::istream& is, Product& b){
		return b.read(is);
	}
}
