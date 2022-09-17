// Name: Tapi Z. Ushe
// Class: OOP244
// Workshop 4
#include <iostream>
#include "Enrollment.h"
using namespace std;
using namespace sict;
void displayEnrollments(const Enrollment& e1, const Enrollment& e2);
int main(){
	Enrollment* slots;
	Enrollment current;
	char name[31];
	char code[11];
	int year;
	int semester;
	int slot;
	int i = 0;
	int n;
	cout << "Please entere the number of course sections: ";
	cin >> n;
	cin.ignore(1000, '\n');
	slots = new Enrollment[n];
	cout << "Please enter the following " << n << " course sections for enrollment:" << endl;
	while (i < n){
		cout << "Course section " << (i + 1) << ":" << endl
			<< "Subject Name: ";
		cin.getline(name, 30, '\n');
		cout << "Subject Code: ";
		cin.getline(code, 10, '\n');
		cout << "Year: ";
		cin >> year;
		cout << "Semester: ";
		cin >> semester;
		cout << "Slot: ";
		cin >> slot;
		cin.ignore(1000, '\n');
		current.set(name, code, year, semester, slot);
		if (current.isValid()){
			int c;
			if ((c = current.enrol(slots, n)) == 0){
				char res;
				slots[i] = current;
				cout << "Enrolled!" << endl;
				i++;
				cout << "Continue? (y/n)";
				res = cin.get();
				if (res != 'y' && res != 'Y'){
					i = n;
				}
				cin.ignore(1000, '\n');
			}
			else{
				cout << "There is a conflict with the following, please change enrollment time: " << endl;
				slots[c - 1].display();
			}
		}
		else{
			cout << "Invalid information entered, please redo: " << endl;
		}
	}
	for (i = 0; i < n; i++){
		cout << "------------------------------" << endl;
		slots[i].display();
	}

	// testing withdraw();
	slots[0].withdraw();
	slots[0].display();
	delete[] slots;
	slots = nullptr;
	return 0;
}

/* output
Please entere the number of course sections: 5
Please enter the following 5 course sections for enrollment:
Course section 1:
Subject Name: aaa aaa
Subject Code: aa
Year: 2015
Semester: 3
Slot: 3
Enrolled!
Continue? (y/n)y
Course section 2:
Subject Name: bbb bbb
Subject Code: bb
Year: 2015
Semester: 2
Slot: 2
Enrolled!
Continue? (y/n)y
Course section 3:
Subject Name: ccc ccc
Subject Code: cc
Year: 2015
Semester: 2
Slot: 2
There is a conflict with the following, please change enrollment time:
bbb bbb
bb, Year: 2015 semester: 2 Slot: 2
Status: Enrolled.
Course section 3:
Subject Name: ccc ccc
Subject Code: cc
Year: 2015
Semester: 1
Slot: 1
Enrolled!
Continue? (y/n)n
------------------------------
aaa aaa
aa, Year: 2015 semester: 3 Slot: 3
Status: Enrolled.
------------------------------
bbb bbb
bb, Year: 2015 semester: 2 Slot: 2
Status: Enrolled.
------------------------------
ccc ccc
cc, Year: 2015 semester: 1 Slot: 1
Status: Enrolled.
------------------------------
Invalid enrollment!
------------------------------
Invalid enrollment!
aaa aaa
aa, Year: 2015 semester: 3 Slot: 3
Status: Not enrolled.

*/
