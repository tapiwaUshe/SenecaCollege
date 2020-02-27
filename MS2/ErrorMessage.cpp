// Name: Tapi Z. Ushe
// ID: 045787132
// Project 1 - MS2

#include "ErrorMessage.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sict
{
	ErrorMessage::ErrorMessage(const char* errorYes)
	{
		if (errorYes == nullptr)
		{
			this->_message = nullptr;
		}
		else
        {
			this->_message = new char[strlen(errorYes) + 1];
			strcpy(this->_message, errorYes);
		}
	}

	ErrorMessage::~ErrorMessage()
	{
		clear();
	}

	void ErrorMessage::clear()
	{
		delete[] this->_message;
		this->_message = nullptr;
	}

	bool ErrorMessage::isClear() const
	{
		return (_message == nullptr) ? true : false;
	}

	void ErrorMessage::message(const char* str)
	{
		delete[] _message;
		this->_message = new char[strlen(str) + 1];
		strcpy(_message, str);
	}

	const char* ErrorMessage::message() const
	{
		return _message;
	}

	std::ostream& operator<<(std::ostream& outs, const ErrorMessage& error)
	{
		if (!error.isClear()) {
			outs << error.message();
		}
		return outs;
	}
}
