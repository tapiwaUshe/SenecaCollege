// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project
#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>
namespace sict{

  class Date{

  private:

    int value()const;
	void errCode(int errorCode);
	int year_;
	int mon_;
	int day_;
	int readErrorCode_;

  public:

	  Date();
	  Date(int year_, int mon_, int day_);
	  bool operator==(const Date& D)const;
	  bool operator!=(const Date& D)const;
	  bool operator<(const Date& D)const;
	  bool operator>(const Date& D)const;
	  bool operator<=(const Date& D)const;
	  bool operator>=(const Date& D)const;

	  int errCode()const;
	  bool bad()const;
 
	  int mdays()const;

	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr)const;
  };

  std::ostream& operator<<(std::ostream& os, const Date& b);
  std::istream& operator>>(std::istream& is, Date& b);


}
#endif

