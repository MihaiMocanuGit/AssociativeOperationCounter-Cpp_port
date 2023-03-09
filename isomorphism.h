#ifndef ISOMORPHISM_H
#define ISOMORPHISM_H

#include "constBijectionArr.h"


template <std::size_t CARDINAL_SET>
class Isomorphism
{
private:
    // computing all bijective functions as permutations
    static constexpr ConstBijectionsArr BIJ_FUNCTIONS = ConstBijectionsArr<CARDINAL_SET>();

public:
    Isomorphism() = default;

};



#endif //SOMORPHISM_H
