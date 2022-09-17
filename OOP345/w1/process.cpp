// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 1: I/O
#include <iostream>
#include "CString.h"
#include "process.h"
using namespace w1;
void process(const char *str)
{
  CString cStr(str);
  std::cout << cStr << std::endl;
}
