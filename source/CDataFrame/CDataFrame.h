//
// Created by sohukia on 3/30/2024.
//

#ifndef CDATAFRAME_CDATAFRAME_H
#define CDATAFRAME_CDATAFRAME_H
#include "../types.h"

/**
 * @brief Creates a new dataframe with the given types and titles. The columns will be empty.
 * @param types: the types of the columns
 * @param titles: the titles of the columns
 * @param n: the number of columns
 * @return a new dataframe
 */
DataFrame create_dataframe(const ENUM_TYPE *types, char **titles, unsigned int n);

/**
 * @brief Creates an empty dataframe
 * @return a new empty dataframe
 */
DataFrame create_empty_dataframe();

/**
 * @brief Updates the indexes of the columns in a dataframe
 * @param df: the dataframe to update
 */
void update_column_indexes(const DataFrame *df);

/**
 * @brief Inserts a column into a dataframe
 * @param df: the dataframe in which to insert the column
 * @param column: the column to insert
 */
void insert_column(DataFrame *df, Column *column);

/**
 * @brief inserts a column into a dataframe at a specific index
 * @param df: the dataframe in which to insert the column
 * @param column: the column to insert
 * @param index: the index at which to insert the column
 */
void insert_column_at_index(DataFrame *df, Column *column, unsigned int index);

/**
 * @brief Deletes a column from a dataframe
 * @param df: the dataframe from which to delete the column
 * @param title: the column title to delete
 */
void delete_column(DataFrame *df, char title[]);

/**
 * @brief Deletes a row from a dataframe
 * @param df: the dataframe from which to delete the row
 * @param index: the index of the row to delete
 */
void delete_row(DataFrame *df, unsigned int index);

/**
 * @brief Deletes a dataframe and frees all associated memory
 * @param df: the dataframe to delete
 */
void delete_dataframe(DataFrame *df);

/**
 * @brief Prints the contents of a dataframe
 * @param df: the dataframe to print
 */
void print_dataframe(const DataFrame *df);

/**
 * @brief Adds a row to a dataframe
 * @param df: the dataframe to add the row to
 * @param data: the data to add
 */
void add_dataframe_row(const DataFrame *df, COLUMN_TYPE *data);

/**
 * @brief Gets the number of rows in a dataframe
 * @param df: the dataframe to get the number of rows from
 * @return the number of rows in the dataframe
 */
void fill_dataframe_with_random_numbers(const DataFrame *df);

/**
 * @brief Gets the number of rows in a dataframe
 * @param df: the dataframe to get the number of rows from
 * @param start: the start index
 * @param end: the end index
 * @return the number of rows in the dataframe
 */
void display_part_of_dataframe_rows(const DataFrame *df, int start, int end);

/**
 * @brief Gets the number of rows in a dataframe
 * @param df: the dataframe to get the number of rows from
 * @param start: the start index
 * @param end: the end index
 * @return the number of rows in the dataframe
 */
void display_part_of_dataframe_columns(const DataFrame *df, int start, int end);

#endif //CDATAFRAME_CDATAFRAME_H
