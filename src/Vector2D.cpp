#include "Vector2D.h"

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D &Vector2D::add(const Vector2D &vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2D &Vector2D::subtract(const Vector2D &vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

// Implement other vector operations if necessary
