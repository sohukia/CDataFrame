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
int count_occurrences(const Column *column, void *value);

/**
 * @brief Gets the position of a value in a column
 * @param column: The column to search
 * @param value: The value to find
 * @return The position of the value in the column
 */
int get_position(const Column *column, void *value);

/**
 * @brief Counts the number of values in a column that are greater than a given value
 * @param column: The column to search
 * @param value: The value to compare
 * @param size: The size of the value
 * @return The number of values in the column that are greater than the given value
 */
int count_greater_than(const Column *column, void *value, int size);

/**
 * @brief Counts the number of values in a column that are less than a given value
 * @param column: The column to search
 * @param value: The value to compare
 * @param size: The size of the value
 * @return The number of values in the column that are less than the given value
 */
int count_less_than(const Column *column, void *value, int size);

/**
 * @brief Counts the number of values in a column that are equal to a given value
 * @param column: The column to search
 * @param value: The value to compare
 * @param size: The size of the value
 * @return The number of values in the column that are equal to the given value
 */
int count_equal_to(const Column *column, void *value, int size);

/**
 * @brief search for a column by name and return its associated node
 * @param df the dataframe to search
 * @param title the name of the column to search for
 * @return the node associated with the column
 */
Node *search_by_name(const DataFrame *df, const char *title);

/**
 * @brief get the size of the dataframe
 * @param df the dataframe to get the size of
 * @return the size of the dataframe
 */
int get_dataframe_size(const DataFrame *df);

/**
 * @brief get the maximum number of rows in the dataframe
 * @param df the dataframe to get the maximum number of rows of
 * @return the maximum number of rows in the dataframe
 */
int get_dataframe_max_rows(const DataFrame *df);

/**
 * @brief get the column at the specified index
 * @param df the dataframe to get the column from
 * @param index the index of the column to get
 * @return the column at the specified index
 */
Column *get_column(const DataFrame *df, int index);

#endif //CDATAFRAME_SEARCHING_H
