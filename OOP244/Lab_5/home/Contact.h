// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 6
#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_
#include "PhoneNumber.h"
namespace sict{
  class Contact{
    char name_[41];
    PhoneNumber* phoneNumber_;
    int _noPN;
    void setEmpty();
	void copy(const Contact& C);

  public:
	  Contact& operator=(const Contact& C);
	 Contact();
	 Contact(const char* name, int noPhn);
	 ~Contact();
    void read();
    void display()const;
    bool isEmpty()const;
  };

}
#endif
