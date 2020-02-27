//  Name: Tapi Z. Ushe
//  Num: 045787132
//  Created by Tapi Z. Ushe  2018-07.
//  AID MANAGEMENT APPLICATION -- MILESTONE 1

#ifndef K_hpp
#define K_hpp
#include <iostream>

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4
#define min_year 2000
#define max_year 2030

using namespace std;
namespace sict{ // BEGIN NAMESPACE AMA
    class Date{
        int __theYear;
        int __theMonth;
        int __theDay;
        int __readTheError;
        int mdays(int month, int year) const;
        void errCode(int);
        int getCompValue() const;
    public:
        Date();
        Date(int year, int mon, int day);
        void set(int, int, int);
        bool bad() const;
        int errCode() const;
        bool operator<(const Date&) const;
        bool operator>(const Date&) const;
        bool operator<=(const Date&) const;
        bool operator>=(const Date&) const;
        bool operator==(const Date&) const;
        bool operator!=(const Date&) const;
        std::ostream& write(std::ostream&) const;
        std::istream& read(std::istream&);
    };
    std::ostream& operator<<(std::ostream&, const Date&);
    std::istream& operator>>(std::istream&, Date&);
} // END NAMESPACE AMA
#endif /* K_hpp */
