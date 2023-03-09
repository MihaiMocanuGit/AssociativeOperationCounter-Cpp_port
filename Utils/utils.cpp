#include "utils.h"

int Utils::powInt(int base, int power)
{
    int result = 1;
    for (int p = 1; p <= power; ++p)
        result *= base;
    return result;
}
