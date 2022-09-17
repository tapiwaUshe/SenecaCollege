// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 3: Copy & Move Semantics
#include <iostream>
#include <fstream>
#include <vector>
#include "Text.h"

w3::Text::Text() {
  _data.clear();
}

w3::Text::Text(const std::string fileName) {
  std::fstream fs(fileName);
  if(fs.fail()) return;
  std::string line;
  while(getline(fs, line)) {
    _data.push_back(line);
  }
  fs.close();
}

w3::Text::Text(const w3::Text& text) {
  *this = text;
}

w3::Text::Text(const w3::Text&& text) {
  *this = text;
}

w3::Text& w3::Text::operator=(const w3::Text& text) {
  if(this != &text) _data = text._data;
	return *this;
}

w3::Text&& w3::Text::operator=(w3::Text&& text) {
  if(this != &text) _data = text._data;
  return std::move(*this);
}

size_t w3::Text::size() const {
  return _data.size();
}
