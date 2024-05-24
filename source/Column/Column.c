//
// Created by sohukia on 3/30/2024.
//

#include "Column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Column* create_column(const char *title, const unsigned int max_size, const DataType datatype, const unsigned long long index)
{
	Column *column = malloc(sizeof(Column));
	if (column == NULL) return NULL;
	column->index = index;
	column->title = strdup(title);
	column->max_size = max_size;
	column->size = 0;
	column->datatype = datatype;
	switch (datatype) { // allocate memory if is string else just set the value
		case STRING:
			column->data = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE *) * max_size);
		if (column->data == NULL) // in case where the memory allocation fails
		{
			free(column->title);
			free(column);
			return NULL;
		}
		break;
		default:
			column->data = NULL;
		break;

	}
	column->data = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE *) * max_size);
	if (column->data == NULL) // in case where the memory allocation fails
	{
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
	column->data[column->size] = *data; // insert the data into the column
	column->size++; // increment the size of the column
}

int convert_value(const Column *column, const unsigned long long int i, char *buffer)
{
	if (column == NULL || buffer == NULL) return 0;
	if (i >= column->size) {
		strcpy(buffer, " "); // fill with a blank space if the value doesn't exist
		return 1;
	}
	int length;
	switch (column->data[i].datatype)
	{
		case UINT:
			length = sprintf(buffer, "%u", column->data[i].value.uint_value);
		break;
		case INT:
			length = sprintf(buffer, "%d", column->data[i].value.int_value);
		break;
		case CHAR:
			length = sprintf(buffer, "%c", column->data[i].value.char_value);
		break;
		case FLOAT:
			length = sprintf(buffer, "%f", column->data[i].value.float_value);
		break;
		case DOUBLE:
			length = sprintf(buffer, "%f", column->data[i].value.double_value);
		break;
		case STRING:
			length = sprintf(buffer, "%s", column->data[i].value.string_value);
		break;
		default:
			strcpy(buffer, " ");
		length = 1;
		break;
	}
	return length;
}

void free_column(Column *column) {
	if (column == NULL) return;
	free(column->title); // free the memory for the title
	for (unsigned int i = 0; i < column->size; i++) {
		switch (column->data[i].datatype) {
			case STRING:
				free(column->data[i].value.string_value);
			break;
			default:
				break;
		}
	}
	free(column->data); // free the memory for the data array
	free(column); // free the memory for the column structure
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
