// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 6
#pragma once
#include <string>

class Grades {
public:
  Grades(const std::string fileName);
  // template<typename F>
  // void displayGrades(std::ostream &os, F letter) const;
  // template<typename F>
  // void displayGrades(std::ostream &os, F letter) const;
  // void displayGrades(std::ostream &os, std::ostream &os, std::function<std::string(double)> letter) const;
  
  template<typename F>
  void displayGrades(std::ostream &os, F letter) const;
};
