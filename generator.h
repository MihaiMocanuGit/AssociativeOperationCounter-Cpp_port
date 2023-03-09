#ifndef GENERATOR_H
#define GENERATOR_H

/*
 * Using templates to speed up running speed by allowing us to define array's size at compile time. This way I'm not
 * loosing performance with dynamic arrays. It makes the implementation a bit ugly, but I'm taking the sacrifice
 */
template <std::size_t CARDINAL_SET, std::size_t LENGHT_GROUP>
class Generator
{
private:
    /*
     * I am actually storing the data of the given operation matrix (from the example) into a 1-D array
     * initially all the elements from AxA are mapped into just a0 (which is denoted by its index, 0)
     */
    int m_currentDigit = LENGHT_GROUP - 1;
    int m_arrayProjection[LENGHT_GROUP] = {};

public:
    static constexpr int ARRAY_LENGHT = LENGHT_GROUP;

    Generator()
    {
        // we will be "counting" in base |A| = CARDINAL_SET. So we set the index to the right-most digit
        m_arrayProjection[m_currentDigit] = -1;
    }

    bool generateNext()
    {
        /*
         * if the addition would result in going over the base's max value , we need to advance towards the next more significant
         * digit and carry the one. Moreover, we have to reset all the less significant digits to their starting value
         * (that being 0)
         */
        while (m_currentDigit >= 0 and m_arrayProjection[m_currentDigit] == CARDINAL_SET - 1)
        {
            for (int i = m_currentDigit; i < LENGHT_GROUP; ++i)
                m_arrayProjection[i] = 0;
            m_currentDigit--;
        }

        /*
         * if our current_digit pointer is situatead outside the range of our number, than that means that we've gone
         * through all the possible numbers
         */
        if (m_currentDigit == -1)
            return false;

        // we increase the value of the "number" by one
        m_arrayProjection[m_currentDigit]++;

        // and we move the current_digit pointer back to the end (in the case we actually had to carry at least a one)
        m_currentDigit = LENGHT_GROUP - 1;

        return true;
    }

    int* getPtrArray()
    {
        return &m_arrayProjection;
    }
};


#endif //GENERATOR_H
