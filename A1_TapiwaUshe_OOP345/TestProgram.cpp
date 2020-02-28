// Name: Tapi Z. Ushe
// Class: OOP345
// Stu No. 045787132

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Book.h"
using namespace std;

void AddNewBook(vector<Book> *bookdata);
void PrintBooks(vector<Book> &bookdata);
void SortBooks(vector<Book> &bookdata);
void PrintMenu();

Book bk;
vector<Book> v;

int main()
{
	vector<Book> bookdata;

	while (true) {
		int select;
		string t, a, d, empty;

		PrintMenu();
		std::cout << "choice: ";
		std::cin >> select;

		switch (select) {
		case 1:
			std::cout << endl;
			std::getline(std::cin, empty);

			cout << "Enter title: ";
			std::getline(cin, t);
			cout << "Enter author: ";
			std::getline(cin, a);
			cout << "Enter date: ";
			std::getline(cin, d);

			bk.setData(a, t, d);
			AddNewBook(&v);
			break;
		case 2:
			PrintBooks(v);
			break;
		case 3:
			exit(true);
			break;
		default:
			std::cout << std::endl;
			std::cout << "Wrong Number, Select Another Number" << std::endl;
			std::cout << std::endl;
			break;
		}
	}

	return 0;
}

void AddNewBook(vector<Book>* bookdata)
{
	bookdata->push_back(bk);
	std::cout << std::endl;
}

void PrintBooks(vector<Book>& bookdata)
{
	SortBooks(bookdata);
	std::cout << std::endl;
	std::cout << "The books entered so far, sorted alphatetically by artist are: " << std::endl;
	for (vector<Book>::iterator it = bookdata.begin(); it != bookdata.end(); ++it) {
		std::cout << it->getTitle() << ", " << it->getAuthor() << ", " << it->getDate() << std::endl;
	}
	std::cout << std::endl;
}

void SortBooks(vector<Book>& bookdata)
{
	sort(bookdata.begin(), bookdata.end());
}

void PrintMenu()
{
	std::cout << "Select from the following choices:" << std::endl;
	std::cout << "1. Add new book" << std::endl;
	std::cout << "2. Print listing sorted by author" << std::endl;
	std::cout << "3. Quit" << std::endl;
}
