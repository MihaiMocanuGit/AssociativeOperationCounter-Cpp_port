#ifndef CONST_CARTESIAN_PRODUCT_ARR_H
#define CONST_CARTESIAN_PRODUCT_ARR_H

template <std::size_t CARDINAL_SET, std::size_t REPEAT>
class ConstCartesianProductArr
{
private:
    static constexpr int COMPUTE_NO_PRODUCTS()
    {
        int product = 1;
        for (int i = 1; i <= REPEAT; ++i)
        {
            product *= CARDINAL_SET;
        }

        return product;
    }

public:
    static consexpr int NO_PRODUCTS = COMPUTE_NO_PRODUCTS();
    int FUNCTIONS[NO_PRODUCTS][REPEAT];

    constexpr ConstCartesianProductArr() : FUNCTIONS()
    {
        for (int functionIndex = 0; functionIndex < NO_PRODUCTS; ++functionIndex)
            for (int i = 0; i < REPEAT; ++i)
                FUNCTIONS[functionIndex][i] = 0;

        for (int functI = 1; functI < NO_PRODUCTS; ++functI)
        {
            for (int i = 0; i < REPEAT; ++i)
            {
                FUNCTIONS[functI][i] = FUNCTIONS[functI - 1][i];
            }
            //The same algorithm use in generator.h, generateNext()
            int currentDigit = REPEAT - 1;
            while (currentDigit >= 0 and FUNCTIONS[functI][currentDigit] == CARDINAL_SET - 1)
            {
                for (int i = currentDigit; i < REPEAT; ++i)
                    FUNCTIONS[functI][i] = 0;
                currentDigit--;
            }

            // we increase the value of the "number" by one
            FUNCTIONS[functI][currentDigit]++;

            // and we move the current_digit pointer back to the end (in the case we actually had to carry at least a one)
            currentDigit = REPEAT - 1;

        }

    }

    /*
    void debug_printProductFunctions() const
    {
        for (int functionIndex = 0; functionIndex < COMPUTE_NO_PRODUCTS(); ++functionIndex)
        {
            std::cout << functionIndex << '\n';
            for (int i = 0; i < REPEAT; ++i)
            {
                std::cout << '\t' << FUNCTIONS[functionIndex][i] << '\t';
            }
            std::cout << '\n';
        }
    }
     */


};


#endif //CONST_CARTESIAN_PRODUCT_ARR_H
