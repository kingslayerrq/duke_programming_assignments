/* write your class interface in this file
   write function definitions only if they are very short
 */
#pragma once

#include <string>
#include <iostream>

class Vector2D {
  public:
  Vector2D();
  Vector2D(double x, double y);
  // void initVector(double init_x, double init_y);
  double getMagnitude() const;
  Vector2D operator+(const Vector2D& rhs) const;
  Vector2D& operator+=(const Vector2D& rhs);
  double dot(const Vector2D& rhs) const;
  void print() const;
  
  private:
    double x;
    double y;
};
