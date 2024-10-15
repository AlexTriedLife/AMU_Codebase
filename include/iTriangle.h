#ifndef I_TRIANGLE_H
#define I_TRIANGLE_H
#include <array>
#include "defines.h"
NS_AMU_BEGINS
NS_INTERFACE_BEGINS
class iTriangle {
 public:
  virtual ~iTriangle() = default;

  /* a getter for the vertices: a(x1,y1), b(x2,y2), c(x3,y3)
   * represented by a 2d array
   */
  virtual std::array < std::array<float, 3>,3> getVertices() const = 0;
  // a getter for the side lengths: a, b, c
  virtual std::array<float, 3> getSides() const = 0;
  // a getter for the internal angles: A, B, C
  virtual std::array<float, 3> getAngles() const = 0;

  virtual float getArea() const = 0;
  virtual float getPerimeter() const = 0;

 
};
NS_ENDS      // interface
    NS_ENDS  // amu

#endif  // I_TRIANGLE_H
