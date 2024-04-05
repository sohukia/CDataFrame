cmake_minimum_required(VERSION 3.27)
project(CDataFrame C)

set(CMAKE_C_STANDARD 17)

add_executable(CDataFrame main.c
        source/Column/Column.c
        source/Column/Column.h
        source/CDataFrame/CDataFrame.c
        source/CDataFrame/CDataFrame.h
        source/Column/Sorting/Sorting.c
        source/Column/Sorting/Sorting.h
        source/Column/Searching/Searching.c
        source/Column/Searching/Searching.h)
