#include "vector2.h"


Vector2::Vector2(double x, double y) : x(x), y(y) {}

Vector2::Vector2(const Vector2 &obj) : x(obj.x), y(obj.y) {}

Vector2::~Vector2() {}

double Vector2::magnitude() const { 
    if (x == 0.0 && y == 0.0) {
        throw std::runtime_error("Magnitude of zero vector is undefined");
    }
    
    return std::sqrt(x * x + y * y);
}