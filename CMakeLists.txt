cmake_minimum_required(VERSION 3.14)
project(clion_projects)

set(CMAKE_CXX_STANDARD 14)

add_executable(clion_projects main.cpp selectionSort.cpp bucketSort.cpp bucketSort.h timSort.cpp mergeSort.cpp quickSort.cpp quickSort.h selectionSort.h timSort.h mergeSort.h test.cpp test.h)