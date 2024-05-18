//
// Created by sohukia on 3/30/2024.
//

#include <time.h>
#include <stdlib.h>
#include <string.h>
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
        const int length = strlen(current->data->title);
        if (length > max_lengths[column_index]) {
            max_lengths[column_index] = length;
        }
        for (int i = 0; i < size; i++) {
            const int length = convert_value(current->data, i, buffers[column_index][i]);
            if (length > max_lengths[column_index]) {
                max_lengths[column_index] = length;
            }
        }
        current = current->next;
        column_index++;
    }

    // Reset the current pointer to the head of the list
    current = df->columns.head;

    // Print the table header
    printf("+");
    for (int j = 0; j < num_columns; j++) {
        printf("-");
        for (int i = 0; i < max_lengths[j] + 2; i++) {
            printf("-");
        }
    }
    printf("+\n");

    // Print the column titles
    printf("|");
    for (int j = 0; j < num_columns; j++) {
        printf(" ");
        printf("%-*s", max_lengths[j], current->data->title); // print the column titles

        printf(" ");
        printf("|");
        current = current->next; // Move to the next column title
    }
    printf("\n");

    // Print the table separator
    printf("+");
    for (int j = 0; j < num_columns; j++) {
        printf("-");
        for (int i = 0; i < max_lengths[j] + 2; i++) {
            printf("-");
        }
    }
    printf("+\n");

    // Print the dataframe as a table
    for (int i = 0; i < size; i++) {
        printf("|");
        for (int j = 0; j < num_columns; j++) {
            printf(" ");
            printf("%-*s", max_lengths[j], buffers[j][i]);
            printf(" ");
            printf("|");
        }
        printf("\n");
    }

    // Print the table footer
    printf("+");
    for (int j = 0; j < num_columns; j++) {
        printf("-");
        for (int i = 0; i < max_lengths[j] + 2; i++) {
            printf("-");
        }
    }
    printf("+\n");

    // Free the memory allocated for the buffers
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
        add_data((Column *) columns[j]->data, data[j]);
    }
    free(columns);
}

void fill_dataframe_with_random_numbers(DataFrame *df) {
    srand(time(0)); // Use current time as seed for random generator

    Node* current = df->columns.head;
    while (current != NULL) {
        Column* column = current->data;
        for (int i = 0; i < column->max_size; i++) {
            COLUMN_TYPE* value = (COLUMN_TYPE*)malloc(sizeof(COLUMN_TYPE));
            value->datatype = column->datatype;
            switch (column->datatype) {
                case UINT:
                    value->value.uint_value = rand();
                    break;
                case INT:
                    value->value.int_value = rand();
                    break;
                case CHAR:
                    value->value.char_value = 'A' + (rand() % 26); // Generate a random uppercase letter
                    break;
                case FLOAT:
                    value->value.float_value = (float)rand() / (float)(RAND_MAX);
                    break;
                case DOUBLE:
                    value->value.double_value = (double)rand() / (double)(RAND_MAX);
                    break;
                case STRING:
                    // For simplicity, let's fill the string with a single random character
                    value->value.string_value = (char*)malloc(2 * sizeof(char));
                    value->value.string_value[0] = 'A' + (rand() % 26);
                    value->value.string_value[1] = '\0';
                    break;
                default:
                    break;
            }
            column->data[i] = value;
        }
        current = current->next;
    }
}

void display_whole_dataframe(DataFrame *df) {
    const int num_columns = get_dataframe_size(df);
    const int size = df->columns.head->data->max_size;

    // allocate memory for buffers to hold the string representation of each value
    char ***buffers = (char ***)malloc(sizeof(char **) * num_columns);
    for (int j = 0; j < num_columns; j++) {
        buffers[j] = (char **)malloc(sizeof(char *) * size);
        for (int i = 0; i < size; i++) {
            buffers[j][i] = (char *)malloc(sizeof(char) * 256);
        }
    }

    // convert each value to a string and store it in the buffers
    const Node* current = df->columns.head;
    int column_index = 0;
    while (current != NULL) {
        printf("%s\t", current->data->title);
        for (int i = 0; i < size; i++) {
            convert_value(current->data, i, buffers[column_index][i]);
        }
        current = current->next;
        column_index++;
    }
    printf("\n"); // print a newline after the column titles

    // print the dataframe as a table
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < num_columns; j++) {
            printf("%s\t", buffers[j][i]); // print the values of each column
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
}

void display_part_of_dataframe_rows(DataFrame *df, int start, int end) {
    const int num_columns = get_dataframe_size(df);

    // allocate memory for buffers to hold the string representation of each value
    char **buffers = (char **)malloc(sizeof(char *) * num_columns);
    for (int j = 0; j < num_columns; j++) {
        buffers[j] = (char *)malloc(sizeof(char) * 256);
    }

    // convert each value to a string and store it in the buffers
    const Node* current = df->columns.head;
    int column_index = 0;
    while (current != NULL) {
        printf("%s\t", current->data->title);
        current = current->next;
        column_index++;
    }
    printf("\n"); // print a newline after the column titles

    // print the dataframe as a table
    for (int i = start; i < end; i++) {
        current = df->columns.head;
        column_index = 0;
        while (current != NULL) {
            convert_value(current->data, i, buffers[column_index]);
            printf("%s\t", buffers[column_index]); // print the values of each column
            current = current->next;
            column_index++;
        }
        printf("\n"); // print a newline after each row
    }

    // free the memory allocated for the buffers
    for (int j = 0; j < num_columns; j++) {
        free(buffers[j]);
    }
    free(buffers);
}

void display_part_of_dataframe_columns(DataFrame *df, int start, int end) {
    const int size = df->columns.head->data->max_size;

    // allocate memory for buffers to hold the string representation of each value
    char **buffers = (char **)malloc(sizeof(char *) * size);
    for (int i = 0; i < size; i++) {
        buffers[i] = (char *)malloc(sizeof(char) * 256);
    }

    // convert each value to a string and store it in the buffers
    const Node* current = df->columns.head;
    int column_index = 0;
    while (current != NULL && column_index < end) {
        if (column_index >= start) {
            printf("%s\t", current->data->title);
            for (int i = 0; i < size; i++) {
                convert_value(current->data, i, buffers[i]);
            }
            for (int i = 0; i < size; i++) {
                printf("%s\t", buffers[i]); // print the values of the column
            }
            printf("\n"); // print a newline after each column
        }
        current = current->next;
        column_index++;
    }

    // free the memory allocated for the buffers
    for (int i = 0; i < size; i++) {
        free(buffers[i]);
    }
    free(buffers);
}