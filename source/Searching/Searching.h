//
// Created by sohukia on 4/5/2024.
//

#ifndef CDATAFRAME_SEARCHING_H
#define CDATAFRAME_SEARCHING_H
#include "../types.h"

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
int get_position(Column *column, void *value);

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

/**
 * @brief search for a column by name and return its associated node
 * @param df the dataframe to search
 * @param name the name of the column to search for
 * @return the node associated with the column
 */
Node *search_by_name(DataFrame *df, const char *name);

#endif //CDATAFRAME_SEARCHING_H
