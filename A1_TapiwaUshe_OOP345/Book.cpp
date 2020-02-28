// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 045787132

#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

using namespace std;

Book::Book(){}
Book::Book(string newA, string newT, string newD){}

void Book::setData(string newA, string newT, string newD)
{
	author = newA;
	title = newT;
	date = newD;
}

string Book::getAuthor() const{ return author; }
string Book::getTitle() const { return title; }
string Book::getDate() const { return date; }

bool operator<(const Book & book1, const Book & book2) { return (book1.author < book2.author); }
