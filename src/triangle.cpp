#include "triangle.h"

USE_NS_MATH;

Triangle::Triangle(const std::array<std::array<float, 3>, 3> vertices)
    : m_vertices(vertices) {}

Triangle::~Triangle() {}

void Triangle::idTriangle() {
        if (m_sides[0] == m_sides[1] && m_sides[2]) {
                m_sideType = Triangle::SideType::equilateral;
        } else if (m_sides[0] == m_sides[1] || m_sides[2] ||
                   m_sides[1] == m_sides[2]) {
                m_sideType = Triangle::SideType::isosceles;
        } else if (m_sides[0] != m_sides[1] ||
                   m_sides[2] && m_sides[1] != m_sides[2]) {
                m_sideType = Triangle::SideType::scalene;
        }
}

std::array<std::array<float, 3>, 3> Triangle::getVertices() const {
        return m_vertices;
}

std::array<float, 3> Triangle::getSides() const {
        return std::array<float, 3>();
}

std::array<float, 3> Triangle::getAngles() const {
        return std::array<float, 3>();
}

float Triangle::getArea() const { return 0.0f; }

float Triangle::getPerimeter() const { return 0.0f; }

Triangle::SideType Triangle::getSideType() const { return m_sideType; }

Triangle::AngleType Triangle::getAngleType() const { return m_angleType; }
