#ifndef SHAPES_AARECTANGLE_H
#define SHAPES_AARECTANGLE_H

#include "Shape.h"

class AARectangle: public Shape
{
public:
    AARectangle();
    AARectangle(const Vec2D& topLeft, float width, float height);
    AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight);

    inline void SetTopLeftPt(const Vec2D& topLeft) {aPoints[0] = topLeft;}
    inline void SetBottomRightPt(const Vec2D& bottomRight) {aPoints[1] = bottomRight;}

    Vec2D GetTopLeftPt() const {return aPoints[0];}
    Vec2D GetBottomRightPt() const {return aPoints[1];}

    float GetWidth() const;
    float GetHeight() const;

    void MoveTo(const Vec2D& pos);

    virtual Vec2D GetCenterPoint() const override;

    bool Intersects(const AARectangle& otherRect) const;

    bool ContainsPoint(const Vec2D& point) const;

    static AARectangle Inset(const AARectangle& rect, Vec2D& insets);

    virtual std::vector<Vec2D> GetPoints() const override;
};


#endif