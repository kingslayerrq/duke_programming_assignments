#ifndef __INT_ARRAY__H__
#define __INT_ARRAY__H__

#include <cstdlib>
#include <ostream>

class IntArray {

public:
  IntArray();
  IntArray(int n);
  IntArray(const IntArray& rhs);
  ~IntArray();

  IntArray& operator=(const IntArray& rhs);
  int& operator[](int index);
  const int& operator[](int index) const;
  bool operator==(const IntArray& rhs) const;
  bool operator!=(const IntArray& rhs) const;
  
  int size() const;

private:
  int *data;
  int numElements;

};

std::ostream& operator<<(std::ostream& s, const IntArray& rhs);

#endif
