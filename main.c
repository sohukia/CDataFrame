#include <stdio.h>
#include <string.h>

#include "source/Column/Column.h"
#include "source/Searching/Searching.h"
#include "source/List/List.h"
#include "source/Sorting/Sorting.h"

int main() {
	Column *column = create_column("Column 1", 10, UINT);
	COLUMN_TYPE *data = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE));
	data->datatype = UINT;
	data->value.uint_value = 10;
	add_data(column, data);
	data = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE));
	data->datatype = UINT;
	data->value.uint_value = 5;
	add_data(column, data);
	data = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE));
	data->datatype = UINT;
	data->value.uint_value = 7;
	add_data(column, data);
	data = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE));
	data->datatype = UINT;
	data->value.uint_value = 3;
	add_data(column, data);
	data = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE));
	data->datatype = UINT;
	data->value.uint_value = 1;
	add_data(column, data);
	print_column(column);
	insertion_sort(column->data, UINT, 0, column->size - 1);
	print_column(column);
	free_column(column);
	return 0;
}
