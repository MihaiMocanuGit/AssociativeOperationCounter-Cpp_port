#ifndef ISOMORPHISM_H
#define ISOMORPHISM_H

#include <set>

#include "ConstGenerators/constBijectionArr.h"
#include "ConstGenerators/constCartesianProductArr.h"
#include "Utils/utils.h"
template <std::size_t CARDINAL_SET>
class Isomorphism
{
private:
    // computing all bijective functions as permutations
    static constexpr ConstBijectionsArr BIJ_FUNCTIONS = ConstBijectionsArr<CARDINAL_SET>();

    /*
     * # we calculate this beforehand, it will be used in computeOperationArray. We are actually computing all the ways
     * we can write x*y using elements from the set (for computing f(xy) = f(x) * f(y))
     */
    static constexpr ConstCartesianProductArr PROD_FUNCTIONS = ConstCartesianProductArr<CARDINAL_SET, 2>();

    std::set<int> m_associativeKeys;

    static constexpr int ARR_LENGHT = CARDINAL_SET * CARDINAL_SET;

    int m_computeKey(int operationArr[ARR_LENGHT])
    {
        /*
         * the key will actually be the conversion of the number represented in nparray from base <self.__cardinal> into
         * base 10
         */

        int sum = 0;
        for (int i = 0; i < ARR_LENGHT; ++i)
            sum += operationArr[i] * Utils::powInt(CARDINAL_SET, i);
        return sum;
    }
public:
    Isomorphism() = default;

};



#endif //SOMORPHISM_H
