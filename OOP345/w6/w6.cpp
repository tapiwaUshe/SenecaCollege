// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 6: Lambda Expressions

#include <iostream>
#include <functional>
#include <string>
#include "Grades.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << argv[0] <<
    ": incorrect number of arguments\n";
    std::cerr << "Usage: " << argv[0] << " file_name\n"; 
    return 1;
  }

  Grades grades(argv[1]);
  // define the lambda expression for letter
  // auto letter = [](double grade) {
  //   std::string letterGrade;
  //   return letterGrade;
  // };
  
  // grades.displayGrades(std::cout, 
  //   [](double grade) {
  //     std::string letterGrade;
  //     letterGrade = "grade is " << grade << std::endl;
  //     return letterGrade;
  //   }
  // );

  // grades.displayGrades(std::cout, 
  //   [](int grade) {
  //     return grade * 2;
  //   }
  // );

  // std::function<std::string(double)> f = [](double grade) { return std::string(grade * 2) };
  // std::function<double (double, double)> f = [](double a, double b) { return a*b; };
  std::function<double (double)> letter = [](double grade) { return grade*grade; };
  // std::function<char* (double)> f = [](double grade) { return "ok"; };
  
  grades.displayGrades(std::cout, letter);

  std::cout << "Press any key to continue ... ";
  std::cin.get();
}
