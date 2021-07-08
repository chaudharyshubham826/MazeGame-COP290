#ifndef UTILS_VEC2D_H
#define UTILS_VEC2D_H

#include <ostream>

class Vec2D
{
public:
    static const Vec2D Zero;

    Vec2D(): Vec2D(0, 0) {}
    Vec2D(float x, float y): aX(x), aY(y) {}
    // CONSTRUCTORS

    inline void SetX(float x) { aX = x; } 
    inline void SetY(float y) { aY = y; }

    inline float GetX() const { return aX; }
    inline float GetY() const { return aY; }

    bool operator==(const Vec2D& vec) const;
    bool operator!=(const Vec2D& vec) const;

    Vec2D operator*(float m) const;
    Vec2D operator/(float m) const;
    Vec2D operator-() const;

    Vec2D& operator*=(float m);
    Vec2D& operator/=(float m);

    Vec2D operator+(const Vec2D& vec) const;
    Vec2D operator-(const Vec2D& vec) const;
    Vec2D& operator+=(const Vec2D& vec);
    Vec2D& operator-=(const Vec2D& vec);

    float Magnitude2() const;
    float Magnitude() const;

    Vec2D GetUnitVector() const;
    Vec2D& Normalize();

    float Distance(const Vec2D& vec) const;
    float Dot(const Vec2D& vec) const;

    Vec2D ProjectOnto(const Vec2D& vec) const;
    float AngleBetween(const Vec2D& vec) const;
    Vec2D Reflect(const Vec2D& normalVec) const;

    void Rotate(float angle, const Vec2D& aroundPoint);
    Vec2D RotatedVector(float angle, const Vec2D& aroundPoint) const;

    
    friend Vec2D operator*(float m, const Vec2D& vec);

    friend std::ostream& operator<<(std::ostream& console, const Vec2D& vec);



private:
    float aX, aY;
};



#endif