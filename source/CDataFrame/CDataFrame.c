//
// Created by sohukia on 3/30/2024.
//

#include "CDataFrame.h"
#include "../Column/Column.h"
#include "../List/List.h"
#include "../Searching/Searching.h"

DataFrame create_dataframe(const ENUM_TYPE *types, char **titles, const unsigned int n) {
    DataFrame df;
    df.columns = create_list();
    for (unsigned int i = 0; i < n; i++) {
        Column* column = create_column(titles[i], 10, types[i]);
        insert_in_list(&df.columns, column);
    }
    return df;
}

void insert_column(DataFrame *df, Column *column) {
    insert_in_list(&df->columns, column);
}

void delete_column(DataFrame *df, char title[]) {
    delete_node(&df->columns, search_by_name(df, title));
}

void delete_dataframe(DataFrame *df) {
    free_list(&df->columns);
}

void print_dataframe(const DataFrame *df) {
    print_list(&df->columns);
}
