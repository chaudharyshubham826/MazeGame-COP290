#include "AARectangle.h"
#include "Utils.h"
#include <cmath>

AARectangle::AARectangle(): AARectangle(Vec2D::Zero, Vec2D::Zero) {}

AARectangle::AARectangle(const Vec2D& topLeft, float width, float height): AARectangle(topLeft, Vec2D(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1)) {}

AARectangle::AARectangle(const Vec2D& topLeft, const Vec2D& bottomRight)
{
    aPoints.push_back(topLeft);
    aPoints.push_back(bottomRight);
}

float AARectangle::GetWidth() const
{
    return GetBottomRightPt().GetX() - GetTopLeftPt().GetX() + 1;
}

float AARectangle::GetHeight() const
{
    return GetBottomRightPt().GetY() - GetTopLeftPt().GetY() + 1;
}

void AARectangle::MoveTo(const Vec2D& pos)
{
    float width = GetWidth();
    float height = GetHeight();

    SetTopLeftPt(pos);
    SetBottomRightPt(Vec2D(pos.GetX() + width - 1, pos.GetY() + height - 1));
}

Vec2D AARectangle::GetCenterPoint() const
{
    return Vec2D(GetTopLeftPt().GetX() + GetWidth()/2.0f, GetTopLeftPt().GetY() + GetHeight()/2.0f);
}

bool AARectangle::Intersects(const AARectangle& otherRect) const
{
    return !(otherRect.GetBottomRightPt().GetY() < GetTopLeftPt().GetY() ||
            otherRect.GetTopLeftPt().GetX() > GetBottomRightPt().GetX() ||
            otherRect.GetTopLeftPt().GetY() > GetBottomRightPt().GetY() ||
            otherRect.GetBottomRightPt().GetX() < GetTopLeftPt().GetX());
}

bool AARectangle::ContainsPoint(const Vec2D& point) const
{
    bool x = point.GetX() >= GetTopLeftPt().GetX() && point.GetX() <= GetBottomRightPt().GetX();
    bool y = point.GetY() >= GetTopLeftPt().GetY() && point.GetY() <= GetBottomRightPt().GetY();

    return x && y;
}

AARectangle AARectangle::Inset(const AARectangle& rect, const Vec2D& insets)
{
    return AARectangle(rect.GetTopLeftPt() + insets, rect.GetWidth() - 2*insets.GetX(), rect.GetHeight() - 2*insets.GetY());
}

std::vector<Vec2D> AARectangle::GetPoints() const
{
    std::vector<Vec2D> allPoints;

    allPoints.push_back(aPoints[0]);
    allPoints.push_back(Vec2D(aPoints[1].GetX(), aPoints[0].GetY()));
    allPoints.push_back(aPoints[1]);
    allPoints.push_back(Vec2D(aPoints[0].GetX(), aPoints[1].GetY()));

    return allPoints;
}