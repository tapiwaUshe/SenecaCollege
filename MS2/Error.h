#ifndef SICT_ERROR_h
#define SICT_ERROR_h
#include <iostream>
namespace sict{ // BEGIN NAMESPACE AMA
    class ErrorMessage{
        char* msg;
    public:
        ErrorMessage(const ErrorMessage& eMsg) = delete;
        virtual ~ErrorMessage();
        explicit ErrorMessage(const char* eMsg = nullptr);
        bool isClear() const;
        void clear();
        void message(const char*);
        const char* message() const;
        ErrorMessage& operator=(const ErrorMessage& eR) = delete;
    };
    std::ostream& operator<<(std::ostream&, const ErrorMessage&);
} // END NAMESPACE SICT
#endif
