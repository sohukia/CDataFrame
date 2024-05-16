cmake_minimum_required(VERSION 3.27)
project(CDataFrame C)

set(CMAKE_C_STANDARD 17)

add_executable(CDataFrame main.c
        source/Column/Column.c
        source/Column/Column.h
        source/CDataFrame/CDataFrame.c
        source/CDataFrame/CDataFrame.h
				source/Sorting/Sorting.c
				source/Sorting/Sorting.h
				source/Searching/Searching.c
				source/Searching/Searching.h
		source/types.h
		source/List/List.c
		source/List/List.h
)
