// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 2: UInt, Enumerations, String Class and File I/O 
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Stations.h"

w2::Stations::Stations(char* fileName)
{
  std::string stationName;
  unsigned studentPassCount;
  unsigned adultPassCount;
  // Station station;
  int i = 0;

  _fileName.assign(fileName);

  std::ifstream ifs(_fileName, std::ifstream::in);
  if(ifs.fail()) return;

  // // ignore the first line (station counter), since we are using vectors
  // ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  ifs >> _count;
  ifs.ignore();

  _stations = new Station[_count];
  
  while(ifs.good()) {
    std::getline(ifs, stationName, ';');
    ifs >> studentPassCount >> adultPassCount;    
    
    // station = Station();
    // station.set(stationName, studentPassCount, adultPassCount);
    // _stations.push_back(station);
    _stations[i].set(stationName, studentPassCount, adultPassCount);
    i++;
  }
  
  ifs.close();  
}

void w2::Stations::update() const
{
  int studentSold, adultSold;
  // Station station;
  
  std::cout << "\nPasses Sold :\n-------------";
  
  // for(int i=0; i<_stations.size(); i++) {
  for(int i=0; i<_count; i++) {
    // station = _stations[i];
    std::cout << _stations[i].getName() << std::endl;
    std::cout << " Student Passes sold : ";
    std::cin >> studentSold;
    _stations[i].update(Student, -studentSold);
    std::cout << " Adult   Passes sold : ";
    std::cin >> adultSold;
    _stations[i].update(Adult, -adultSold);
  }  
}

void w2::Stations::restock() const
{
  int studentAdded, adultAdded;
  // Station station;
  
  std::cout << "\nPasses Added :\n-------------";
  
  // for(int i=0; i<_stations.size(); i++) {
  for(int i=0; i<_count; i++) {
    // station = _stations[i];
    std::cout << _stations[i].getName() << std::endl;
    std::cout << " Student Passes sold : ";
    std::cin >> studentAdded;
    _stations[i].update(Student, studentAdded);
    std::cout << " Adult   Passes sold : ";
    std::cin >> adultAdded;
    _stations[i].update(Adult, adultAdded);
  }  
}

void w2::Stations::report() const
{
  // Station station;
  
  std::cout << "\nPasses in Stock : Student Adult\n-------------------------------";
  
  // for(int i=0; i<_stations.size(); i++) {
  for(int i=0; i<_count; i++) {
    // station = _stations[i];
    std::cout << std::setw(19) << std::left  << _stations[i].getName();
    std::cout << std::setw(7)  << std::right << _stations[i].inStock(Student);
    std::cout << std::setw(6)                << _stations[i].inStock(Adult);
  }
  std::cout << std::endl;
}

w2::Stations::~Stations()
{
  // Station station;
  
  std::ofstream ofs(_fileName, std::ifstream::out);
  // ofs << _stations.size() << ";\n";
  ofs << _count << ";\n";
  
  // while(_stations.size() > 0) {
  for(int i=0; i<_count; i++) {
    // station = _stations.front();
    // station = _stations[i];
    // _stations.erase(_stations.begin());
    ofs << _stations[i].getName() << ';' << _stations[i].inStock(Student) << ' ' << _stations[i].inStock(Adult);
  }
  ofs.close();
}
