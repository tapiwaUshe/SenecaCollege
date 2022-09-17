// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 2: UInt, Enumerations, String Class and File I/O 
#ifndef _STATION
#define _STATION

enum PassType { Student, Adult };

namespace w2
{  
  class Station
  {
    public:
      Station();
      void set(const std::string&, unsigned, unsigned);
      void update(PassType, int);
      unsigned inStock(PassType) const;
      const std::string& getName() const;
    private:
      std::string _stationName;
      unsigned _studentPassCount;
      unsigned _adultPassCount;
  };
}

#endif
