// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project: Milestone 2
#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <iostream>
namespace sict{

	class ErrorMessage{

	private:
		char* message_;
	public:

		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& os, ErrorMessage& em);
}
#endif

