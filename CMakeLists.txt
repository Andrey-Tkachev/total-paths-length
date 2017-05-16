cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



project(FastFourierTransform)

SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        "Single Directory for all"
    )

SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_BINARY_DIR}/bin
        CACHE PATH
        "Single Directory for all"
    )

enable_testing()

set(CMAKE_BUILD_TYPE Release)

include_directories(include)


include_directories(include)

set(SRC_LIST src/main.cpp src/graph.cpp)

add_executable( paths-len ${SRC_LIST} )
#add_subdirectory( test build/test)
