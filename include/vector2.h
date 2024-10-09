#ifndef VECTOR2_H
#define VECTOR2_H
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <variant>

class Vector2 {
       public:
        Vector2(double x, double y);
        Vector2(const Vector2& obJ);
        ~Vector2();
        double x, y;

        // Unit vector
        double magnitude() const;

       private:
};

#endif  // VECTOR2_H
