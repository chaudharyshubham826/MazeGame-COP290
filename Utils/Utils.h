#ifndef UTILS_UTILS_H
#define UTILS_UTILS_H

static const float TOLERANCE = 0.0001f;

const float PI = 3.14159f;
const float TWO_PI = 2.0f * PI;

bool IsEqual(float x, float y);
bool IsGreaterThanOrEqual(float x, float y);
bool IsLessThanOrEqual(float x, float y);

unsigned int GetIndex(unsigned int width, unsigned int r, unsigned int c);

bool StringCompare(const std::string& a, const std::string& b);

struct Size
{
	unsigned int width = 0, height = 0;
};


#endif