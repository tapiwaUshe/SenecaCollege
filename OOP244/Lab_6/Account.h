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

	//imple
	Account& operator+=(const Account& b);
	friend Account operator+(const Account& a, const Account& b);
	Account& operator=(const Account& b);
  };

  std::ostream& operator<<(std::ostream& os, const Account& b);

};

#endif
