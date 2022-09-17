// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 5
#ifndef SICT__Streamable_H_
#define SICT__Streamable_H_
#include <iostream>
#include <fstream>
namespace sict{
  class Streamable{
  public:
    // pure virtual functions go here!
	  virtual std::fstream& store(std::fstream& file, bool addNewLine = true)const = 0;
	  virtual std::fstream& load(std::fstream& file) = 0;
	  virtual std::ostream& write(std::ostream& os, bool linear)const = 0;
	  virtual std::istream& read(std::istream& is) = 0;


  };
}
#endif
