#define _CRT_SECURE_NO_WARNINGS
#include "NonPerishable.h"
#include "ErrorMessage.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>





using namespace std;
namespace sict {
	void NonPerishable::name(const char* name)
	{
		if (name == nullptr) {
			delete[] m_name;
			
		}

		else
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_name[strlen(name) + 1] = '\0';
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
		m_type = '\0';
		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';
		m_quantity = 0;
		m_Needquantity = 0;
		m_beforeTax = 0;

	}

	NonPerishable::NonPerishable(char spectype)
	{
		m_type = spectype;
		m_sku[0] = '\0';
		m_name = nullptr;
		m_unit[0] = '\0';
		m_quantity = 0;
		m_Needquantity = 0;
		m_beforeTax = 0;
	}

	NonPerishable::NonPerishable(const char * sku, const char *crname, const char * na, int prodOnHand, bool taxable, double pricebt, int numNeeded)
	{
		
		m_type = '\0';
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
		//do i need the er
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
		if (newLine)
			file << 'N' << ',' << m_sku << ',' << m_name << ',' << m_beforeTax << ',' << m_taxable << ',' << m_quantity << ',' << m_unit << ',' << m_Needquantity<< endl;
		else
			file << 'P' << ',' << m_sku << ',' << m_name << ',' << m_beforeTax << ',' << m_taxable << ',' << m_quantity << ',' << m_unit << ',' << m_Needquantity;
		return file;
	}

	std::fstream & NonPerishable::load(std::fstream & file)
	{
		char temp_sku[21], temp_name[21];

		
		
		string temp_unit;
		double temp_price;
		bool temp_tax;
		int temp_qty;
		int temp_qtyN;
		char comma;


		file.getline(temp_sku, MSL + 1, ',');
		strcpy(m_sku, temp_sku);

		file.getline(temp_name, MMNL + 1, ',');
		name(temp_name);

		file >> temp_price >> comma >> temp_tax >> comma >> temp_qty >> comma  ;
		
		getline(file, temp_unit, ',');
		file >> temp_qtyN;
		strcpy(m_sku, temp_sku);;
		name(temp_name);
		price(temp_price);
		taxed(temp_tax);
		quantity(temp_qty);
		setUnit(temp_unit.c_str());
		quantityNeeded(temp_qtyN);
		
		return file;
	}

	std::ostream & NonPerishable::write(std::ostream & os, bool linear) const
	{
		if (!(m_err.isClear())) {
			os << m_err.message();
		}
		 else if (linear) {
			os << left << setw(MSL) << setfill(' ') << m_sku << "|";

			os << left<< setw(20) << setfill(' ') << m_name << "|";

			os << right << setw(7) << setfill(' ') << fixed << setprecision(2) << (total_cost()) << "|";

			os << right << setw(4) << setfill(' ') << m_quantity << "|";

			os << left << setw(10) << setfill(' ') << m_unit << "|";
			
			os << right << setw(4) << setfill(' ') << m_Needquantity << "|";

	
		}
		 else if (linear == false)
		{
			
			 os << left << setw(4)  << setfill(' ') << "Sku: " << m_sku << endl;

			os << left << setw(4) <<  setfill(' ') << "Name: " << m_name << endl;

			os << left << setw(4) << fixed << setprecision(2) << setfill(' ')  << "Price: " << m_beforeTax << endl;

			if (taxed()) {
				os << setw(10) << "Price after tax: " << total_cost() << endl;
			}
			else {
				os << "Price after tax: N/A" << endl;
			}
			os << setw(4) << "Quantity On Hand: " << m_quantity <<" " << m_unit << endl;

			os <<  setw(4) << "Quantity Needed: " << m_Needquantity;
		}
		return os;
	}

	std::istream & NonPerishable::read(std::istream & is)
	{
		char sku_temp[MSL + 1];
		char name_temp[MSL + 1];
		double price_temp;
		char unit_temp[MSL + 1];
		char tax_temp;
		int qty_temp;
		int Needqty_temp;

		if (is.fail()) {
			return is;
		}
		

		cout << " Sku: ";
		is >> sku_temp;

		strcpy(m_sku, sku_temp);

		cout << " Name: ";
		is >> name_temp;

		name(name_temp);

		cout << " Unit: ";
		is >> unit_temp;

		strcpy(m_unit, unit_temp);

		cout << " Taxed? (y/n): ";
		is >> tax_temp;


		if (tax_temp == 'y' || tax_temp == 'n' || tax_temp == 'Y' || tax_temp == 'N')
		{
			 if(tax_temp == 'y' || tax_temp == 'Y')
			 {
				 m_taxable = true;
			 }
			 else 
			 {
				 m_taxable = false;
			 }


			cout << " Price: ";
			is >> price_temp;

			m_beforeTax = price_temp;

			if (!(is.fail())) {

				cout << "Quantity On hand: ";
				is >> qty_temp;
				m_quantity = qty_temp;



				if (!(is.fail())) {

					cout << "Quantity Needed: ";
					is >> Needqty_temp;
					m_Needquantity = Needqty_temp;



					if (!(is.fail())) {

						m_err.clear();
						return is;

					}

				else {

					m_err.message("Invalid Quantity Needed Entry");
					is.clear();
					is.setstate(ios::failbit);
				}
			}



			else {

				m_err.message("Invalid Quantity Entry");
				is.clear();
				is.setstate(ios::failbit);
			}
		}

		else {

			m_err.message("Invalid Price Entry");
			is.clear();
			is.setstate(ios::failbit);
		}
	}

		else {

			m_err.message("Only (Y)es or (N)o are acceptable");
			is.clear();
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

	char NonPerishable::setType() const
	{
		return m_type;
	}

	char * NonPerishable::setsku() const
	{
		return (char *)m_sku;
	}

	double NonPerishable::setTax() const
	{
		return m_beforeTax;
	}

	bool NonPerishable::taxed(bool sd) {
		return m_taxable  = sd;
	}


	void NonPerishable::quantityNeeded(int qtyNeeded) {
		m_Needquantity = qtyNeeded;
	}

	void  NonPerishable::setSku(const char*  sad) 
	{
		strcpy(m_sku, sad);
	}

	
	
	bool NonPerishable::taxed() const {
		return m_taxable;
	}

	void NonPerishable::setUnit(const char* unit) {
		strncpy(m_unit, unit, MUL);
	}

	void NonPerishable::price(double price) {
		m_beforeTax = price;
	}

	
	NonPerishable::~NonPerishable()
	{

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