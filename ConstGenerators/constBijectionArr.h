//
// Created by mihai on 3/9/23.
//

#ifndef CONSTBIJECTIONARR_H
#define CONSTBIJECTIONARR_H


template <std::size_t CARDINAL_SET>
class ConstBijectionsArr
{
private:
    static constexpr int COMPUTE_FACTORIAL()
    {
        int factorial = 1;
        for (int i = 2; i <= CARDINAL_SET; ++i)
        {
            factorial *= i;
        }
        return factorial;
    }

public:
    int FUNCTIONS[COMPUTE_FACTORIAL()][CARDINAL_SET];

    constexpr ConstBijectionsArr() : FUNCTIONS()
    {
        for (int functionIndex = 0; functionIndex < COMPUTE_FACTORIAL(); ++functionIndex)
            for (int i = 0; i < CARDINAL_SET; ++i)
                FUNCTIONS[functionIndex][i] = i;

        for (int functI = 1; functI < COMPUTE_FACTORIAL(); ++functI)
        {
            for (int i = 0; i < CARDINAL_SET; ++i)
            {
                FUNCTIONS[functI][i] = FUNCTIONS[functI - 1][i];
            }
            //https://stackoverflow.com/questions/1622532/algorithm-to-find-next-greater-permutation-of-a-given-string
            //1
            int i = CARDINAL_SET - 1;
            while (i > 0 and FUNCTIONS[functI][i - 1] >= FUNCTIONS[functI][i])
                i--;

            //2
            int j = CARDINAL_SET - 1;
            while (FUNCTIONS[functI][j] <= FUNCTIONS[functI][i - 1])
                j--;

            //3
            int temp = FUNCTIONS[functI][i - 1];
            FUNCTIONS[functI][i - 1] = FUNCTIONS[functI][j];
            FUNCTIONS[functI][j] = temp;

            //4
            j = CARDINAL_SET - 1;
            while (i < j)
            {
                temp = FUNCTIONS[functI][i];
                FUNCTIONS[functI][i] = FUNCTIONS[functI][j];
                FUNCTIONS[functI][j] = temp;
                i++;
                j--;
            }

        }

    }

    /*
    void debug_printBijectiveFunctions() const
    {
        for (int functionIndex = 0; functionIndex < COMPUTE_FACTORIAL(); ++functionIndex)
        {
            std::cout << functionIndex << '\n';
            for (int i = 0; i < CARDINAL_SET; ++i)
            {
                std::cout << '\t' << FUNCTIONS[functionIndex][i] << '\t';
            }
            std::cout << '\n';
        }
    }
    */
};


#endif //CONSTBIJECTIONARR_H
