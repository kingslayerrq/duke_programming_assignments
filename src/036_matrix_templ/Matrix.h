#ifndef __T_MATRIX_H___
#define __T_MATRIX_H___

#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>


//YOUR CODE GOES HERE!
template <typename T>
class Matrix {

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& rhs);
    ~Matrix();

    int getRows() const;
    int getColumns() const;

    Matrix& operator=(const Matrix& rhs);
    const std::vector<T>& operator[](int index) const;
    std::vector<T>& operator[](int index);
    bool operator==(const Matrix& rhs) const;
    Matrix operator+(const Matrix& rhs) const;

private:
    int numRows;
    int numColumns;
    std::vector<T>** rows;
};

template <typename T>
std::ostream& operator<<(std::ostream& s, const Matrix<T>& rhs);

#include "Matrix.h"

template <typename T>
Matrix<T>::Matrix() : numRows(0), numColumns(0), rows(NULL) {
}

template <typename T>
Matrix<T>::Matrix(int r, int c) : numRows(r), numColumns(c), rows(new std::vector<T>* [r]) {
    for (int i = 0; i < numRows; ++i){
        rows[i] = new std::vector<T>(c);
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs)  {
    numRows = rhs.getRows();
    numColumns = rhs.getColumns();

    rows = new std::vector<T>* [numRows];
    for (int i = 0; i < numRows; ++i){
        rows[i] = new std::vector<T>(*rhs.rows[i]);
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < numRows; ++i){
        delete rows[i];
    }
    delete[] rows;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    if (this != &rhs){
        for (int i = 0; i < numRows; ++i){
            delete rows[i];
        }
        delete[] rows;

        numRows = rhs.getRows();
        numColumns = rhs.getColumns();

        rows = new std::vector<T>* [numRows];
        for (int i = 0; i < numRows; ++i){
            rows[i] = new std::vector<T>(*rhs.rows[i]);
        }
    }
    return *this;
}

template <typename T>
int Matrix<T>::getRows() const {
    return numRows;
}

template <typename T>
int Matrix<T>::getColumns() const {
    return numColumns;
}

template <typename T>
const std::vector<T>& Matrix<T>::operator[](int index) const {
    assert(index < numRows);
    return *rows[index];
}

template <typename T>
std::vector<T>& Matrix<T>::operator[](int index) {
    assert(index < numRows);
    return *rows[index];
}

template <typename T>
bool Matrix<T>::operator==(const Matrix<T>& rhs) const {
    if (this == &rhs) return true;
    if (numRows == rhs.getRows() && numColumns == rhs.getColumns()){
        for (int i = 0; i < numRows; ++i){
            if (*rows[i] != rhs[i]) return false;
        }
        return true;
    }
    return false;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
    assert(numRows == rhs.getRows() && numColumns == rhs.getColumns());
    Matrix<T> res = Matrix<T>(numRows, numColumns);
    for (int i = 0; i < numRows; ++i){
        for (int j = 0; j < numColumns; ++j){
            res[i][j] = (*this)[i][j] + rhs[i][j];
        }
    }
    return res;

}

template <typename T>
std::ostream& operator<<(std::ostream& s, const Matrix<T>& rhs) {
    s << "[ ";
    for (int i = 0; i < rhs.getRows(); ++i){
        s << "{";
        for (size_t j = 0; j < rhs[i].size(); ++j){
            if (j != rhs[i].size()-1){
                s << rhs[i][j] << ", ";
            }
            else{
                s << rhs[i][j];
            }
        }
        s << "}";
        if (i != rhs.getRows() - 1){
            s << ",\n";
        }
    }
    s << " ]";
    return s;
}

#endif
