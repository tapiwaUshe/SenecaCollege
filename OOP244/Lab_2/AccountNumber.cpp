// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 2
#include <iostream>
#include <cstring>
#include "AccountNumber.h"
using namespace std;
namespace sict{
	// member functions' (methods') definition go here
	void AccountNumber::name(const char name[]){
		strcpy(_name, name);
	}

	void AccountNumber::accountNumber(int bankCode, int branchCode, int accountNumber){
		_bankCode = bankCode;
		_branchCode = branchCode;
		_accountNumber = accountNumber;
		_validAccNumber = isValid();
	}

	void AccountNumber::display() const{
		if (isValid() == true){
			cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
				<< _branchCode << "-" << _accountNumber << endl;
		}
		else{
			cout << _name << " does not have a valid account number." << endl;
		}
	}

	bool AccountNumber::isValid() const{
		if (_bankCode >= MIN_BANKCODE && _bankCode <= MAX_BANKCODE && _branchCode >= MIN_BRANCHCODE && _branchCode <= MAX_BRANCHCODE &&_accountNumber >= MIN_ACCNO && _accountNumber <= MAX_ACCNO){
			return true;
		}
		else{
			return false;
		}
	}
}

