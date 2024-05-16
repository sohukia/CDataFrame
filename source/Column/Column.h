//
// Created by sohukia on 3/30/2024.
//

#ifndef CDATAFRAME_COLUMN_H
#define CDATAFRAME_COLUMN_H

#include "../types.h"

/**
 * @brief Creates a new column
 * @param title: the title of the column
 * @param max_size: the maximum size of the column
 * @param datatype: the datatype of the column
 * @return A pointer to the newly created column
 */
Column *create_column(const char *title, unsigned int max_size, DataType datatype);

/**
 * @brief Inserts some data into a column
 * @param column: the column to insert the value into
 * @param data: the value to insert
 */
void add_data(Column *column, COLUMN_TYPE *data);

/**
 * @brief Converts a value to a string
 * @param column: The column that contains the value
 * @param i: The index of the value in the column
 * @param buffer: The buffer to store the string
 * @return the lenght of the value inserted in the buffer
 */
int convert_value(const Column *column, unsigned long long int i, char *buffer);

/**
 * @brief Deletes a column and frees all associated memory
 * @param column: The column to free
 */
void free_column(Column *column);

/**
 * @brief Prints the contents of a column
 * @param column: The column to print
 */
void print_column(const Column *column);

#endif //CDATAFRAME_COLUMN_H