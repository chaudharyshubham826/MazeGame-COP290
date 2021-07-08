#include "Triangle.h"
#include "Utils.h"
#include <cmath>

Triangle::Triangle(): Triangle(Vec2D::Zero, Vec2D::Zero, Vec2D::Zero) {}

Triangle::Triangle(const Vec2D& p1, const Vec2D& p2, const Vec2D& p3)
{
    aPoints.push_back(p1);
    aPoints.push_back(p2);
    aPoints.push_back(p3);
}

Vec2D Triangle::GetCenterPoint() const
{
    return Vec2D((aPoints[0].GetX() + aPoints[1].GetX() + aPoints[2].GetX()) / 3.0f, (aPoints[0].GetY() + aPoints[1].GetY() + aPoints[2].GetY()) / 3.0f);
}

float Triangle::Area() const
{
    return Area(aPoints[0], aPoints[1], aPoints[2]);
}

bool Triangle::ContainsPoint(const Vec2D& p) const
{
    float a1 = Area(p, aPoints[0], aPoints[1]);
    float a2 = Area(p, aPoints[1], aPoints[2]);
    float a3 = Area(p, aPoints[2], aPoints[0]);

    float a = Area();

    return IsEqual(a, a1 + a2 + a3);

}

float Triangle::Area(const Vec2D& p1, const Vec2D& p2, const Vec2D& p3) const
{
    float a1 = p1.GetX() * (p2.GetY() - p3.GetY());
    float a2 = p2.GetX() * (p3.GetY() - p1.GetY());
    float a3 = p3.GetX() * (p1.GetY() - p2.GetY());

    return fabs((a1 + a2 + a3) / 2.0f);
}
