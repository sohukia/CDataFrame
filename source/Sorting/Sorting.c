//
// Created by sohukia on 3/30/2024.
//

#include "Sorting.h"
#include <string.h>
#include <stdio.h>

void swap(COLUMN_TYPE **a, COLUMN_TYPE **b)
{
	COLUMN_TYPE *temp = *a;
	*a = *b;
	*b = temp;
}

int partition(void* array, int low, int high)
{
	COLUMN_TYPE **arr = (COLUMN_TYPE **)array;
	COLUMN_TYPE *pivot = arr[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		switch (arr[j]->datatype)
		{
			case UINT:
				if (arr[j]->value.uint_value < pivot->value.uint_value)
				{
					i++;
					swap(&arr[i], &arr[j]);
				}
				break;
			case INT:
				if (arr[j]->value.int_value < pivot->value.int_value)
				{
					i++;
					swap(&arr[i], &arr[j]);
				}
				break;
			case CHAR:
				if (arr[j]->value.char_value < pivot->value.char_value)
				{
					i++;
					swap(&arr[i], &arr[j]);
				}
				break;
			case FLOAT:
				if (arr[j]->value.float_value < pivot->value.float_value)
				{
					i++;
					swap(&arr[i], &arr[j]);
				}
				break;
			case DOUBLE:
				if (arr[j]->value.double_value < pivot->value.double_value)
				{
					i++;
					swap(&arr[i], &arr[j]);
				}
				break;
			case STRING:
				if (strcmp(arr[j]->value.string_value, pivot->value.string_value) < 0)
				{
					i++;
					swap(&arr[i], &arr[j]);
				}
				break;
			default:
				printf("Error: unknown type\n");
				return -1;
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quicksort(void* array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}