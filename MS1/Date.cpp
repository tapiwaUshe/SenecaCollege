//  Name: Tapi Z. Ushe
//  Num: 045787132
//  Created by Tapi Z. Ushe  2018-07.
//  AID MANAGEMENT APPLICATION -- MILESTONE 1

#include "K.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace sict{ // BEGIN NAMEPACE AMA
    
    Date::Date()
    {
        __theYear = 0;
        __theMonth = 0;
        __theDay = 0;
        __readTheError = 0;
    }
    
    Date::Date(int yY, int mM, int dD)
    {
        set(yY, mM, dD);
    }
    
    void Date::set(int yY2, int mM2, int dD2)
    {
        if(min_year <= yY2 && yY2 <= max_year){
            if(1 <= mM2 && mM2 <= 12){
                if(1 <= dD2 && dD2 <= mdays(mM2, yY2)){
                    __readTheError = 0;
                    __theYear = yY2;
                    __theMonth = mM2;
                    __theDay = dD2;
                }else
                    Date();
            }else
                Date();
        }else
            Date();
    }
    
    int Date::mdays(int mon, int year)const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int month = mon >= 1 && mon <= 12 ? mon : 13;
        month--;
        return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    
    bool Date::bad() const
    {
        return (errCode() != NO_ERROR);
    }
    
    int Date::errCode() const
    {
        return (__readTheError);
    }
    
    void Date::errCode(int eCode)
    {
        __readTheError = eCode;
    }
    
    int Date::getCompValue() const
    {
        return (__theYear * 372 + __theMonth * 31 + __theDay);
    }
    
    bool Date::operator<(const Date& rhs) const
    {
        return this->getCompValue() < rhs.getCompValue();
    }
    
    bool Date::operator>(const Date& rhs) const
    {
        return this->getCompValue() > rhs.getCompValue();
    }
    
    bool Date::operator>=(const Date& rhs) const
    {
        return this->getCompValue() >= rhs.getCompValue();
    }
    
    bool Date::operator<=(const Date& rhs) const
    {
        return this->getCompValue() <= rhs.getCompValue();
    }
    
    bool Date::operator!=(const Date& rhs) const
    {
        return this->getCompValue() != rhs.getCompValue();
    }
    
    bool Date::operator==(const Date& rhs) const
    {
        return this->getCompValue() == rhs.getCompValue();
    }
    
    std::ostream& Date::write(std::ostream& ostr) const
    {
        ostr << setfill('0') << setw(1) << __theYear << '/' <<
        setfill('0') << setw(2) << __theMonth << '/' <<
        setfill('0') << setw(2) << __theDay;
        return ostr;
    }
    
    std::istream& Date::read(std::istream& istr)
    {
        errCode(NO_ERROR);
        char readString;
        istr >> this ->__theYear >> readString >> this->__theMonth >> readString >> this->__theDay;
        
        if(istr.fail()){
            this->errCode(CIN_FAILED);
        }else if(min_year > this->__theYear || this-> __theYear >= max_year){
            this->errCode(YEAR_ERROR);
            // Set year failure errorstate.
        }//else if(this->__theMonth < 1 || this->__theMonth >= 12){
        else if(1 > this->__theMonth || this->__theMonth >= 12){
            this->errCode(MON_ERROR);
            // Set month failure errorstate.
        }//else if(this->__theDay <= 1 || this->__theDay < this->mdays(__theMonth, __theYear)){
        else if(this->__theDay > this->mdays(__theMonth, __theYear) || this->__theDay <= 1){
            // Set day failure errorstate.
            this->errCode(DAY_ERROR);
        }else{
            this->errCode(NO_ERROR);
            // Set no errorstate.
        }
        if(__readTheError != 0){
            __theYear = 0;
            __theMonth = 0;
            __theDay = 0;
        }
        return istr;
    }
    
    std::ostream& operator<<(std::ostream& ostr, const Date& elDia)
    {
        elDia.write(ostr);
        return ostr;
    }
    
    std::istream& operator>>(std::istream& istr, Date& elDate)
    {
        elDate.read(istr);
        return istr;
    }
} // END NAMESPACE AMA
