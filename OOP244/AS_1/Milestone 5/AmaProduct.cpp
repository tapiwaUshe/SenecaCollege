// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 5
#include "AmaProduct.h"
#include "Date.h"
#include <string> 
#include <cstring>
#define TAB '\t'
using namespace std;
namespace sict{
	AmaProduct::AmaProduct(char tagfile){
		fileTag_ = tagfile;

	}

	const char AmaProduct::fileTag()const{
		return fileTag_;
	}
	void AmaProduct::fileTag(char a){
		fileTag_ = a;
	}

	const char*AmaProduct::unit()const{
		return unit_;
	}
	void AmaProduct::unit(const char* value){
		strcpy(unit_, value);
	}

	const bool AmaProduct::ex()const{
		return ex_;
	}
	void AmaProduct::ex(bool a){
		ex_ = a;
	}
	std::fstream& AmaProduct::store(std::fstream& file, bool addNewLine)const{
		char* temp = new char[strlen(unit()) + 1];
		strcpy(temp, unit());
		if (addNewLine == false){
			temp[0] = toupper(temp[0]);
		}

		file << fileTag_ << ',' << sku() << ',' << name() << ',' << price() << ','
			<< int(taxed()) << ',' << quantity() << ',' << temp << ',' << qtyNeeded();

		if (addNewLine == true)
			file << endl;

		return file;
	}
	std::fstream& AmaProduct::load(std::fstream& file){
		char buf[2000];
		double dbuf = 0;
		int ibuf = 0;
		char skuL[2000];
		if (file.is_open()){
			while (file.good() && !file.eof()){

				file.get(buf, 7, ',');
				strcpy(skuL, buf);
				sku(skuL);

				file.ignore(1, ',');
				file.get(buf, 20, ',');
				name(buf);

				file.ignore(1, ',');
				file.get(buf, 7, ',');
				dbuf = std::stod(buf, 0);
				price(dbuf);

				file.ignore(1, ',');
				file.get(buf, 2, ',');
				ibuf = std::stoi(buf, 0);
				taxed(bool(ibuf));

				file.ignore(1, ',');
				file.get(buf, 2);
				ibuf = std::stoi(buf, 0);
				quantity(ibuf);

				file.ignore(1, ',');
				file.get(buf, 10, ',');
				unit(buf);

				file.ignore(1, ',');
				file.get(buf, 4, ',');
				ibuf = std::stoi(buf, 0);
				qtyNeeded(ibuf);

				//clear buffer
				buf[0] = 0;
				skuL[0] = 0;
				break;
			}
		}
		if (ex_ == false){
			file.close();
		}
		return file;
	}
	std::ostream& AmaProduct::write(std::ostream& os, bool linear)const{
		if (!(err_.isClear())){
			os << err_.message();
			return os;
		}
		else{
			if (linear){
				char* temp2 = new char[strlen(unit()) + 1];
				strcpy(temp2, unit());
				temp2[0] = tolower(temp2[0]);
				os.setf(std::ios::fixed);
				os.setf(std::ios::left);
				os.unsetf(std::ios::right);
				os.width(MAX_SKU_LEN);
				os << sku();
				os << '|';
				os.unsetf(std::ios::right);
				os.setf(std::ios::fixed);
				os.setf(std::ios::left);
				os.width(20);
				os << name();
				os.setf(std::ios::fixed);
				os.setf(std::ios::right);
				os << '|';
				os.setf(std::ios::fixed);
				os.setf(std::ios::right);
				os.precision(2);
				os.width(7);
				os << cost();
				os.setf(std::ios::fixed);
				os.setf(std::ios::right);
				os << '|';
				os.unsetf(std::ios::fixed);
				os.setf(std::ios::right);
				os.width(4);
				os << quantity();
				os.setf(std::ios::fixed);
				os.setf(std::ios::right);
				os << '|';
				os.setf(std::ios::fixed);
				os.unsetf(std::ios::right);
				os.width(10);
				os << temp2;
				os.setf(std::ios::fixed);
				os.setf(std::ios::right);
				os << '|';
				os.width(4);
				os << qtyNeeded() << '|';
			}
			else{

				if (taxed()){
					os << "Sku: " << sku() << endl;
					os << "Name: " << name() << endl;
					os << "Price: " << price() << endl;
					os << "Price after tax: " << cost() << endl;
					os << "Quantity On Hand: " << quantity() << " " << unit() << endl;
					os << "Quantity Needed: " << qtyNeeded();
				}
				else{
					os << "Sku: " << sku() << endl;
					os << "Name: " << name() << endl;
					os << "Price: " << price() << endl;
					os << "Price after tax: " << "N/A" << endl;
					os << "Quantity On Hand: " << quantity() << " " << unit() << endl;
					os << "Quantity Needed: " << qtyNeeded() << endl;
				}
			}
			return os;
		}
	}
	std::istream& AmaProduct::read(std::istream& is){

		char buf[MAX_SKU_LEN];
		char YN;
		double dbuf;
		int ibuf;
		cout << "Sku: ";
		is >> buf;
		sku(buf);
		cout << "Name: ";
		is >> buf;
		name(buf);
		cout << "Unit: ";
		is >> buf;
		unit(buf);
		cout << "Taxed? (y/n): ";
		is >> YN;
		if (YN == 'Y' || YN == 'y' || YN == 'N' || YN == 'n'){
			if (YN == 'Y' || YN == 'y'){
				taxed(true);
			}
			else{
				taxed(false);
			}
			cout << "Price: ";
			is >> dbuf;
			price(dbuf);
			if (!(is.fail())){
				cout << "Quantity On hand: ";
				is >> ibuf;
				quantity(ibuf);
				if (!(is.fail())){
					cout << "Quantity Needed: ";
					is >> ibuf;
					qtyNeeded(ibuf);
					if (!(is.fail())){
						err_.clear();
						return is;
					}
					else{
						err_.message("Invalid Quantity Needed Entry");
						is.clear();
						is.setstate(ios::failbit);
					}
				}
				else{
					err_.message("Invalid Quantity Entry");
					is.clear();
					is.setstate(ios::failbit);
				}
			}
			else{
				err_.message("Invalid Price Entry");
				is.clear();
				is.setstate(ios::failbit);
			}
		}
		else{
			err_.message("Only (Y)es or (N)o are acceptable");
			is.clear();
			is.setstate(ios::failbit);
		}
		return is;
	}
}
