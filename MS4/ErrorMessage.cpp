#define _CRT_SECURE_NO_WARNINGS
#include "ErrorMessage.h"
#include <iostream>
#include <iomanip>
#include <cstring>


using namespace std;

namespace sict
{

	ErrorMessage::ErrorMessage(const char* errorm)
	{
	

		if (errorm == nullptr)
		{
		
			this->m_message = nullptr;
		}
		else
		{

			this->m_message = new char[strlen(errorm) + 1];
			strcpy(this->m_message, errorm);

		}
	}

	ErrorMessage::~ErrorMessage()
	{
		clear();
	}

	void ErrorMessage::clear()
	{
		delete[] this->m_message;
		this->m_message = nullptr;
	}

	bool ErrorMessage::isClear() const
	{
		return (m_message == nullptr) ? true : false;
	}

	void ErrorMessage::message(const char* str)
	{
		delete[] m_message;
		this->m_message = new char[strlen(str) + 1];
		strcpy(m_message, str);
	}

	const char* ErrorMessage::message() const
	{
		return m_message;
	}



	std::ostream& operator<<(std::ostream& os, const ErrorMessage& err)
	{
		if (!err.isClear()) {
			os << err.message();
		}
		return os;
	}
}
