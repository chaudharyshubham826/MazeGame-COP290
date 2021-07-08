#include<iostream>
#include<cmath>
#include<cassert>

#include "Vec2D.h"
#include "Utils.h"

using namespace std;

const Vec2D Vec2D::Zero;

ostream& operator<<(std::ostream& console, const Vec2D& vec){
    console << "X: " << vec.aX << ", Y: " << vec.aY;
    return console;
}

Vec2D operator*(float m, const Vec2D& vec)
{
    return vec * m;
}


bool Vec2D::operator==(const Vec2D& vec) const
{
    return IsEqual(aX, vec.GetX()) && IsEqual(aY, vec.GetY());
}

bool Vec2D::operator!=(const Vec2D& vec) const
{
    return !(*this == vec);
}

Vec2D Vec2D::operator*(float m) const
{
    return Vec2D(aX*m, aY*m);
}

Vec2D Vec2D::operator/(float m) const
{
    assert(fabsf(m) > TOLERANCE);

    return Vec2D(aX/m, aY/m);
}

Vec2D& Vec2D::operator*=(float m){
    (*this) = (*this) * m;
    return *this;
}


Vec2D& Vec2D::operator/=(float m){
    assert(fabsf(m) > TOLERANCE);

    (*this) = (*this) / m;
    return *this;
}

Vec2D Vec2D::operator-() const
{
    return Vec2D(-aX, -aY);
}



Vec2D Vec2D::operator+(const Vec2D& vec) const
{
    return Vec2D(aX + vec.aX, aY + vec.aY);
}

Vec2D Vec2D::operator-(const Vec2D& vec) const
{
    return Vec2D(aX - vec.aX, aY - vec.aY);
}

Vec2D& Vec2D::operator+=(const Vec2D& vec)
{
    *this = *this + vec;
    return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& vec)
{
    *this = *this - vec;
    return *this;
}

float Vec2D::Magnitude2() const
{
    return aX*aX + aY*aY;
}

float Vec2D::Magnitude() const
{
    return sqrt(Magnitude2());
}

Vec2D Vec2D::GetUnitVector() const
{
    float mag = Magnitude();

    if(mag > TOLERANCE){
        return *this/mag;
    }

    return Vec2D::Zero;
}

Vec2D& Vec2D::Normalize()
{
    float mag = Magnitude();

    if(mag > TOLERANCE){
        *this/=mag;
    }

    return *this;
}

float Vec2D::Distance(const Vec2D& vec) const
{
    return (vec - *this).Magnitude();
}

float Vec2D::Dot(const Vec2D& vec) const
{
    return (aX*vec.aX + aY*vec.aY);
}

Vec2D Vec2D::ProjectOnto(const Vec2D& vec) const
{
    Vec2D unitVec = vec.GetUnitVector();

    float dotProd = Dot(unitVec);

    return unitVec*dotProd;
}

float Vec2D::AngleBetween(const Vec2D& vec) const
{
    return acosf(GetUnitVector().Dot(vec.GetUnitVector()));
}

Vec2D Vec2D::Reflect(const Vec2D& normalVec) const
{
    //v - 2*(v dot n)n

    return *this - ProjectOnto(normalVec);

}

void Vec2D::Rotate(float angle, const Vec2D& aroundPoint)
{
    float sine = sinf(angle);
    float cosine = cosf(angle);

    Vec2D vec(aX, aY);
    vec -= aroundPoint;

    float xRot = vec.aX * cosine - vec.aY * sine;
    float yRot = vec.aX * sine + vec.aY * cosine;

    Vec2D rotated = Vec2D(xRot, yRot);

    *this = rotated + aroundPoint;
}

Vec2D Vec2D::RotatedVector(float angle, const Vec2D& aroundPoint) const
{
    float sine = sinf(angle);
    float cosine = cosf(angle);

    Vec2D vec(aX, aY);
    vec -= aroundPoint;

    float xRot = vec.aX * cosine - vec.aY * sine;
    float yRot = vec.aX * sine + vec.aY * cosine;

    Vec2D rotated = Vec2D(xRot, yRot);

    return rotated + aroundPoint;
}