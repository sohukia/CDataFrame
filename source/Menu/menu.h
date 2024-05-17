//
// Created by denni on 16/05/2024.
//

#ifndef CDATAFRAME_MENU_H
#define CDATAFRAME_MENU_H
#include "../CDataFrame/CDataFrame.h"

/**
 * @brief Fills the Dataframe
 * @param df: the dataframe to fill
 */
void menu_filling(DataFrame *df);

/**
 * @brief Displays the Dataframe
 * @param df: the dataframe to display
 */
void menu_displaying(DataFrame *df);

/**
 * @brief Creates a column
 * @param df: the dataframe to create the column in
 */
void menu_create_column(DataFrame *df);

/**
 * @brief Usual options
 * @param df: the dataframe to use
 */
void menu_usual_options(DataFrame *df);

/**
 * @brief Usual statistics
 * @param df: the dataframe to use
 */
void menu_usual_statistics(DataFrame *df);

/**
 * @brief Menu
 * @param df: the dataframe to use
 */
void menu(DataFrame *df);

#endif //CDATAFRAME_MENU_H
