//
// Created by sohukia on 3/30/2024.
//

#ifndef CDATAFRAME_SORTING_H
#define CDATAFRAME_SORTING_H

#include "../Column/Column.h"

/**
 * @brief Swap two pointers
 * @param : pointer to a pointer
 * @param : pointer to a pointer
 */
void swap(COLUMN_TYPE **a, COLUMN_TYPE **b);

/**
 * @brief Partition the array
 * @param : pointer to the array
 * @param : low index
 * @param : high index
 * @return : partition index
 */
int partition(void* array, int low, int high);

/**
 * @brief Sort the array with quicksort
 * @param : pointer to the array
 * @param : low index
 * @param : high index
 */
void quicksort(void* array, int low, int high);
#endif //CDATAFRAME_SORTING_H
