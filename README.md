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

## License
This project is all rights reserved.
