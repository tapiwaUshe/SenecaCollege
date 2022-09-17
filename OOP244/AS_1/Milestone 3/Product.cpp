// Name: Tapi Z. Ushe
// Class: OOP244 Object Oriented Programming
// Assignment: Milestone 3
#include <iostream>
#include <fstream>
#include <cstring>
#include "Product.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
namespace sict{
	Product::Product(){
		sku_[0] = 0;
		name_ = nullptr;
		price_ = 0;
		qtyNeeded_ = 0;
		quantity_ = 0;
	}
	Product::Product(const char* psku, const char* pname, bool ptaxed, double pprice, int pqtyNeeded){
		sku(psku);
		name_ = new char[strlen(pname) + 1];
		name(pname);
		taxed(ptaxed);
		price(pprice);
		qtyNeeded(pqtyNeeded);
		quantity(0);

	}
	Product::~Product(){
		delete[] name_;
	}
	void Product::sku(const char* newSku){
		strcpy(sku_, newSku);
	}
	void Product::name(const char* newName){
		name_ = new char[strlen(newName) + 1];
		strcpy(name_, newName);
	}
	void Product::price(double newPrice){
		price_ = newPrice;
	}
	void Product::taxed(bool newTaxed){
		taxed_ = newTaxed;
	}
	void Product::qtyNeeded(int newQtyNeeded){
		qtyNeeded_ = newQtyNeeded;
	}
	void Product::quantity(int newQty){
		quantity_ = newQty;
	}
	const char* Product::sku()const{
		return sku_;
	}
	const char* Product::name()const{
		return name_;
	}
	double Product::price()const{
		return price_;
	}
	bool Product::taxed()const{
		return taxed_;
	}
	int Product::qtyNeeded()const{
		return qtyNeeded_;
	}
	int Product::quantity()const{
		return quantity_;
	}
	double Product::cost()const{
		double total;
		if (taxed()){
			total = price() + (price()*TAX);
		}
		else{
			total = price();
		}
		return total;
	}
	bool Product::isEmpty()const{
		return (name_ == nullptr);
	}
	Product::Product(const Product& item){
		sku(item.sku());
		name(item.name());
		price(item.price());
		taxed(item.taxed());
		quantity(item.quantity());
		qtyNeeded(item.qtyNeeded());
	}
	Product& Product::operator=(const Product& item){
		sku(item.sku());
		name(item.name());
		price(item.price());
		taxed(item.taxed());
		quantity(item.quantity());
		qtyNeeded(item.qtyNeeded());
		return *this;
	}
	bool Product::operator==(const char* str){
		return 0 == strcmp(sku_, str);
	}
	int Product::operator+=(int num){
		quantity(quantity() + num);
		return quantity();
	}
	int Product::operator-=(int num){
		quantity(quantity() - num);
		return quantity();
	}

	double operator+=(double& left, const Product& item){
		return left += item.quantity() * item.cost();
	}
	std::ostream& operator<<(std::ostream& os, Product& item){
		return item.write(os, true);
	}
	std::istream& operator>>(std::istream& is, Product& item){
		return item.read(is);
	}
}
