#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "source/CDataFrame/CDataFrame.h"
#include "source/Column/Column.h"

int main() {
	DataFrame df = create_empty_dataframe();
	Column *column1 = create_column("A", 10, INT);
	Column *column2 = create_column("B", 10, INT);
	insert_column(&df, column1);
	insert_column(&df, column2);
	const int data1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	const int data2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	for (int i = 0; i < 10; i++) {
		COLUMN_TYPE *data = malloc(sizeof(COLUMN_TYPE));
		data->datatype = INT;
		data->value.int_value = data1[i];
		add_data(column1, data);
		data = malloc(sizeof(COLUMN_TYPE));
		data->datatype = INT;
		data->value.int_value = data2[i];
		add_data(column2, data);
	}
	print_dataframe(&df);
	add_dataframe_row(&df, (COLUMN_TYPE *[]) {column1->data[0], column2->data[0]});


	delete_dataframe(&df);
	return 0;
}
