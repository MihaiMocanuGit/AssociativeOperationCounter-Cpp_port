#include <iostream>

#include "validator.h"
#include <chrono>


int main()
{
    //Change the number below to generate semigroups on different sets
    constexpr int CARDINAL_SET = 4;

    Validator<CARDINAL_SET> validator;

    auto timerStart = std::chrono::high_resolution_clock::now();
    validator.startGeneration();
    auto timerStop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timerStop - timerStart);

    std::cout << duration.count() << "\tmilliseconds" << std::endl;

    return 0;
}