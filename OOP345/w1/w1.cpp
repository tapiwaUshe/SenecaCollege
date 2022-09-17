// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 1: I/O
#include <iostream>
#include "process.h"
#include "CString.h"

using namespace w1;

int main(int argc, char* argv[])
{
  if(argc<=1) {
    std::cout << "Insufficient number of arguments (min 1)" << std::endl;
    return 1;
  }
  std::cout << "Maximum number of characters stored : " << MAX << std::endl;
  int n=1;
  while(n<argc) {
    process(argv[n++]);
  }
  return 0;
}
