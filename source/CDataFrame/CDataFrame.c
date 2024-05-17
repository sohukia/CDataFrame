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

DataFrame create_empty_dataframe() {
    DataFrame df;
    df.columns = create_list();
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
    const int size = get_dataframe_max_rows(df);
    const int num_columns = get_dataframe_size(df);
    char ***buffers = (char ***)malloc(sizeof(char **) * num_columns);
    int *max_lengths = (int *)malloc(sizeof(int) * num_columns);
    for (int j = 0; j < num_columns; j++) {
        buffers[j] = (char **)malloc(sizeof(char *) * size);
        max_lengths[j] = 0;
        for (int i = 0; i < size; i++) {
            buffers[j][i] = (char *)malloc(sizeof(char) * 256);
        }
    }

    const Node* current = df->columns.head;
    int column_index = 0;
    while (current != NULL) {
        printf("%s\t", current->data->title);
        for (int i = 0; i < size; i++) {
            const int length = convert_value(current->data, i, buffers[column_index][i]);
            if (length > max_lengths[column_index]) {
                max_lengths[column_index] = length;
            }
        }
        current = current->next;
        column_index++;
    }
    printf("\n"); // print a newline after the column titles

    // print the dataframe as a table
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < num_columns; j++) {
            printf("%-*s\t", max_lengths[j], buffers[j][i]); // print the values of each column
        }
        printf("\n"); // print a newline after each row
    }

    // free the memory allocated for the buffers
    for (int j = 0; j < num_columns; j++) {
        for (int i = 0; i < size; i++) {
            free(buffers[j][i]);
        }
        free(buffers[j]);
    }
    free(buffers);
    free(max_lengths);
}

void add_dataframe_row(const DataFrame *df, COLUMN_TYPE **data) {
    const int num_columns = get_dataframe_size(df);
    Column **columns = (Column **)malloc(sizeof(Column *) * num_columns);
    const Node* current = df->columns.head;
    int i = 0;
    while (current != NULL) {
        columns[i] = current->data;
        current = current->next;
        i++;
    }
    for (int j = 0; j < num_columns; j++) {
        add_data(columns[j], data[j]);
    }
    free(columns);
}