#include <iostream>
#include <cmath>
#include "Utils.h"
#include <algorithm>
#include <cctype>

using namespace std;


bool IsEqual(float x, float y)
{
    return fabsf(x-y) < TOLERANCE;
}

bool IsGreaterThanOrEqual(float x, float y)
{
    return x>y || IsEqual(x, y);
}

bool IsLessThanOrEqual(float x, float y)
{
    return x<y || IsEqual(x, y);
}

unsigned int GetIndex(unsigned int width, unsigned int r, unsigned int c)
{
	return r * width + c;
}

bool StringCompare(const std::string& a, const std::string& b)
{
	if(a.length() == b.length())
	{
		return std::equal(b.begin(), b.end(), a.begin(), [](unsigned char a, unsigned char b){
			return std::tolower(a) == std::tolower(b);
		});
	}

	return false;
}

