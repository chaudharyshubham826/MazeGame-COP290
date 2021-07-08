#include <iostream>
#include <cmath>
#include "Utils.h"

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




