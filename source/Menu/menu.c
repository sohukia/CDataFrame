//
// Created by denni on 16/05/2024.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "../CDataFrame/CDataFrame.h"
#include "../Column/Column.h"
#include "../Searching/Searching.h"

void menu_filling(DataFrame *df) {
    int option = 0;
    printf("Select an option between 1 and 3: \n\t1. Create an empty Dataframe\n\t2. Hard file a Dataframe\n\t3. Go back\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            *df = create_empty_dataframe();
            menu_filling(df);
            break;
        case 2:
            fill_dataframe_with_random_numbers(df);
            printf("You just fill your Dataframe with random numbers.\n");
            menu_filling(df);
            break;
        case 3:
            menu(df);
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void menu_displaying(DataFrame *df) {
    int option = 0;
    printf("Select an option between 1 and 4: \n\t1. Display your whole Dataframe\n\t2. Display a part of the Dataframe rows\n\t3. Display a part of the Dataframe columns\n\t4. Go back\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            //TODO: Display your whole Dataframe
            break;
        case 2:
            int start_row, end_row;
            printf("Enter the start row index: ");
            scanf("%d", &start_row);
            printf("Enter the end row index: ");
            scanf("%d", &end_row);
            display_part_of_dataframe_rows(df, start_row, end_row);
            menu_displaying(df);
            break;
        case 3:
            int start_col, end_col;
            printf("Enter the start column index: ");
            scanf("%d", &start_col);
            printf("Enter the end column index: ");
            scanf("%d", &end_col);
            display_part_of_dataframe_columns(df, start_col, end_col);
            menu_displaying(df);
            break;
        case 4:
            menu(df);
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void menu_create_column(DataFrame *df) {
    char title[256];
    unsigned int max_size;
    DataType datatype;
    printf("Enter the title of the column: ");
    scanf("%s\n", title);
    printf("Enter the maximum size of the column: ");
    scanf("%u\n", &max_size);
    printf("Enter the datatype of the column (1=UINT, 2=INT, 3=CHAR, 4=FLOAT, 5=DOUBLE, 6=STRING): ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            datatype = UINT;
            break;
        case 2:
            datatype = INT;
            break;
        case 3:
            datatype = CHAR;
            break;
        case 4:
            datatype = FLOAT;
            break;
        case 5:
            datatype = DOUBLE;
            break;
        case 6:
            datatype = STRING;
            break;
        default:
            printf("Invalid choice\n");
            return;

    }
    Column *column = create_column(title, max_size, datatype);
    insert_column(df, column);
}

void menu_usual_options(DataFrame *df) {
    int option = 0;
    printf("Select an option between 1 and 9: \n");
    printf("\t1. Add a row of values\n");
    printf("\t2. Delete a row of values\n");
    printf("\t3. Add a column of values\n");
    printf("\t4. Delete a column of values\n");
    printf("\t5. Rename the column\n");
    printf("\t6. check the existence of a value\n");
    printf("\t7. Access/replace the value in a CDataframe cell using its row and column number\n");
    printf("\t8. Display column names\n");
    printf("\t9. Go back\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            //TODO: Add a row of values
            menu_usual_options(df);
            break;
        case 2:
            //TODO: Delete a row of values
            menu_usual_options(df);
            break;
        case 3:
            menu_create_column(df);
            menu_usual_options(df);
            break;
        case 4:
            //TODO: Delete a column of values
            menu_usual_options(df);
            break;
        case 5:
            //TODO: Rename the column
            menu_usual_options(df);
            break;
        case 6:
            //TODO: check the existence of a value
            menu_usual_options(df);
            break;
        case 7:
            //TODO: Access/replace the value in a CDataframe cell using its row and column number
            menu_usual_options(df);
            break;
        case 8:
            //TODO: Display column names
            menu_usual_options(df);
            break;
        case 9:
            menu(df);
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void menu_statistics(DataFrame *df) {
    int option = 0;
    printf("Select an option between 1 and 6: \n");
    printf("\t1. Display the number of rows\n");
    printf("\t2. Display the number of column\n");
    printf("\t3. Display the number of cells equal to x\n");
    printf("\t4. Display the number of cells containing a value greater than x\n");
    printf("\t5. Display the number of cells containing a value less than x\n");
    printf("\t6. Go Back\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            //TODO: Display the number of rows
            menu_statistics(df);
            break;
        case 2:
            //TODO: Display the number of column
            menu_statistics(df);
            break;
        case 3:
            //TODO: Display the number of cells equal to x
            menu_statistics(df);
            break;
        case 4:
            //TODO: Display the number of cells containing a value greater than x
            menu_statistics(df);
            break;
        case 5:
            //TODO: Display the number of cells containing a value less than x
            menu_statistics(df);
            break;
        case 6:
            menu(df);
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void menu(DataFrame *df){
    int option = 0;
    printf("Welcome to the CDataframe program\n");
    printf("Select an option between 1 and 4: \n");
    printf("\t1. Filling the Dataframe\n");
    printf("\t2. Displaying the Dataframe\n");
    printf("\t3. Usual operation\n");
    printf("\t4. Statistics\n");
    printf("\t5. Exit\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            menu_filling(df);
            break;
        case 2:
            menu_displaying(df);
            break;
        case 3:
            menu_usual_options(df);
            break;
        case 4:
            menu_statistics(df);
            break;
        case 5:
            printf("Goodbye.\n");
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void create_row_from_input(DataFrame *df) {
    int num_columns = get_dataframe_size(df);
    void **values = (void **)malloc(sizeof(void *) * num_columns);
    for (int i = 0; i < num_columns; i++) {
        Column *column = get_column(df, i);
        switch (column->datatype) {
            case UINT:
                values[i] = (void *)malloc(sizeof(unsigned int));
                printf("Enter a value for column %s: ", column->title);
                scanf("%u", (unsigned int *)values[i]);
                break;
            case INT:
                values[i] = (void *)malloc(sizeof(int));
                printf("Enter a value for column %s: ", column->title);
                scanf("%d", (int *)values[i]);
                break;
            case CHAR:
                values[i] = (void *)malloc(sizeof(char));
                printf("Enter a value for column %s: ", column->title);
                scanf("%c", (char *)values[i]);
                break;
            case FLOAT:
                values[i] = (void *)malloc(sizeof(float));
                printf("Enter a value for column %s: ", column->title);
                scanf("%f", (float *)values[i]);
                break;
            case DOUBLE:
                values[i] = (void *)malloc(sizeof(double));
                printf("Enter a value for column %s: ", column->title);
                scanf("%lf", (double *)values[i]);
                break;
            case STRING:
                values[i] = (void *)malloc(sizeof(char) * column->max_size);
                printf("Enter a value for column %s: ", column->title);
                scanf("%s", (char *)values[i]);
                break;
            default:
                printf("Invalid datatype\n");
                return;
        }
    }
}