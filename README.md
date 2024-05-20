# CDataFrame

## Project Idea

CDataFrame is a C library that provides a data structure similar to a DataFrame in Python's pandas library. It allows for the creation of columns of different data types and provides various functions to manipulate and analyze the data.

## Installation and Usage

To install and use the project, follow these steps:
1. Clone the GitHub repository to your local machine.
2. Navigate to the project directory.
### Run on Linux
3. Compile the project using a C compiler. For example, you can use gcc: `gcc -o main main.c source/Column/Column.c`
4. Run the compiled program: `./main`
### Run on Windows
3. Open CLion and load the project.
4. Run the main.c file.

## Features
The CDataFrame library provides the following features (at least for now):  
- Create a new column with a specific data type and title.
- Insert a value into a column.
- Convert a value in a column to a string.
- Delete a column and free all associated memory.
- Print the contents of a column.
- Count the occurrences of a value in a column.
- Get the position of a value in a column.
- Count the number of values in a column that are greater than, less than, or equal to a given value.


## Project repository
The project repository is located at: [https://github.com/sohukia/CDataFrame](https://github.com/sohukia/CDataFrame).

## Structure
The project is structured as follows:
```
.
├── main.c                   The entry point of the program
├── README.md                The documentation of the project
└── source
    ├── CDataFrame
    │   ├── CDataFrame.c     Contains the implementation of DataFrame operations
    │   └── CDataFrame.h     Contains the declaration of DataFrame and its operations
    ├── Column
    │   ├── Column.c         Contains the implementation of Column operations
    │   └── Column.h         Contains the declaration of Column and its operations
    ├── List
    │   ├── List.c           Contains the implementation of List operations
    │   └── List.h           Contains the declaration of List and its operations
    ├── Menu
    │   └── menu.h           Contains the declaration of menu operations for user interaction
    ├── Searching
    │   ├── Searching.c      Contains the implementation of searching operations in DataFrame
    │   └── Searching.h      Contains the declaration of searching operations
    ├── Sorting
    │   ├── Sorting.c        Contains the implementation of sorting operations in DataFrame
    │   └── Sorting.h        Contains the declaration of sorting operations
    └── types.h              Contains the declaration of data types used in the project
```

## License
This project is all rights reserved.
