// Name: Tapi Z. Ushe
// Class: OOP345
// Workshop 4: Templates
#ifndef OOP344_W4_KVLIST
#define OOP344_W4_KVLIST

#include <vector>

template <typename K, typename V, int N>
class KVList {
  static const int _maxSize = N;
  std::vector<K> _keys;
  std::vector<V> _values;
public:
  // default constructor - adopts a safe empty state
  KVList() {
    _keys.clear();
    _values.clear();
  }
  // returns the number of entires in the key-value list
  size_t size() const {
    return _keys.size();
  }
  // returns an unmodifiable reference to the key of element i in the list
  const K& key(int i) const {
    return _keys.at(i);
  }
  // returns an unmodifiable reference to the value of element i in the list
  const V& value(int i) const {
    return _values.at(i);
  }
  // adds a new element to the list if room exists and returns a reference to the current object, does nothing if no room exists
  KVList& add(const K& k, const V& v) {
    if(size() < _maxSize) {
      _keys.push_back(k);
      _values.push_back(v);
    }
    return *this;
  }
  // returns the index of the first element in the list with a key equal to k - defaults to 0
  int find(const K& k) const {
    int index = 0;
    for(auto it = _keys.begin(); it != _keys.end(); ++it, ++index) {
      if((*it) == k) {
        return index;
      }
    }
    return -1;
  }
  // replaces element i in the list with the key and value received and returns a reference to the current object
  KVList& replace(int i, const K& k, const V& v) {
    _keys.at(i) = k;
    _values.at(i) = v;
    return *this;
  }
};

#endif
