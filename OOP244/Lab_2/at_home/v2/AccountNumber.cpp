// OOP244 Workshop 2: Compound types and privacy
// File	sub class
// Version 1.0
// Date	Jan 26, 2016
// Author	Kelvin Cho
// Description:
// Account number
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

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

	void sict::AccountNumber::display(bool dspName, bool dspNumber) const{
		if (isValid()){
			if (dspName && dspNumber){
				cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
					<< _branchCode << "-" << _accountNumber << endl;
			}
			if (dspName == false && dspNumber){
				displayNumber();
			}
			if (dspName  && dspNumber == false){
				displayName();
			}
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

	void AccountNumber::displayName() const{
		cout << "Name: " << _name << endl;
	}

	void AccountNumber::displayNumber() const{
		cout << "Account number: " << _bankCode << "-"
			<< _branchCode << "-" << _accountNumber << endl;
	}
}

