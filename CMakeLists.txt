cmake_minimum_required(VERSION 3.13)
project(pageRank)

set(CMAKE_CXX_STANDARD 14)

add_executable(pageRank main.cpp matrix.cpp matrix.hpp utilities.cpp utilities.hpp q_matrix.hpp q_matrix.cpp)