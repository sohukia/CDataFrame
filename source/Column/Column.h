//
// Created by sohukia on 3/30/2024.
//

#ifndef CDATAFRAME_COLUMN_H
#define CDATAFRAME_COLUMN_H

#include "../types.h"

#define REALLOC_SIZE 256
#define ASC 0
#define DESC 1

/**
 * @brief Creates a new column
 * @param type: The data type of the column
 * @param title: The title of the column
 * @return A pointer to the newly created column
 */
Column *create_column(DataType type, char *title);

/**
 * @brief Inserts a value into a column
 * @param column: The column to insert the value into
 * @param value: The value to insert
 * @return 1 if the value was successfully inserted, 0 otherwise
 */
int insert_value(Column *column, void *value);

/**
 * @brief Converts a value to a string
 * @param column: The column that contains the value
 * @param i: The index of the value in the column
 * @param str: The string to store the converted value
 * @param size: The size of the string
 */
void convert_value(Column *column, unsigned long long int i, char *str, int size);

/**
 * @brief Deletes a column and frees all associated memory
 * @param column: The column to delete
 */
void delete_column(Column **column);

/**
 * @brief Prints the contents of a column
 * @param column: The column to print
 */
void print_column(Column *column);

/**
 * @brief Counts the occurrences of a value in a column
 * @param column: The column to search
 * @param value: The value to count
 * @return The number of occurrences of the value in the column
 */
int count_occurrences(Column *column, void *value);

/**
 * @brief Gets the position of a value in a column
 * @param column: The column to search
 * @param value: The value to find
 * @param size: The size of the value
 * @return The position of the value in the column
 */
int get_position(Column *column, void *value, int size);

/**
 * @brief Counts the number of values in a column that are greater than a given value
 * @param column: The column to search
 * @param value: The value to compare
 * @param size: The size of the value
 * @return The number of values in the column that are greater than the given value
 */
int count_greater_than(Column *column, void *value, int size);

/**
 * @brief Counts the number of values in a column that are less than a given value
 * @param column: The column to search
 * @param value: The value to compare
 * @param size: The size of the value
 * @return The number of values in the column that are less than the given value
 */
int count_less_than(Column *column, void *value, int size);

/**
 * @brief Counts the number of values in a column that are equal to a given value
 * @param column: The column to search
 * @param value: The value to compare
 * @param size: The size of the value
 * @return The number of values in the column that are equal to the given value
 */
int count_equal_to(Column *column, void *value, int size);

#endif //CDATAFRAME_COLUMN_H