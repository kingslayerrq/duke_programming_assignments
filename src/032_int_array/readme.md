# Assignment 032

## Instructions

For this problem, you will be writing an `IntArray` class. 

This class will hold an array of `int`s, as well as the number of elements in the array.

It will provide the following functionality:

  - A default constructor  
    - Initalizes the size to 0 and the array to NULL
  - A constructor that takes an int
    - Initializes the size to the int passed in and the array to hold that many ints 
  - A copy constructor
    - Performs a deep copy
  - An assignment operator
    - Performs a deep copy
  - A destructor
    - Releases any allocated memory
  - An `[]` operator
    - Checks if the index is in bounds (use assert)
    - Returns a reference to the appropriate element
    * Note: there are two versions of this operator:
      ```cpp
        int& operator[](int index);
        const int& operator[](int index) const;
      ```
      They will have the exact same code.
      
      The difference is that if the object they are invoked on is "const", then the second will be used, returning a "const" reference, preventing modification of the object.
  - A `size` function
    - Returns the size of the arrray
  - An `==` operator
    - Checks two arrays to see if the have the same contents:
      + Same number of elements
      + Each element is the same as the element in the other array at
      the same index 
  - A `!=` operator
    - The opposite of the == operator
  - The `<<` operator should be overloaded on `std::ostream` and `const IntArray&` to print the array 
    - Format: {element0, element1, element2, ...elementN-1}

Note that we have provided you with four files:
  - `IntArray.h`: provides the header (interface) of this class.  
    _You should not need to modify this file._

  - `IntArray.cpp`: provides the implementation of this class.   
    **You will make your changes here.**

  - `test.cpp`: provides a main to test your array.  
    _You should not need to modify this file._

  - `Makefile`: will compile intArrayTest to test your program.

With the interface and implementation separated between the .h and the .cpp files, the functions in the .cpp file must be named with the classname and :: operator to indicate what class they live in, e.g.:

```cpp
  int IntArray::size() const { }
```

This specifies that you are defining the `size()` method in the `IntArray` class. 

Test, debug, and valgrind your code! We have provided the output of the test program which the Makefile builds.
