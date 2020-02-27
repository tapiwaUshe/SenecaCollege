// Name: Tapi Z. Ushe
// ID: 045787132
// Project 1 - MS2

#ifndef SICT_ERRORMESSAGE_H__
#define SICT_ERRORMESSAGE_H__
#include <iostream>

namespace sict {
	class ErrorMessage {
		char* _message;
	public:
		explicit ErrorMessage(const char* errorMessage = nullptr);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage&) = delete;
		virtual ~ErrorMessage();
		void clear();
		bool isClear() const;
		void message(const char*);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream& outs, const ErrorMessage& error);
}
#endif
