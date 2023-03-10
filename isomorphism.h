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
    // computing at compile time all bijective functions as permutations
    static constexpr ConstBijectionsArr BIJ_FUNCTIONS = ConstBijectionsArr<CARDINAL_SET>();

    /*
     * # we calculate this beforehand, it will be used in computeOperationArray. We are actually computing all the ways
     * we can write x*y using elements from the set (for computing f(xy) = f(x) * f(y))
     */
    static constexpr ConstCartesianProductArr PROD_GROUPS = ConstCartesianProductArr<CARDINAL_SET, 2>();

    //in this set we store the unique keys that characterize a semigroup
    std::set<int> m_associativeKeys;

    static constexpr int CARDINAL_SET_SQ = CARDINAL_SET * CARDINAL_SET;

    //generating unique keys that characterize a semigroup
    int m_computeKey(int operationArr[CARDINAL_SET_SQ])
    {
        /*
         * the key will actually be the conversion of the number represented in operationArr from base <CARDINAL_SET> into
         * base 10
         */

        int sum = 0;
        for (int i = 0; i < CARDINAL_SET_SQ; ++i)
            sum += operationArr[i] * Utils::powInt(CARDINAL_SET, i);
        return sum;
    }

    /*
     * Given a bijective function and an operation, it computes an isomorphic structure
     * (in our case isomorphic semigroup)
     */
    void m_computeNewOperationArray(const int bijFunction[CARDINAL_SET], int oldOperationArray[CARDINAL_SET_SQ],
                                    int newOperationArray[CARDINAL_SET_SQ])
    {
        //TODO: Make sure that this is really useless
        //for (int i = 0; i < CARDINAL_SET * CARDINAL_SET; ++i)
        //    newOperationArray[i] = -1;

        /*
         * We go through every way of grouping x and y and compute f(xy) = f(x) * f(y)
         * oldOperationArray is used to compute xy
         * newOperationArray is used to store f(x) * f(y)
         */
        for (int groupIndex = 0; groupIndex < PROD_GROUPS.NO_PRODUCTS; ++groupIndex)
        {
            int x = PROD_GROUPS.PRODUCTS[groupIndex][0];
            int y = PROD_GROUPS.PRODUCTS[groupIndex][1];
            int xy = Utils::getElementAtIJ(x,y, oldOperationArray,CARDINAL_SET);

            int f_x = bijFunction[x];
            int f_y = bijFunction[y];
            int f_xy = bijFunction[xy];

            Utils::setElementAtIJ(f_x, f_y, f_xy, newOperationArray, CARDINAL_SET);
        }
    }
public:
    Isomorphism() = default;

    static constexpr int MAX_ISOMORPHISMS = BIJ_FUNCTIONS.NO_BIJECTIONS;

    /*
     * Given an operation, it computes into isomorphicOperations[][] all unique isomorphisms
     */
    void compute_isomorphisms(int operationArray[CARDINAL_SET_SQ],
                              int isomorphicOperations[MAX_ISOMORPHISMS][CARDINAL_SET_SQ], int &rNoIsomorphisms)
    {
        int key = m_computeKey(operationArray);
        rNoIsomorphisms = 0;
        //if the given operation was already computed do nothing,
        if (m_associativeKeys.contains(key))
            return;

        //otherwise compute all isomorphisms to that operation

        //we go through every bijective function
        for (int bijIndex = 0; bijIndex < MAX_ISOMORPHISMS; ++bijIndex)
        {
            const int *bijFunction = BIJ_FUNCTIONS.FUNCTIONS[bijIndex];
            int *newOperation = isomorphicOperations[rNoIsomorphisms];

            //computes new operation given a bijective function and an old operation
            m_computeNewOperationArray(bijFunction, operationArray, newOperation);

            //checking for uniqueness in set
            int newKey = m_computeKey(newOperation);
            if (!m_associativeKeys.contains(newKey))
            {
                m_associativeKeys.insert(newKey);
                rNoIsomorphisms++;
            }
        }

    }

};



#endif //ISOMORPHISM_H
