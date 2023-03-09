#ifndef ISOMORPHISM_H
#define ISOMORPHISM_H

#include "ConstGenerators/constBijectionArr.h"
#include "ConstGenerators/constCartesianProductArr.h"

template <std::size_t CARDINAL_SET>
class Isomorphism
{
private:
    // computing all bijective functions as permutations
    static constexpr ConstBijectionsArr BIJ_FUNCTIONS = ConstBijectionsArr<CARDINAL_SET>();

public:
    static constexpr ConstCartesianProductArr PROD_FUNCTIONS = ConstCartesianProductArr<CARDINAL_SET, 2>();
    Isomorphism() = default;

};



#endif //SOMORPHISM_H
