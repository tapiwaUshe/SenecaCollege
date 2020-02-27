
#include "Error.h"
#include <iostream>
#include <iomanip>
#include <cstring>

namespace sict{ // BEGIN NAMESPACE SICT
    ErrorMessage::~ErrorMessage()
    {
        clear();
    }
    
    ErrorMessage::ErrorMessage(const char* eMsg)
    {
        if(eMsg == nullptr){
            this->msg = nullptr;
        }else{
            this->msg = new char [strlen(eMsg) + 1];
            strcpy(this->msg, eMsg);
        }
    }

    void ErrorMessage::message(const char* charlie)
    {
        delete [] msg;
        this->msg = new char[strlen(charlie) + 1];
        strcpy(msg, charlie);
    }
    
    const char* ErrorMessage::message() const
    {
        return msg;
    }
    
    void ErrorMessage::clear()
    {
        delete [] this->msg;
        this->msg = nullptr;
    }
    
    bool ErrorMessage::isClear() const
    {
        return (msg == nullptr) ? true : false;
    }
    
    std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& eR)
    {
        if(!eR.isClear()){
            ostr << eR.message();
        }
        return ostr;
    }
} // END NAMESPACE SICT
