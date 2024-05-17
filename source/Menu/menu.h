//
// Created by denni on 16/05/2024.
//

#ifndef CDATAFRAME_MENU_H
#define CDATAFRAME_MENU_H
#include "../CDataFrame/CDataFrame.h"

/**
 * @brief Fills the Dataframe
 */
void menu_filling(DataFrame *df);

/**
 * @brief Displays the Dataframe
 */
void menu_displaying(DataFrame *df);

/**
 * @brief Creates a column
 */
void menu_create_column(DataFrame *df);

/**
 * @brief Usual options
 */
void menu_usual_options(DataFrame *df);

/**
 * @brief Usual statistics
 */
void menu_usual_statistics(DataFrame *df);

/**
 * @brief Menu
 */
void menu(DataFrame *df);

#endif //CDATAFRAME_MENU_H
