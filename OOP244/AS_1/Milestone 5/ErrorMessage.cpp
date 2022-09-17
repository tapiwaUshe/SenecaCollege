// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 5
#include "ErrorMessage.h"
#include <cstring>
namespace sict{

	ErrorMessage::ErrorMessage(){
		message_ = nullptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage){
		message_ = nullptr;
		message(errorMessage);
	}

	ErrorMessage& ErrorMessage::operator=(const char* errorMessage){
		delete[] message_;
		message_ = new char[strlen(errorMessage) + 1];
		strcpy(message_, errorMessage);
		return *this;
	}

	ErrorMessage::~ErrorMessage(){
	      delete[] message_;
		  message_ = nullptr;
	}

	void ErrorMessage::clear(){
		delete[] message_;
		message_ = nullptr;
	}

	bool ErrorMessage::isClear()const{
		return message_ == nullptr;
	}

	void ErrorMessage::message(const char* value){
		delete[] message_;
		message_ = nullptr;
		message_ = new char[(strlen(value) + 1)];
		strcpy(message_, value);
	}

	const char* ErrorMessage::message()const{
		return message_;
	}

	std::ostream& operator<<(std::ostream& os, ErrorMessage& em){
		if (em.isClear() == false){
			std::cout << em.message();
		}
		return os;
	}
}

