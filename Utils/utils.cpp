#include "utils.h"

int Utils::powInt(int base, int power)
{
    int result = 1;
    for (int p = 1; p <= power; ++p)
        result *= base;
    return result;
}

int Utils::getElementAtIJ(int i, int j, int arr[], int numberColumns)
{
    return arr[i * numberColumns + j];
}

int Utils::setElementAtIJ(int i, int j, int value, int arr[], int numberColumns)
{
    arr[i * numberColumns + j] = value;
}