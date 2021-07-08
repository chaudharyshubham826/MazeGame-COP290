#include "Shape.h"

void Shape::MoveBy(const Vec2D& offset)

{
    for(Vec2D& point : aPoints)
    {
        point = point + offset;
    }
}
