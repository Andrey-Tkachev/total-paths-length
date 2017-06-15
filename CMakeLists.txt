cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



project(FastFourierTransform)

enable_testing()

set(CMAKE_BUILD_TYPE Release)

include_directories(include)

set(SRC_LIST src/main.cpp src/graph.cpp src/algorithms.cpp)

add_executable( paths-len ${SRC_LIST} )


set(TESTS_SOURCES
        tests/tests.cpp src/graph.cpp src/algorithms.cpp)
find_package (Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
set(TEST test_graph)
add_executable(${TEST} ${TESTS_SOURCES})
target_link_libraries(${TEST} ${PROJECT} ${Boost_LIBRARIES})

add_test(${TEST} ${TEST})
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

