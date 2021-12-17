cmake_minimum_required(VERSION 3.0.0)
project(source VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(source main.cpp)
# Set cpp standard to c++17
set(CMAKE_CXX_STANDARD 17)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_library(
    Huffman 
    Huffman.cpp
)

target_link_libraries(
    source PUBLIC
    Huffman
    )