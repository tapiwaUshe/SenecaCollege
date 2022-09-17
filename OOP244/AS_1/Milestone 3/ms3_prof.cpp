// Name: Tapi Z. Ushe
// Class: OOP244 Object Oriented Programming
// Assignment: Milestone 3
#include <iostream>
#include "MyFile.h"
using namespace std;
using namespace sict;
int main(){  
  fstream file("ms2.txt", ios::out);
  file << "one" << endl << "two" << endl;
  file.close();
  MyFile F("ms2.txt");
  F.load(file);
  cout << "Linear: " << F << endl;
  cout << "As is: " << endl;
  F.print();
  cout << "Enter the folowing: " << endl << "three<ENTER>" << endl << "four<ENTER>" << endl << "<Ctrl-D>" << endl << endl;
  cin >> F;
  F.store(file, true);
  F.load(file);
  cout << F << endl;
  F.print();
  return 0;
}
