#ifndef SHAPES_TRIANGLE_H
#define SHAPES_TRIANGLE_H

#include "Shape.h"

class Triangle: public Shape
{
public:
    Triangle();
    Triangle(const Vec2D& p1, const Vec2D& p2, const Vec2D& p3);

    inline void SetP1(const Vec2D& p1) {aPoints[0] = p1;}
    inline void SetP2(const Vec2D& p2) {aPoints[0] = p2;}
    inline void SetP3(const Vec2D& p3) {aPoints[0] = p3;}

    inline Vec2D GetP1() const {return aPoints[0];}
    inline Vec2D GetP2() const {return aPoints[1];}
    inline Vec2D GetP3() const {return aPoints[2];}

    virtual Vec2D GetCenterPoint() const override;

    float Area() const;

    bool ContainsPoint(const Vec2D& p) const;

private:
    float Area(const Vec2D& p1, const Vec2D& p2, const Vec2D& p3) const;

};


#endif