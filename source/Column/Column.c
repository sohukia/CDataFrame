//
// Created by sohukia on 3/30/2024.
//

#include "Column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256

Column* create_column(const char *title, const unsigned int max_size, const DataType datatype)
{
	Column *column = malloc(sizeof(Column));
	if (column == NULL) return NULL;
	column->index = (unsigned long long *)malloc(sizeof(unsigned long long));
	column->title = strdup(title);
	column->max_size = max_size;
	column->size = 0;
	column->datatype = datatype;
	column->data = (COLUMN_TYPE **)malloc(sizeof(COLUMN_TYPE *) * max_size);
	if (column->data == NULL) // in case where the memory allocation fails
	{
		free(column->index);
		free(column->title);
		free(column);
		return NULL;
	}
	return column;
}

void add_data(Column *column, COLUMN_TYPE *data)
{
	if (column == NULL || data == NULL) return; // if the column or data is NULL, return
	if (column->size >= column->max_size) return; // prevent overflow
	column->data[column->size] = data; // insert the data into the column
	column->size++; // increment the size of the column
}

void convert_value(const Column *column, const unsigned long long int i, char *buffer)
{
	if (column == NULL || buffer == NULL) return;
	if (i >= column->size) return;
	switch (column->data[i]->datatype)
	{
		case UINT:
			sprintf(buffer, "%u", column->data[i]->value.uint_value);
		break;
		case INT:
			sprintf(buffer, "%d", column->data[i]->value.int_value);
		break;
		case CHAR:
			sprintf(buffer, "%c", column->data[i]->value.char_value);
		break;
		case FLOAT:
			sprintf(buffer, "%f", column->data[i]->value.float_value);
		break;
		case DOUBLE:
			sprintf(buffer, "%f", column->data[i]->value.double_value);
		break;
		case STRING:
			sprintf(buffer, "%s", column->data[i]->value.string_value);
		break;
		case STRUCT:
			sprintf(buffer, "%p", column->data[i]->value.struct_value);
		break;
		default:
			break;
	}
}

void free_column(Column *column)
{
	if (column == NULL) return;
	if (column->index != NULL) free(column->index);
	if (column->title != NULL) free(column->title);
	if (column->data != NULL)
	{
		for (unsigned int i = 0; i < column->size; i++)
		{
			if (column->data[i] != NULL)
			{
				if (column->data[i]->datatype == STRING)
				{
					if (column->data[i]->value.string_value != NULL) free(column->data[i]->value.string_value);
				}
				free(column->data[i]);
			}
		}
		free(column->data);
	}
	free(column);
}

void print_column(const Column *column)
{
	if (column == NULL) return;
	for (unsigned int i = 0; i < column->size; i++)
	{
		char buffer[256];
		convert_value(column, i, buffer);
		printf("%s\n", buffer);
	}
}
