#include "Circle.h"
#include "Utils.h"

Circle::Circle(): Circle(Vec2D::Zero, 0) {}

Circle::Circle(const Vec2D& center, float radius): aRadius(radius)
{
    aPoints.push_back(center);
}

bool Circle::Intersects(const Circle& otherCircle) const
{
    return GetCenterPoint().Distance(otherCircle.GetCenterPoint()) < GetRadius() + otherCircle.GetRadius();
}

bool Circle::ContainsPoint(const Vec2D& point) const
{
    return IsLessThanOrEqual(point.Distance(GetCenterPoint()), aRadius);
}