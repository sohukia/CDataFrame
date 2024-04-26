#include "source/Column/Column.h"
#include "source/Searching/Searching.h"
#include <stdio.h>

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
    insert_value(column, &value);

    print_column(column);

    int count = count_occurrences(column, &value);
    printf("Count of %f: %d\n", value, count);

    int position = get_position(column, &value);
    printf("Position of %f: %d\n", value, position);

    float compare = 3.0f;
    int greater = count_greater_than(column, &compare, sizeof(float));
    printf("Greater than %f: %d\n", compare, greater);

    int less = count_less_than(column, &compare, sizeof(float));
    printf("Less than %f: %d\n", compare, less);

    int equal = count_equal_to(column, &compare, sizeof(float));
    printf("Equal to %f: %d\n", compare, equal);

	delete_column(&column);
	return 0;
}
