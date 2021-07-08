#ifndef SHAPES_SHAPE_H
#define SHAPES_SHAPE_H

#include "Vec2D.h"
#include <vector>

class Shape
{
public:
    virtual Vec2D GetCenterPoint() const = 0;
    virtual ~Shape() {};

    inline virtual std::vector<Vec2D> GetPoints() const { return aPoints; }
    void MoveBy(const Vec2D& offset);

protected:
    std::vector<Vec2D> aPoints;
};



#endif