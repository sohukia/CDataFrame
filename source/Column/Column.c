//
// Created by sohukia on 3/30/2024.
//

#include "Column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256

Column *create_column(DataType type, char *title)
{
	Column *to_create = (Column *)malloc(sizeof(Column));
	if (to_create == NULL) return NULL;

	to_create->index = NULL;

	to_create->title = strdup(title);
	if (to_create->title == NULL) // failed to create a column
	{
		free(to_create);
		return NULL;
	}
	to_create->max_size = REALLOC_SIZE;
	to_create->size = 0;
	to_create->datatype = type;
	to_create->data = NULL;

	return to_create;
}

int insert_value(Column *column, void *value)
{
	// check if we can insert
	if (column->size >= column->max_size) return 0;

	// allocate memory
	COLUMN_TYPE *new_value = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE));
	if (new_value == NULL) return 0; // failed to allocate memory


	switch (column->datatype)
	{
		case UINT:
			new_value->value.uint_value = *(unsigned int *)value;
			break;
		case INT:
			new_value->value.int_value = *(int *)value;
			break;
		case CHAR:
			new_value->value.char_value = *(char *)value;
			break;
		case FLOAT:
			new_value->value.float_value = *(float *)value;
			break;
		case DOUBLE:
			new_value->value.double_value = *(double *)value;
			break;
		case STRING:
			new_value->value.string_value = strdup((char *)value);
			if (new_value->value.string_value == NULL) // failed to allocate string memory
			{
				free(new_value);
				return 0;
			}
			break;
		case STRUCT:
			new_value->value.struct_value = value;
			break;
		default: // failed to allocate memory for new value
			free(new_value);
			break;
	}

	column->data[column->size] = new_value;
	column->size++;

	return 1;

}

void convert_value (Column *column, unsigned long long int i, char *str, int size)
{
	switch(column->datatype)
	{
		case UINT:
			snprintf(str, size, "%u\n", ((unsigned int *) column->data)[i]);
			break;
		case INT:
			snprintf(str, size, "%d\n", ((int*)column->data)[i]);
			break;
		case CHAR:
			snprintf(str, size, "%c\n", ((char*)column->data)[i]);
			break;
		case FLOAT:
			snprintf(str, size, "%f\n", ((float*)column->data)[i]);
			break;
		case DOUBLE:
			snprintf(str, size, "%lf\n", ((double*)column->data)[i]);
			break;
		case STRING:
			snprintf(str, size, "%s\n", ((char**)column->data)[i]);
			break;
		default:
			printf("Error: unknown type\n");
			return;
	}
}

void delete_column(Column **column)
{
	// column is already NULL
	if (*column == NULL) return;

	// free the title
	if ((*column)->title != NULL) free((*column)->title);

	// free the index
	if ((*column)->index != NULL) free((*column)->index);

	// free the data
	if ((*column)->data != NULL)
	{
		for (unsigned int i = 0; i < (*column)->size; i++)
		{
			if ((*column)->data[i] != NULL)
			{
				switch ((*column)->datatype)
				{
					case STRING:
						free((*column)->data[i]->value.string_value);
						break;
					default:
						break;
				}
				free((*column)->data[i]);
			}
		}
		free((*column)->data);
	}

	// free the column
	free(*column);
	*column = NULL;
}
