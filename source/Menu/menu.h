//
// Created by denni on 16/05/2024.
//

#ifndef CDATAFRAME_MENU_H
#define CDATAFRAME_MENU_H
#include "../CDataFrame/CDataFrame.h"

/**
 * @brief Create a dataframe filled by the user
 * @return the dataframe created
 */
DataFrame menu_create_dataframe();

/**
 * @brief Create a dataframe filled with random data
 * @return the dataframe created
 */
DataFrame menu_create_random_dataframe();

/**
 * @brief Create a dataframe with user's choice set of data
 * @return the dataframe created
 */
DataFrame menu_begin_fill_operation();

/**
 * @brief Add a row to the dataframe
 * @param df: the dataframe to add the row to
 */
void menu_add_row(const DataFrame *df);

/**
 * @brief Usual operations of a dataframe such as adding, deleting, and renaming a column or a row
 * searching for a value, display the column names
 * @param df: the dataframe to use
 */
void menu_usual_operations(DataFrame *df);

/**
 * @brief Main menu of the program
 */
void menu_main();

#endif //CDATAFRAME_MENU_H
