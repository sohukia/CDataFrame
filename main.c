#include <stdio.h>
#include "source/Column/Column.h"

int main() {
	Column *column = create_column(UINT, "test");
	unsigned int value = 5;
	insert_value(column, &value);
	value = 3;
	insert_value(column, &value);
	value = 7;
	insert_value(column, &value);

	char output[5];

	convert_value(column, 0, output, 5);
	printf("%s\n", output);

	print_column(column);

	delete_column(&column);
	return 0;
}
