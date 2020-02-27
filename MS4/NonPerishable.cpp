#define _CRT_SECURE_NO_WARNINGS
#include "NonPerishable.h"
#include "ErrorMessage.h"
#include "iomanip"
#include <iostream>
#include <fstream>
#include <cstring>




using namespace std;
namespace sict {
	void NonPerishable::name(const char* name)
	{
		if (name == nullptr) {
			std::cout << "Value of ptr is: " << m_name << std::endl;
			delete[] m_name;
			std::cout << "After delete" << std::endl;
			m_name = nullptr;
		}

		if (name != nullptr)
		{
			this->m_name = new char[strlen(name) + 1];
			strcpy(this->m_name, name);

		}


	}

	const char * NonPerishable::name() const
	{
		if (this->m_name == nullptr)
		{
			return nullptr;
		}
		return this->m_name;
	}

	double NonPerishable::cost() const
	{

		if (taxed())
		{
			return m_beforeTax * TR;
		}
		else
		{
			return m_beforeTax;
		}
	}

	void NonPerishable::message(const char * errormessage)
	{
		m_err.message(errormessage);
	}

	bool NonPerishable::isClear() const
	{
		return m_err.isClear();
	}

	NonPerishable::NonPerishable()
	{
		type = '\0';
		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';
		m_quantity = 0;
		m_Needquantity = 0;
		m_beforeTax = 0;

	}

	NonPerishable::NonPerishable(char spectype)
	{
		type = '\0';
		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';
		m_quantity = 0;
		m_Needquantity = 0;
		m_beforeTax = 0;
	}

	NonPerishable::NonPerishable(const char * sku, const char *crname, const char * na, int prodOnHand, bool taxable, double pricebt, int numNeeded)
	{
		type = '\0';
		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';
		m_quantity = 0;
		m_Needquantity = 0;
		m_beforeTax = 0;

		strcpy(m_sku, sku);
		name(crname);
		strcpy(m_unit, na);
		m_quantity = prodOnHand;
 		m_taxable = taxable;
		m_beforeTax = pricebt;
		m_Needquantity = numNeeded;

	}

	NonPerishable::NonPerishable(const NonPerishable & pr)
	{
		*this = pr;
		//do i need the error message
	}

	NonPerishable& NonPerishable::operator=(const NonPerishable & cr)
	{
		strcpy(m_sku, cr.m_sku);
		name(cr.m_name);
		strcpy(m_unit, cr.m_unit);
		m_quantity = cr.m_quantity;
		m_Needquantity = cr.m_Needquantity;
		m_beforeTax = cr.m_beforeTax;
		m_taxable = cr.m_taxable;

		return *this;
	}


	std::fstream & NonPerishable::store(std::fstream & file, bool newLine) const
	{
		file << this->type << ',' << this->m_sku
			<< ',' << this->name() << ',' << this->m_beforeTax
			<< ',' << this->total_cost() << ',' << this->quantity() << endl;
		return file;
	}

	std::fstream & NonPerishable::load(std::fstream & file)
	{
		char temp1[21];
		double temp2;
		int temp3;



		file.getline(temp1, MSL + 1, ',');
		strcpy(m_sku, temp1);
		file.getline(temp1, strlen(m_name), ',');
		strcpy(m_name, temp1);
		file >> temp2;
		m_beforeTax = temp2;

		file.ignore();
		file >> temp3;
		if (temp3 == 1)
			m_taxable = true;
		else
			m_taxable = false;
		file.ignore();
		file >> temp3;
		quantity(temp3);
		file.ignore();
		return file;
	}

	std::ostream & NonPerishable::write(std::ostream & os, bool linear) const
	{

		if (linear == true) {
			os << left << setw(MSL) << m_sku << "|";

			os << left << setw(20) << name() << "|";

			os << right << setw(7) << total_cost() << "|";
		}
		else if (m_taxable == true)
		{
			os << right << setw(2) << type << "|";
			os << right << setw(4) << quantity() << "|";
			os << right << setw(9) << fixed << setprecision(2) << (total_cost()) << "|";
		}
		return os;
	}

	std::istream & NonPerishable::read(std::istream & is)
	{
		char sku_temp[MSL + 1];
		char name_temp[MSL + 1];
		double price_temp;
		char tax_temp;

		if (is.fail()) {
			return is;
		}
		else {
			cout << "Item Entry:" << endl;

			cout << "Sku: ";
			is >> sku_temp;
		}
		if (!(is.fail())) {
			strcpy(m_sku, sku_temp);

			cout << "Name:" << endl;
			is >> name_temp;
		}

		if (!(is.fail())) {
			strcpy(m_name, name_temp);

			cout << "Price: ";
			is >> price_temp;
		}

		if (is.fail()) {
			cout << "Invalid Price Entry" << endl;
		}

		else {

			m_beforeTax = price_temp;
		}

		if (price_temp > 0) {
			m_err.clear();
		}

		if (m_err.isClear()) {
			cout << "Taxed: ";
			is >> tax_temp;
		}

		if (tax_temp == 1 || tax_temp == 0)
		{
			m_taxable = tax_temp;

		}

		else {
			cout << "Invalid Taxed Entry, (y)es or (n)o" << endl;
			is.setstate(ios::failbit);
		}
		return is;
	}



	bool NonPerishable::operator==(const char * ProductSku) const
	{
		if (strcmp(m_sku, ProductSku) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	double NonPerishable::total_cost() const
	{
		double totalcost = 0.0;
		
		totalcost = cost()*quantity();
		return totalcost;
	}

	void NonPerishable::quantity(int numProduct)
	{
		this->m_quantity = numProduct;  
	}

	bool NonPerishable::isEmpty() const
	{
		if (m_sku[0] == '\0' && m_name == nullptr && m_taxable == false && m_quantity == 0 && m_Needquantity == 0)
		{

			return true;

		}
		else
		{

			return false;

		}

	}

	int NonPerishable::qtyNeeded() const
	{
		return this->m_Needquantity;
	}

	int NonPerishable::quantity() const
	{
		return this->m_quantity;
	}

	bool NonPerishable::operator>(const char * productsku) const
	{
		if (strcmp(m_sku, productsku) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int NonPerishable::operator+=(int UpdatedUnits)
	{
		if (UpdatedUnits > 0)
		{
			return (this->m_quantity += UpdatedUnits);
		}
		else
		{
			return (this->m_quantity);
		}
	}

	bool NonPerishable::operator>(const Product & pr) const
	{
		if (strlen(pr.name()) > strlen(this->m_name))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool NonPerishable::taxed() const {
		return m_taxable;
	}
	NonPerishable::~NonPerishable()
	{
		delete[]m_name;
	}

	std::ostream & operator<<(std::ostream & os, const Product & pr)
	{
		return pr.write(os, true);
		
	}

	std::istream & operator >> (std::istream & is, Product & pr)
	{
		return pr.read(is);
		
	}

	double operator+=(double & price, const Product & pr)
	{
		return price += pr.total_cost();
	}

	NonPerishable::Product* CreateProduct()
	{
		NonPerishable *p = new NonPerishable;
		return p;
	}
}