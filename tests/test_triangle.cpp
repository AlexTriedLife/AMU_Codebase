#include <gtest/gtest.h>

#include "triangle.h"

USE_NS_MATH;

TEST(TriangleTest, EquilateralTriangle) {
  std::array<std::array<float, 3>, 3> vertices = {
      {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.866f, 0.0f}}};
  Triangle triangle(vertices);
  triangle.idTriangle();
  EXPECT_EQ(triangle.getSideType(), Triangle::SideType::equilateral);
}

TEST(TriangleTest, IsoscelesTriangle) {
  std::array<std::array<float, 3>, 3> vertices = {
      {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 1.0f, 0.0f}}};
  Triangle triangle(vertices);
  triangle.idTriangle();
  EXPECT_EQ(triangle.getSideType(), Triangle::SideType::isosceles);
}

TEST(TriangleTest, ScaleneTriangle) {
  std::array<std::array<float, 3>, 3> vertices = {
      {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.5f, 0.0f}}};
  Triangle triangle(vertices);
  triangle.idTriangle();
  EXPECT_EQ(triangle.getSideType(), Triangle::SideType::scalene);
}

TEST(TriangleTest, GetSides) {
  std::array<std::array<float, 3>, 3> vertices = {
      {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}};
  Triangle triangle(vertices);
  std::array<float, 3> sides = triangle.getSides();
  EXPECT_FLOAT_EQ(sides[0], 1.0f);
  EXPECT_FLOAT_EQ(sides[1], 1.0f);
  EXPECT_FLOAT_EQ(sides[2], 1.0f);
}
/*
TEST(TriangleTest, GetAngles) {
  std::array<std::array<float, 3>, 3> vertices = {
      {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.866f, 0.0f}}};
  Triangle triangle(vertices);
  std::array<float, 3> angles = triangle.getAngles();
  EXPECT_FLOAT_EQ(angles[0], 60.0f);
  EXPECT_FLOAT_EQ(angles[1], 60.0f);
  EXPECT_FLOAT_EQ(angles[2], 60.0f);
}

TEST(TriangleTest, GetArea) {
  std::array<std::array<float, 3>, 3> vertices = {
      {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.866f, 0.0f}}};
  Triangle triangle(vertices);
  float area = triangle.getArea();
  EXPECT_FLOAT_EQ(area, 0.433f);
}

TEST(TriangleTest, GetPerimeter) {
  std::array<std::array<float, 3>, 3> vertices = {
      {{0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.5f, 0.866f, 0.0f}}};
  Triangle triangle(vertices);
  float perimeter = triangle.getPerimeter();
  EXPECT_FLOAT_EQ(perimeter, 3.0f);
}*/
