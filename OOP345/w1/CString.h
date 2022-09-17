// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 1: I/O
#ifndef CSTRING_
#define CSTRING_
#define MAX 3

namespace w1
{
  class CString {
  private:
    char _string[MAX+1];
  public:
    CString(const char *string);
    void display(std::ostream &ostream) const;
  };
  std::ostream &operator<<(std::ostream &ostream, const CString &cstring);
}

#endif
