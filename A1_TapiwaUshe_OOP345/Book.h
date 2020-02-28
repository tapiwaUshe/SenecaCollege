// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 045787132

#ifndef BOOK_H
#define BOOK_H
#include <string>
using namespace std;

class Book
{
	string author, title, date;
public:
	Book();
	Book(string newA, string newT, string newD);
	void setData(string newA, string newT, string newD);
	string getAuthor() const;
	string getTitle() const;
	string getDate() const;
	friend bool operator< (const Book &book1, const Book &book2);
};

#endif
