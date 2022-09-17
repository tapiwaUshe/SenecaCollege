// OOP244 Workshop 2: Compound types and privacy
// File	w2_at_home.cpp
// Version 1.0
// Date	2016/01/14
// Author	Fardad Soleimanloo
// Description
// This file is used to demonstrate classes in C++ and 
// how member variables can be defined as private but 
// accessed through member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
#include "AccountNumber.h"
using namespace sict;
void displayAccountNumber(const AccountNumber* acc);
int main(){
  AccountNumber myNumber;
  char name[41];
  int bankCode;
  int branchCode;
  int accNumber;
  cout << "Bank account app" << endl <<
    "===================" << endl << endl;
  cout << "Please enter your name: ";
  cin >> name;
  cout << "please enter your bank account ,branch code" <<
    ", and account number as follows:" << endl << "999 999 99999: ";
  do{
    cin >> bankCode >> branchCode >> accNumber;
    myNumber.name(name);
    myNumber.accountNumber(bankCode, branchCode, accNumber);
    
    displayAccountNumber(&myNumber);

  } while (!myNumber.isValid()
    && cout << "Invalid account number, (999 999 9999), try again: ");
  cout << "Thank you!" << endl;
  return 0;
}
void displayAccountNumber(const AccountNumber* acc){
  acc->display();
  cout << "-------------" << endl;
  acc->display(false);
  cout << "-------------" << endl;
  acc->display(true, false);
  cout << "-------------" << endl;
  acc->display(false, false);
}
