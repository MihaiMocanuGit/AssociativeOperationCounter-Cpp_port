#include <iostream>

#include "validator.h"



int main()
{
    constexpr int CARDINAL_SET = 2;
    Validator<CARDINAL_SET> validator;
    validator.startGeneration();

    return 0;
}