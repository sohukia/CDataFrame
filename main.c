#include <string.h>
#include <stdlib.h>

#include "source/CDataFrame/CDataFrame.h"
#include "source/Column/Column.h"
#include "source/types.h"
#include "source/Sorting/Sorting.h"


int main() {

    // Create DataFrame
    DataFrame df = create_empty_dataframe();

    Column* column1 = create_column("Column 1", 10, INT, 0);
    Column* column2 = create_column("Column 2", 10, FLOAT, 1);
    Column* column3 = create_column("Column 3", 10, STRING, 2);

    ///* Exemple of use : (juste enleve ce commentaire et tu verras)
    // Insert columns into DataFrame
    insert_column(&df, column1);
    insert_column(&df, column2);
    insert_column(&df, column3);

    // Add data to columns
    COLUMN_TYPE data_int = {INT, {.int_value = 42}};
    COLUMN_TYPE data_float = {FLOAT, {.float_value = 3.14}};
    COLUMN_TYPE data_string = {STRING, {.string_value = strdup("Hello, World!")}};

    add_data(column1, &data_int);
    add_data(column1, &data_int);
    add_data(column2, &data_float);
    add_data(column3, &data_string);

    Column *column15 = create_column("Column 1.5", 10, INT, 1);
    data_int.value.int_value = 23;
    add_data(column15, &data_int);
    data_int.value.int_value = 32;
    add_data(column15, &data_int);
    data_int.value.int_value = 90;
    add_data(column15, &data_int);

    insert_column_at_index(&df, column15, 1);

    // Print DataFrame
    print_dataframe(&df);

    // Cleanup
    delete_dataframe(&df);
    //*/
    return 0;
}