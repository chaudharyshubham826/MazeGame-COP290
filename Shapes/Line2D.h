#ifndef SHAPES_LINE2D_H
#define SHAPES_LINE2D_H

#include "Vec2D.h"


class Line2D
{
public:
    Line2D();
    Line2D(float x1, float y1, float x2, float y2);
    Line2D(const Vec2D& p1, const Vec2D& p2);

    inline const Vec2D& GetPoint1() const {return aPoint1;}
    inline const Vec2D& GetPoint2() const {return aPoint2;}

    inline void SetPoint1(const Vec2D& p1) {aPoint1 = p1;}
    inline void SetPoint2(const Vec2D& p2) {aPoint2 = p2;}

    bool operator==(const Line2D& line) const;
    float MinDistanceFrom(const Vec2D& p, bool limitToSegment = false) const;
    Vec2D ClosestPoint(const Vec2D& p, bool limitToSegment = false) const;

    Vec2D MidPoint() const;
    float Slope() const;
    float Length() const;


private:
    Vec2D aPoint1;
    Vec2D aPoint2;

};

#endif