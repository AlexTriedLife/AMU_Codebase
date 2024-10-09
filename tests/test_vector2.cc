#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "vector2.h"
#include <variant>
#include <cmath>
#include <iostream>

TEST(Vector2Tests, TestMagnitude) {
    Vector2 testVector(0.0,0.0); 
    ASSERT_EQ(testVector.x,0);
    ASSERT_EQ(testVector.y,0); 
}


