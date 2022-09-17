// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 2: UInt, Enumerations, String Class and File I/O 
#include <string>
#include "Station.h"

w2::Station::Station()
{
  _stationName = '\0';
  _studentPassCount = 0u;
  _adultPassCount = 0u;
}

void w2::Station::set(const std::string& stationName, unsigned studentPassCount, unsigned adultPassCount)
{
  _stationName = stationName;
  _studentPassCount = studentPassCount;
  _adultPassCount = adultPassCount;
}

void w2::Station::update(PassType passType, int quantity)
{
  switch(passType) {
    case Student:
      _studentPassCount += quantity;
      break;
    case Adult:
      _adultPassCount += quantity;
      break;
  }
}

unsigned w2::Station::inStock(PassType passType) const
{
  unsigned stocked;
  switch(passType) {
    case Student:
      stocked = _studentPassCount;
      break;
    case Adult:
      stocked = _adultPassCount;
      break;
  }
  return stocked;
}

const std::string& w2::Station::getName() const
{
  return _stationName;
}
