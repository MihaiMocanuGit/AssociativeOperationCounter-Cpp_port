#ifndef OPERATION_PRINTING_BUFFER_H
#define OPERATION_PRINTING_BUFFER_H

#include <fstream>
#include <string>

//#include <queue>

#include "Utils/utils.h"

template <std::size_t CARDINAL_SET>
class OperationPrintingBuffer
{
private:
    std::string outputFile = "../output_";
    std::ofstream m_outputStream;

    static constexpr int CARDINAL_SET_SQ = CARDINAL_SET * CARDINAL_SET;

    int m_totalNoOfPrints = 0;

    //std::queue<> operationBuffer
public:
    OperationPrintingBuffer()
    {
        outputFile += std::to_string(CARDINAL_SET);
        outputFile += ".txt";

        m_outputStream.open(outputFile,  std::ofstream::out | std::ofstream::trunc);
    }
    
    //void pushToBuffer(const int operationArray[CARDINAL_SET_SQ]);
    //void flushBuffer();

    void print(const int operationArray[CARDINAL_SET_SQ])
    {
        for (int i = 0; i < CARDINAL_SET; ++i)
        {
            for (int j = 0; j < CARDINAL_SET; ++j)
            {
                int element = Utils::getElementAtIJ(i, j, operationArray, CARDINAL_SET);
                element += 1;

                std::string completeElement = "a";
                completeElement += std::to_string(element);

                m_outputStream << completeElement << ' ';
            }
            m_outputStream << '\n';
        }
        if (m_totalNoOfPrints % 250 == 0)
            std::cout << "At " << m_totalNoOfPrints << " associative operations\n";
        m_totalNoOfPrints++;
        m_outputStream << "\t\t\t" << m_totalNoOfPrints << "\n\n";



    }

    ~OperationPrintingBuffer()
    {
        m_outputStream.close();
    }


};


#endif //OPERATION_PRINTING_BUFFER_H
