// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 6
#include <iomanip>
#include <cstring>
#include "Account.h"
using namespace std;
namespace sict{
  Account::Account(){
    name_[0] = 0;
    balance_ = 0;
  }
  Account::Account(double balance){
    name_[0] = 0;
    balance_ = balance;
  }
  Account::Account(const char name[], double balance){
    strncpy(name_, name, 40);
    name_[40] = 0;
    balance_ = balance;
  }


  void Account::display(bool gotoNewline)const{
    cout << (name_[0] ? name_: "No Name") << ": $" << setprecision(2) << fixed << balance_;
  // if (gotoNewline) cout << endl;
  }

  Account& Account::operator+=(const Account& b){
	  balance_ = balance_ + b.balance_;
	  return *this;
  }
  
  Account operator+(const Account& a, const Account& b){
	  return Account(a.balance_ + b.balance_);
  }
 
  Account& Account::operator=(const Account& b){
	  strcpy(name_,b.name_);
	  if (b.balance_ != 0)
	  balance_ = b.balance_;
	  return *this;
  }

  ostream& operator<<(std::ostream& os,const Account& b){
	  b.display();
	  return os;
  }




}
