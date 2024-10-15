#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <array>

#include "defines.h"
#include "iTriangle.h"
NS_AMU_BEGINS
NS_MATH_BEGINS

class Triangle : amu::interface::iTriangle {
 public:
  enum class SideType {
    equilateral,  // 3 equal sides
    isosceles,    // 2 equal sides
    scalene       // 0 equal sides

  };
  enum class AngleType {
    acute,   // 3 angles < 90 degrees
    right,   // has 1 angle = 90 degrees
    obtuse,  // has 1 angle > 90 degrees
  };
  Triangle(const std::array<std::array<float, 3>, 3> vertices);
  ~Triangle() override;

  void idTriangle();

  // Getters
  
  std::array < std::array<float, 3>,3> getVertices() const override;
  std::array<float, 3> getSides() const override;
  std::array<float, 3> getAngles() const override;
  float getArea() const override;
  float getPerimeter() const override;
  SideType getSideType() const;
  AngleType getAngleType() const;

 private:
  std::array<std::array<float, 3>, 3> m_vertices;
  SideType m_sideType;
  AngleType m_angleType;
  std::array<float, 3> m_sides;
  std::array<float, 3> m_angles;
  bool isOblique;
};

NS_ENDS      // math
    NS_ENDS  // amu

#endif  // TRIANGLE_H
