#ifndef __INT_MATRIX_H___
#define __INT_MATRIX_H___

#include "IntArray.h"
#include <assert.h>
#include <iostream>

class IntMatrix {

public:
  IntMatrix();
  IntMatrix(int r, int c);
  IntMatrix(const IntMatrix& rhs);
  ~IntMatrix();

  int getRows() const;
  int getColumns() const;

  IntMatrix& operator=(const IntMatrix& rhs);
  const IntArray& operator[](int index) const;
  IntArray& operator[](int index);
  bool operator==(const IntMatrix& rhs) const;
  IntMatrix operator+(const IntMatrix& rhs) const;

private:
  int numRows;
  int numColumns;
  IntArray** rows;
};

std::ostream& operator<<(std::ostream& s, const IntMatrix& rhs);

#endif
