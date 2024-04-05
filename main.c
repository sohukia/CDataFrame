#include "source/Column/Column.h"

int main() {
	Column *column = create_column(FLOAT, "test");
	float value = 5.4f;
	insert_value(column, &value);
	value = 3.345f;
	insert_value(column, &value);
	value = 7.237f;
	insert_value(column, &value);
	value = 1.002f;
	insert_value(column, &value);

	print_column(column);

	delete_column(&column);
	return 0;
}
