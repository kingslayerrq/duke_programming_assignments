#include "IntArray.h"
#include <assert.h>
#include <ostream>

IntArray::IntArray() : numElements(0), data(NULL) {
}

IntArray::IntArray(int n) : numElements(n), data(new int[n]()) {
}

IntArray::IntArray(const IntArray& rhs)  {
    numElements = rhs.numElements;
    data = new int[numElements]();
    for (int i = 0; i < numElements; ++i){
        data[i] = rhs.data[i];
    }
}

IntArray::~IntArray() {
    delete[] data;
}

IntArray& IntArray::operator=(const IntArray& rhs) {
    if (this != &rhs) {
        numElements = rhs.numElements;
        delete[] data;
        data = new int[numElements]();
        for (int i = 0; i < numElements; ++i){
            data[i] = rhs.data[i];
        }
    }
    return *this;
}

const int& IntArray::operator[](int index) const {
    assert(index < numElements);
    return data[index];
}

int& IntArray::operator[](int index) {
    assert(index < numElements);
    return data[index];
}

int IntArray::size() const {
    return static_cast<int>(sizeof(data) / sizeof(data[0]));
}

bool IntArray::operator==(const IntArray& rhs) const {
    if (this == &rhs) return true;
    if (numElements != rhs.numElements) return false;
    for (int i = 0; i < numElements; ++i) {
        if (data[i] != rhs.data[i]) return false;
    }
    return true;
}

bool IntArray::operator!=(const IntArray& rhs) const {
    if (numElements == rhs.numElements) {
        for (int i = 0; i < numElements; ++i){
            if (data[i] != rhs.data[i]) return true;
        }
        return false;
    }
    else {
        return true;
    }
    
}

std::ostream& operator<<(std::ostream& s, const IntArray& rhs) {
}
