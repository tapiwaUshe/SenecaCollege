// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 4
#ifndef SICT__Streamable_H_
#define SICT__Streamable_H_
#include <iostream>
#include <fstream>
namespace sict{
  class Streamable{
  public:
    // pure virtual functions go here!
	  std::fstream& store(std::fstream& file, bool addNewLine = true)const;
	  std::fstream& load(std::fstream& file);
	  std::ostream& write(std::ostream& os, bool linear)const;
	  std::istream& read(std::istream& is);

  };
}
#endif
