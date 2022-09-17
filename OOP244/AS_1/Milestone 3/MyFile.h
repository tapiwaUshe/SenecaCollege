// Name: Tapi Z. Ushe
// Class: OOP244 Object Oriented Programming
// Assignment: Milestone 3
#ifndef SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__
#include "Streamable.h"
namespace sict{
  class MyFile : public Streamable {
    char _fname[256];
    char _text[10000];
  public:
    MyFile(const char* fname);
    std::fstream& store(std::fstream& file, bool addNewLine)const;
    std::fstream& load(std::fstream& file);
    std::ostream& write(std::ostream& os, bool linear)const;
    std::istream& read(std::istream& is);
    void print();
  };
  std::ostream& operator<<(std::ostream& ostr, const MyFile& mf);
  std::istream& operator>>(std::istream& istr, MyFile& mf);
}
#endif
