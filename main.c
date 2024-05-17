#include <stdio.h>
#include <string.h>

#include "source/CDataFrame/CDataFrame.h"
#include "source/Column/Column.h"

int main() {
	DataFrame df = create_empty_dataframe();
	Column *column1 = create_column("Column 1", 10, INT);

	return 0;
}
