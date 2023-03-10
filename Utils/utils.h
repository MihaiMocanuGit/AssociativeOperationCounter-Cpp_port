#ifndef UTILS_H
#define UTILS_H

namespace Utils
{
    int powInt(int base, int power);

    int getElementAtIJ(int i, int j, const int arr[], int numberColumns);
    int getElementAtIJ(int i, int j, int arr[], int numberColumns);

    void setElementAtIJ(int i, int j, int value, int arr[], int numberColumns);
}

#endif //UTILS_H
