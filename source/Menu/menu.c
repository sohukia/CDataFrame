//
// Created by denni on 16/05/2024.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../CDataFrame/CDataFrame.h"
#include "../Column/Column.h"
#include "../Searching/Searching.h"

DataFrame menu_create_dataframe() {
    int n_columns;
    do {
        printf("Enter the number of columns: ");
        scanf("%d", &n_columns);
    } while (n_columns < 1);
    ENUM_TYPE *types = malloc(n_columns * sizeof(ENUM_TYPE));
    char **titles = malloc(n_columns * sizeof(char *));
    for (int i = 0; i < n_columns; i++) {
        do {
            printf("Allowed types : (UINT = 1, INT = 2, CHAR = 3, FLOAT = 4, DOUBLE = 5, STRING = 6)\n");
            printf("Enter the type of column %d (use the number associated to the type you want): ", i + 1);
            scanf("%d", &types[i]);
        } while (types[i] < 1 || types[i] > 6);
        printf("Enter the title of column %d: ", i + 1);
        char title[256];
        scanf("%s", title);
        titles[i] = strdup(title);
    }
    const DataFrame df = create_dataframe(types, titles, n_columns);
    free(types);
    for (int i = 0; i < n_columns; i++) {
        free(titles[i]);
    }
    free(titles);
    return df;
}

DataFrame menu_create_random_dataframe() {
    srand(time(0));
    int n_columns;
    do {
        printf("Enter the number of columns: ");
        scanf("%d", &n_columns);
    } while (n_columns < 1);
    ENUM_TYPE *types = malloc(n_columns * sizeof(ENUM_TYPE));
    char **titles = malloc(n_columns * sizeof(char *));
    for (int i = 0; i < n_columns; i++) {
        types[i] = rand() % 6 + 1;
        char title[256];
        sprintf(title, "Column %d", i + 1);
        titles[i] = strdup(title);
    }
    const DataFrame df = create_dataframe(types, titles, n_columns);
    free(types);
    for (int i = 0; i < n_columns; i++) {
        free(titles[i]);
    }
    free(titles);
    fill_dataframe_with_random_numbers(&df);
    return df;
}

DataFrame menu_begin_fill_operation() {
    int choice;
    do {
        printf("1. Create an empty DataFrame\n");
        printf("2. Create a DataFrame given data\n");
        printf("3. Create a DataFrame with pre-defined (and randomly generated) data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                return create_empty_dataframe();
            case 2:
                return menu_create_dataframe();
            case 3:
                return menu_create_random_dataframe();
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return create_empty_dataframe();
}

void menu_add_row(const DataFrame *df) {
    printf("Please enter the value you want to insert in the dataframe\n");
    COLUMN_TYPE *data = malloc(get_dataframe_size(df) * sizeof(COLUMN_TYPE));
    for (int i = 0; i < get_dataframe_size(df); i++) {
        switch (get_column_type(df, i)) {
            case UINT:
                printf("Enter an unsigned integer: ");
                scanf("%u", &(data[i].value.uint_value));
                break;
            case INT:
                printf("Enter an integer: ");
                scanf("%d", &(data[i].value.int_value));
                break;
            case CHAR:
                printf("Enter a character: ");
                scanf(" %c", &(data[i].value.char_value));
                break;
            case FLOAT:
                printf("Enter a float: ");
                scanf("%f", &(data[i].value.float_value));
                break;
            case DOUBLE:
                printf("Enter a double: ");
                scanf("%lf", &(data[i].value.double_value));
                break;
            case STRING:
                printf("Enter a string: ");
                char string[256];
                scanf("%s", string);
                data[i].value.string_value = strdup(string);
                break;
            case NULLVAL:
                break;
            default:
                break;
        }
    }
    add_dataframe_row(df, data);
    for (int i = 0; i < get_dataframe_size(df); i++) {
        if (get_column_type(df, i) == STRING) free(data[i].value.string_value);
    }
    free(data);
}

void menu_usual_operations(DataFrame *df) {
    int choice;
    do {
        printf("1. Add row of values to the DataFrame\n");
        printf("2. Delete row of values from the DataFrame\n");
        printf("3. Add a column to the dataframe");
        printf("4. Delete a column from the dataframe");
        printf("5. Rename a column");
        printf("6. Search for a value in the dataframe");
        printf("7. Display the column names");
        printf("8. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);

}


void menu_main() {
    DataFrame df = create_empty_dataframe();
    int choice;
    do {
        printf("1. Filling operations\n");
        printf("2. Displaying operations\n");
        printf("3. Usual operations\n");
        printf("4. Analysis and statistics operations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //menu_filling(&df);
                break;
            case 2:
                //menu_displaying(&df);
                break;
            case 3:

                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    delete_dataframe(&df);
}