#include "IntMatrix.h"

IntMatrix::IntMatrix() : numRows(0), numColumns(0), rows(NULL) {
}

IntMatrix::IntMatrix(int r, int c) : numRows(r), numColumns(c), rows(new IntArray* [r]) {
    for (int i = 0; i < numRows; ++i){
        rows[i] = new IntArray(c);
    }
}

IntMatrix::IntMatrix(const IntMatrix& rhs)  {
    numRows = rhs.getRows();
    numColumns = rhs.getColumns();

    rows = new IntArray* [numRows];
    for (int i = 0; i < numRows; ++i){
        rows[i] = new IntArray(*rhs.rows[i]);
    }
}

IntMatrix::~IntMatrix() {
    for (int i = 0; i < numRows; ++i){
        delete rows[i];
    }
    delete[] rows;
}

IntMatrix& IntMatrix::operator=(const IntMatrix& rhs) {
    if (this != &rhs){
        for (int i = 0; i < numRows; ++i){
            delete rows[i];
        }
        delete[] rows;

        numRows = rhs.getRows();
        numColumns = rhs.getColumns();

        rows = new IntArray* [numRows];
        for (int i = 0; i < numRows; ++i){
            rows[i] = new IntArray(*rhs.rows[i]);
        }
    }
    return *this;
}

int IntMatrix::getRows() const {
    return numRows;
}

int IntMatrix::getColumns() const {
    return numColumns;
}

const IntArray& IntMatrix::operator[](int index) const {
    assert(index < numRows);
    return *rows[index];
}

IntArray& IntMatrix::operator[](int index) {
    assert(index < numRows);
    return *rows[index];
}

bool IntMatrix::operator==(const IntMatrix& rhs) const {
    if (this == &rhs) return true;
    if (numRows == rhs.getRows() && numColumns == rhs.getColumns()){
        for (int i = 0; i < numRows; ++i){
            if (*rows[i] != rhs[i]) return false;
        }
        return true;
    }
    return false;
}

IntMatrix IntMatrix::operator+(const IntMatrix& rhs) const {
    assert(numRows == rhs.getRows() && numColumns == rhs.getColumns());
    IntMatrix res = IntMatrix(numRows, numColumns);
    for (int i = 0; i < numRows; ++i){
        for (int j = 0; j < numColumns; ++j){
            res[i][j] = (*this)[i][j] + rhs[i][j];
        }
    }
    return res;

}

std::ostream& operator<<(std::ostream& s, const IntMatrix& rhs) {
    s << "[ ";
    for (int i = 0; i < rhs.getRows(); ++i){
        if (i == rhs.getRows() - 1){
            s << rhs[i];
        }
        else{
            s << rhs[i] << ",\n";
        }
    }
    s << " ]";
    return s;
}
