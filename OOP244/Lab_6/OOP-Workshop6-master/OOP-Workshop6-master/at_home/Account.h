// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 6
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
namespace sict{
  class Account{
    char name_[41];
    double balance_;
  public:
    Account();
    Account(double balance);
    Account(const char name[], double balance = 0.0);
    void display(bool gotoNewline = true)const;

  };



};

#endif
