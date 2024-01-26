#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
    float x, y;

    Vector2D(float x = 0.0f, float y = 0.0f);

    Vector2D &add(const Vector2D &vec);
    Vector2D &subtract(const Vector2D &vec);
    // Additional vector operations like multiply, divide, etc.
};

#endif // VECTOR2D_H
