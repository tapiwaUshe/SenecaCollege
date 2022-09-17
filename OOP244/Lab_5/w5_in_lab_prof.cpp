// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 6
#include <iostream>
using namespace std;
#include "Contact.h"
using namespace sict;

int main(){
  Contact c("Empty Contact", 3);
  c.display();
  cout << "Enter Contact information: " << endl;
  c.read();
  c.display();
  cout << endl;
  for (int i = 0; i < 1000000; i++){
    Contact temp("Testing the contact with a looooong "
                 "name that should be taken care of", 20);
    if (!(i % 100000)){
      cout << i << ":" << endl;
      temp.display();
    }
  }
  return 0;
}

/*output:
Empty Contact
----------------------------------------
Enter Contact information:
Contact Name: John Doe
Please enter 3 phone numbers:
1: Home, 123 1234567
2: Cell, 234 2345678
3: Work, 345 3456789
John Doe
Home..........., 123 123-4567
Cell..........., 234 234-5678
Work..........., 345 345-6789
----------------------------------------

0:
Testing the contact with a looooong name
----------------------------------------
100000:
Testing the contact with a looooong name
----------------------------------------
200000:
Testing the contact with a looooong name
----------------------------------------
300000:
Testing the contact with a looooong name
----------------------------------------
400000:
Testing the contact with a looooong name
----------------------------------------
500000:
Testing the contact with a looooong name
----------------------------------------
600000:
Testing the contact with a looooong name
----------------------------------------
700000:
Testing the contact with a looooong name
----------------------------------------
800000:
Testing the contact with a looooong name
----------------------------------------
900000:
Testing the contact with a looooong name
----------------------------------------
*/
