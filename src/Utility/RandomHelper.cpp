#include "Utility/RandomHelper.hpp"

namespace randomhelper {
float RandomFloatBetween(float min, float max)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diffrence = max - min;
    float r = random * diffrence;
    return min + r;
}

int RandomIntBetween(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}
}
