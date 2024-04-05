#include <stdio.h>
#include "source/Column/Column.h"
#include "source/Sorting/Sorting.h"

int main() {
	Column *column = create_column(UINT, "test");
	unsigned int value = 5;
	insert_value(column, &value);
	value = 3;
	insert_value(column, &value);
	value = 7;
	insert_value(column, &value);
	value = 1;
	insert_value(column, &value);

	print_column(column);

	quicksort(column->data, column->datatype, 0, column->size - 1);

	print_column(column);

	delete_column(&column);
	return 0;
}
