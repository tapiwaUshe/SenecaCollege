// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 3: Copy & Move Semantics
#ifndef OOP344_W3_TEXT
#define OOP344_W3_TEXT
#include <vector>
namespace w3 {
  class Text {
  private:
    std::vector<std::string> _data;
    size_t _lineCount;
  public:
    Text();
    Text(const std::string fileName);
    Text(const Text& text);
    Text(const Text&& text);
    Text& operator=(const Text& text);
    Text&& operator=(Text&& text);
    size_t size() const;
  };
}

#endif
