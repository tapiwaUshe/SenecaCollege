// Name: Tapi Z. Ushe
// Class: OOP244
// Assignment Project
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Date.h"
#include "general.h"
using namespace std;
using namespace sict;
bool equalDates(const char* A, const char* B);
bool yes();
int main(){
  int ret = 0;
  bool ok = true;
  if (ok){
    cout << "Checking defined values, POS.h: " << endl;
  }
  if (ok && MIN_YEAR != 2000){
    cout << "MIN_YEAR must be 2000" << endl;
    ok = false;
  }
  if (ok && MAX_YEAR != 2030){
    cout << "MAX_YEAR must be 2030" << endl;
    ok = false;
  }
  if (ok && (TAX - 0.13 > 0.0001 || TAX - 0.13 < -0.0001)){
    cout << "TAX must be 0.13" << endl;
    ok = false;
  }
  if (ok && MAX_SKU_LEN != 7){
    cout << "MAX_SKU_LEN must be 7" << endl;
    ok = false;
  }
  if (ok && DISPLAY_LINES != 10){
    cout << "DISPLAY_LINES must be 10" << endl;
    ok = false;
  }
  if (ok) {
    cout << "Passed!" << endl;
    cout << "Checking define values for error code in Data.h" << endl;
  }
  if (ok && NO_ERROR != 0){
    cout << "NO_ERROR must be 0" << endl;
    ok = false;
  }
  if (ok && CIN_FAILED != 1){
    cout << "CIN_FAILED must be 1" << endl;
    ok = false;
  }
  if (ok && YEAR_ERROR != 2){
    cout << "YEAR_ERROR must be 2" << endl;
    ok = false;
  }
  if (ok && MON_ERROR != 3){
    cout << "MON_ERROR must be 3" << endl;
    ok = false;
  }
  if (ok && DAY_ERROR != 4){
    cout << "DAY_ERROR must be 4" << endl;
    ok = false;
  }
  if (ok){
    cout << "Passed!" << endl;
  }
  if (ok){
    cout << "Testing Date() constructor and operator<< overload; " << endl;
    Date Current;
    cout << "Are these two the same date and time? (regardless of format)" << endl
      << "1- 0/00/00" << endl
      << "2- " << Current << endl
      << "(y)es/(n)o: ";

    if (!yes()){
      cout << "Either the Date() constructor or operator<< is not implemented correctly." << endl;
      ok = false;
    }
    else{
      cout << "Passed!" << endl;
    }
  }
  if (ok){
    Date A(2018, 10, 18);
    Date B = A;
    cout << "Testing Date(int, int, int) constructor and operator>> overload; " << endl;
    cout << "enter the following date, 2018/10/18" << endl << ">";;
    cin >> B;

    if (!equalDates((const char*)&A, (const char*)&B)){
      cout << "Either the constructor or operator>> is not implemented correctly." << endl;
      ok = false;
    }
    else{
      cout << "Passed!" << endl;
    }
  }
  if (ok){
    cout << "Testing the logical operators: " << endl;
  }
  if (ok){
    Date A(2018, 10, 18);
    Date B(2018, 10, 18);
    cout << "testing operator==" << endl;
    if (A == B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is equal to " << B << " but operator== returns otherwise!" << endl;
      ok = false;
    }
  }

  if (ok){
    Date A(2018, 10, 18);
    Date B(2018, 10, 18);
    cout << "testing operator>=" << endl;
    if (A >= B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is equal to " << B << endl << "but operator>= returns otherwise!" << endl;
      ok = false;
    }
  }

  if (ok){
    Date A(2018, 10, 18);
    Date B(2018, 10, 18);
    cout << "testing operator<=" << endl;
    if (A <= B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is equal to " << B << endl << "but operator<= returns otherwise!" << endl;
      ok = false;
    }
  }

  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18);
    cout << "testing operator!=" << endl;
    if (A != B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is not equal to " << B << " but operator!= returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18);
    cout << "testing operator<" << endl;
    if (A < B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is less than " << B << " but operator< returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18);
    cout << "testing operator>" << endl;
    if (B > A){
      cout << "passed!" << endl;
    }
    else{
      cout << B << " is greater than " << B << " but operator> returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18);
    cout << "testing operator<=" << endl;
    if (A < B){
      cout << "passed!" << endl;
    }
    else{
      cout << A << " is less than " << B << " but operator<= returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A(2018, 10, 17);
    Date B(2018, 10, 18);
    cout << "testing operator>=" << endl;
    if (B >= A){
      cout << "passed!" << endl;
    }
    else{
      cout << B << " is greater than " << B << " but operator>= returns otherwise!" << endl;
      ok = false;
    }
  }
  if (ok){
    Date A;
    cout << "Testing error handling in read funciton;" << endl;
    cout << "cin faliure detection, " << endl;
    cout << "Please enter the following string \"abcd\": ";
    cin >> A;
    if (A.errCode() == CIN_FAILED){
      cout << "passed!" << endl;
    }
    else {
      cout << "Your read function does not check cin.fail() after entry," << endl
        << "or it did not set _readErrorCode to CIN_FAILED" << endl;
      ok = false;
    }
    cin.clear();
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    cout << "Year validation, " << endl;
    cout << "Please enter the following string \"10/1/1\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == YEAR_ERROR){
      cout << "passed!" << endl;
    }
    else {
      cout << "Your read function does not check the year entry limits after entry," << endl
        << "or it did not set _readErrorCode to YEAR_ERROR" << endl;
      ok = false;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    cout << "Month validation, " << endl;
    cout << "Please enter the following string \"2000/13/1\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == MON_ERROR){
      cout << "Passed" << endl;
    }
    else {
      cout << "Your read function does not check the month entry limits after entry," << endl
        << "or it did not set _readErrorCode to MON_ERROR" << endl;
      ok = false;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    cout << "Day validation, " << endl;
    cout << "Please enter the following string \"2000/1/50\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == DAY_ERROR){
      cout << "Passed!" << endl;
    }
    else {
      cout << "Your read function does not check the day entry limits after entry," << endl
        << "or it did not set _readErrorCode to DAY_ERROR" << endl;
      ok = false;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    Date A;
    cout << "Day validation, leap year:" << endl;
    cout << "Please enter the following string \"2016/2/29\": ";
    cin >> A;
    cout << "You entered: " << A << endl;
    if (A.errCode() == DAY_ERROR){
      cout << "Your read function does not check the day entry limits using mday()" << endl;
      ok = false;
    }
    else {
      cout << "passed!" << endl;
    }
    cin.ignore(2000, '\n');
  }
  if (ok){
    cout << "You passed all the tests!" << endl;
  }
  else{
    cout << "You did not pass all the tests, keep working on your project!" << endl;
    ret = 1;
  }

  return ret;
}
bool equalDates(const char* A, const char* B){
  unsigned int i;
  for (i = 0; i < sizeof(Date); i++){
    if (A[i] != B[i]) i = sizeof(Date);
  }
  return sizeof(Date) == i;
}

bool yes(){
  char ch;
  ch = cin.get();
  cin.ignore(1000, '\n');
  return ch == 'y' || ch == 'Y';
}

