#pragma once

class Vector2 {
    int x;
    int y;

public:
    Vector2(int x, int y);
    ~Vector2();

    int getX() const;
    int getY() const;

    bool operator==(const Vector2 &rhs) const;
};