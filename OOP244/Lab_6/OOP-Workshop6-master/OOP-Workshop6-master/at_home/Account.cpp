// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 6
#include <iomanip>
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
    if (gotoNewline) cout << endl;
  }




}
