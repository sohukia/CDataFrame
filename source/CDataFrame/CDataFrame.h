//
// Created by sohukia on 3/30/2024.
//

#ifndef CDATAFRAME_CDATAFRAME_H
#define CDATAFRAME_CDATAFRAME_H
#include "../types.h"

/**
 * @brief A data frame
 * @param types: the types of the columns in the data frame
 * @param size: The number of columns in the data frame
 * @return A data frame
 */
DATAFRAME *create_dataframe(const ENUM_TYPE *types, int size);

/**
 * @brief Prints a data frame
 * @param dataframe: the data frame to print
 */
void print_dataframe(const DATAFRAME *dataframe);

/**
 * @brief Deletes a data frame
 * @param dataframe: the data frame to delete
 */
void delete_dataframe(DATAFRAME **dataframe);
#endif //CDATAFRAME_CDATAFRAME_H
