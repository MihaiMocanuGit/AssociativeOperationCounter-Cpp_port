#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "isomorphism.h"
#include "generator.h"
#include "operationPrintingBuffer.h"

template <std::size_t CARDINAL_SET>
class Validator
{
private:
    static constexpr int CARDINAL_SET_SQ = CARDINAL_SET * CARDINAL_SET;

    /*
     * # we calculate this beforehand, it will be used in m_isAssociative. We are actually computing all the ways
     * we can write x*y*z using elements from the set (for (xy)z = x(yz) )
     */
    static constexpr ConstCartesianProductArr PROD_GROUPS = ConstCartesianProductArr<CARDINAL_SET, 3>();

    //Class used to continuously generate operations
    Generator<CARDINAL_SET, CARDINAL_SET_SQ> m_generator = Generator<CARDINAL_SET, CARDINAL_SET_SQ>();

    //Class used to generate all isomorphic structures (semigroups) to a given operation.
    Isomorphism<CARDINAL_SET> m_isomorphism = Isomorphism<CARDINAL_SET>();

    //Class used for printing the semigroups in file
    OperationPrintingBuffer<CARDINAL_SET> m_printer = OperationPrintingBuffer<CARDINAL_SET>();



    /*
     * Checks if the current operation stored in the Generator is associative
     */
    bool m_isAssociative()
    {
        /*
         * (x * y) * z =?= x * (y * z)
         * We use PROD_GROUPS to go through all possible groups of <CARDINAL_SET> elements placed into 3 blocks
         * the first space representing x, the second y and the third z
         */
        const int *operationArray = m_generator.getPtrArray();

        for (int groupIndex = 0; groupIndex < PROD_GROUPS.NO_PRODUCTS; ++groupIndex)
        {
            int x = PROD_GROUPS.PRODUCTS[groupIndex][0];
            int y = PROD_GROUPS.PRODUCTS[groupIndex][1];
            int z = PROD_GROUPS.PRODUCTS[groupIndex][2];
            /*
             * (x * y) * z =?= x * (y * z)
             *  leftSide   =?= rightSide
             */
            int xy = Utils::getElementAtIJ(x, y, operationArray, CARDINAL_SET);
            int leftSide = Utils::getElementAtIJ(xy,z, operationArray, CARDINAL_SET);

            int yz = Utils::getElementAtIJ(y, z, operationArray, CARDINAL_SET);
            int rightSide = Utils::getElementAtIJ(x,yz, operationArray, CARDINAL_SET);

            if (leftSide != rightSide)
                return false;
        }

        return true;
    }

    /*
     * Using the Generator, it searches through operations until it finds one that is associative
     */
    bool m_generateNextValid()
    {
        bool hasNotFinished = m_generator.generateNext();

        while (hasNotFinished and not m_isAssociative())
            hasNotFinished = m_generator.generateNext();

        return hasNotFinished;
    }
public:
    Validator() = default;

    /*
     * This function starts the whole program, the main idea is that using m_generateNextValid(), it finds associative
     * operations. After finding one, the method m_isomorphism.compute_isomorphisms() will generate all unique semigroup
     * isomorphisms, which will be printed into the text file.
     */
    void startGeneration()
    {
        while (m_generateNextValid())
        {
            int isomorphicOperations[Isomorphism<CARDINAL_SET>::MAX_ISOMORPHISMS][CARDINAL_SET_SQ];
            int noOfIsomorphisms;

            m_isomorphism.compute_isomorphisms(m_generator.getPtrArray(),
                                               isomorphicOperations, noOfIsomorphisms);

            for (int isomorphismIndex = 0; isomorphismIndex < noOfIsomorphisms; ++isomorphismIndex)
                m_printer.print(isomorphicOperations[isomorphismIndex]);

        }

    }


};


#endif //VALIDATOR_H
