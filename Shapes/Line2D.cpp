#include "Line2D.h"
#include "Utils.h"
#include <cmath>


Line2D::Line2D(): aPoint1(Vec2D::Zero), aPoint2(Vec2D::Zero) {}

Line2D::Line2D(float x1, float y1, float x2, float y2): Line2D(Vec2D(x1, y1), Vec2D(x2, y2)){}

Line2D::Line2D(const Vec2D& p1, const Vec2D& p2): aPoint1(p1), aPoint2(p2) {}

bool Line2D::operator==(const Line2D& line) const
{
    return aPoint1 == line.GetPoint1() && aPoint2 == line.GetPoint2();
}

float Line2D::MinDistanceFrom(const Vec2D& p, bool limitToSegment) const
{
    return p.Distance(ClosestPoint(p, limitToSegment));
}

Vec2D Line2D::ClosestPoint(const Vec2D& p, bool limitToSegment) const
{
    Vec2D P1ToP = p - aPoint1;
    Vec2D P1ToP2 = aPoint2 - aPoint1;

    float dot = P1ToP.Dot(P1ToP2);

    float l_P1ToP2 = P1ToP2.Magnitude2();

    float m = dot / l_P1ToP2;

    if(limitToSegment){
        m = fmax(0, fmin(1.0f, m));
    }

    return aPoint1 + P1ToP2 * m;
}

Vec2D Line2D::MidPoint() const
{
    return Vec2D((aPoint1.GetX() + aPoint2.GetX())/2.0f, (aPoint1.GetY() + aPoint2.GetY())/2.0f);
}

float Line2D::Slope() const
{
    float dx = aPoint2.GetX() - aPoint1.GetX();
    if(fabsf(dx) < TOLERANCE){
        return 0;
    }

    float dy = aPoint2.GetY() - aPoint1.GetY();

    return dy / dx;
}

float Line2D::Length() const
{
    return aPoint1.Distance(aPoint2);
}