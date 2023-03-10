cmake_minimum_required(VERSION 3.23)
project(AssociativeOperationCounter_Cpp_port)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(ConstGenerators)
include_directories(Utils)

add_executable(AssociativeOperationCounter_Cpp_port
        ConstGenerators/constBijectionArr.h
        ConstGenerators/constCartesianProductArr.h
        Utils/utils.cpp
        Utils/utils.h
        generator.h
        isomorphism.h
        main.cpp
        operationPrintingBuffer.h
        validator.h)
