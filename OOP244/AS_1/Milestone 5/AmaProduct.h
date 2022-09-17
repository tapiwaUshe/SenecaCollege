// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 5
#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
#include "Product.h"
#include "ErrorMessage.h"

namespace sict{
  class AmaProduct :public Product{
	  private:
		  char fileTag_;
		  char unit_[11];
		  bool cap_;
		  bool ex_;
	  protected:
		  ErrorMessage err_;
	  public:
		  AmaProduct(char fileTag_ = 'N');
		  const char* unit()const;
		  void unit(const char* value);
		  const char fileTag()const;
		  void fileTag(char a);
		  const bool ex()const;
		  void ex(bool a = false);
		  std::fstream& store(std::fstream& file, bool addNewLine = true)const;
		  std::ostream& write(std::ostream& os, bool linear)const;
		  std::fstream& load(std::fstream& file);
		  std::istream& read(std::istream& is);
  };
}
#endif


