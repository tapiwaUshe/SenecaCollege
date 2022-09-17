// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 6
#include <iostream>
#include "Contact.h"
using namespace std; using namespace sict;
int main(){
  Contact c("Empty Contact", 3);
  c.display();
  cout << "Enter Contact information: " << endl;
  c.read();
  c.display();
  cout << "Please wait";
  Contact cp = c;
  c = cp;
  for (int i = 0; i < 1000000; i++){

    if (!(i % 100000)) cout << ".";
  }
  cout << endl;
  c.display();
  return 0;
}
