//
// Created by denni on 16/05/2024.
//

#include "menu.h"
#include <stdio.h>
#include "../Column/Column.h"

void menu_filling(DataFrame *df) {
    int option = 0;
    printf("Select an option between 1 and 3: \n");
    printf("\t1. Create an empty Dataframe\n");
    printf("\t2. Hard file a Dataframe\n");
    printf("\t3. Go back\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            //TODO: Create an empty Dataframe
            menu_filling(df);
            break;
        case 2:
            //TODO: Hard file a Dataframe
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
    printf("Select an option between 1 and 4: \n");
    printf("\t1. Display your whole Dataframe\n");
    printf("\t2. Display a part of the Dataframe rows\n");
    printf("\t3. Display a part of the Dataframe columns\n");
    printf("\t4. Go back\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            //TODO: Display your whole Dataframe
            menu_displaying(df);
            break;
        case 2:
            //TODO: Display a part of the Dataframe rows
            menu_displaying(df);
            break;
        case 3:
            //TODO: Display a part of the Dataframe columns
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
    //TODO : insert column in daataframe
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