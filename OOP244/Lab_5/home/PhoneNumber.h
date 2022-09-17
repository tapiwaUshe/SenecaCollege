// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 6
#ifndef SICT_PHONENUMBER_H_
#define SICT_PHONENUMBER_H_
namespace sict{
  class PhoneNumber{
    int area_;
    int number_;
    char* type_;
    void setEmpty();
    bool isValid(int area, int number, const char* type)const;
    bool allocateAndCopy(int area, int number, const char* str);
  public:
    PhoneNumber();
    PhoneNumber(const PhoneNumber& cp);
    PhoneNumber& operator=(const PhoneNumber& ro);

    ~PhoneNumber();
    // Performs a fool-proof entry of phone number form console
    void read();
    // displays the phone number and goes to new line
    void display(bool goToNewLine = true)const;
    bool isEmpty()const;
  };
}
#endif
