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

int partition(void *array, DataType type, int low, int high)
{
	COLUMN_TYPE **arr = (COLUMN_TYPE **)array;
	for(int i = low; i <= high; arr[i++]->datatype = type);
	COLUMN_TYPE *pivot = arr[high];

	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		switch (type)
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
	return (int)(i + 1);
}

// non recursive quicksort
void quicksort(void *array, DataType type, int low, int high)
{
    // Create an auxiliary stack
    int stack[high - low + 1];

    // Initialize top of stack
    int top = -1;

    // Push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from stack while it is not empty
    while (top >= 0)
    {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position in sorted array
        int pi = partition(array, type, low, high);

        // If there are elements on left side of pivot, then push left side to stack
        if (pi - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        // If there are elements on right side of pivot, then push right side to stack
        if (pi + 1 < high)
        {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}
