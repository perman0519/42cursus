#include "Vector2.hpp"

Vector2::Vector2(int x, int y) : x(x), y(y) {}
Vector2::~Vector2() {}

int Vector2::getX() const {
    return x;
}

int Vector2::getY() const {
    return y;
}

bool Vector2::operator==(const Vector2 &rhs) const {
    return x == rhs.x && y == rhs.y;
}