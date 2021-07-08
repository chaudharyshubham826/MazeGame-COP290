#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include "Shape.h"

class Circle: public Shape
{
public:
    Circle();
    Circle(const Vec2D& center, float radius);

    inline virtual Vec2D GetCenterPoint() const override { return aPoints[0]; }
    inline float GetRadius() const { return aRadius; }
    inline void SetRadius(float radius) { aRadius = radius; }
    inline void MoveTo(const Vec2D& p) { aPoints[0] = p; }

    bool Intersects(const Circle& otherCircle) const;
    bool ContainsPoint(const Vec2D& point) const;

private:
    float aRadius;
};

#endif