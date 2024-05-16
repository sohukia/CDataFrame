//
// Created by denni on 16/05/2024.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "../CDataFrame/CDataFrame.h"
#include "../Column/Column.h"


void menu_filling(){
    int option = 0;
    printf("select an option between 1 and 3: \n");
    printf("\t1. Create an empty Dataframe\n");
    printf("\t2. Hard file a Dataframe\n");
    scanf("%d", &option);
    switch (option){
        case 1:
            //TODO: Create an empty Dataframe
            break;
        case 2:
            //TODO: Hard file a Dataframe
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void menu_displaying(){
    int option = 0;
    printf("Select an option between 1 and 4: \n");
    printf("\t1. Display your whole Dataframe\n");
    printf("\t2. Display a part of the Dataframe rows\n");
    printf("\t3. Display a part of the Dataframe columns\n");
    printf("\t4. Go back\n");
    scanf("%d", &option);
    switch (option){
        case 1:
            //TODO: Display your whole Dataframe
            break;
        case 2:
            //TODO: Display a part of the Dataframe rows
            break;
        case 3:
            //TODO: Display a part of the Dataframe columns
            break;
        default:
            printf("Invalid option\n");
            break;
    }
}

void menu_create_column() {
    char title[256];
    unsigned int max_size;
    DataType datatype;
    printf("Enter the title of the column: ");
    scanf("%s", title);
    printf("Enter the maximum size of the column: ");
    scanf("%u", &max_size);
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

void menu_usual_options() {
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
            break;
        case 2:
            //TODO: Delete a row of values
            break;
        case 3:
            menu_create_column();
            break;
        case 4:
            //TODO: Delete a column of values
            break;
        case 5:
            //TODO: Rename the column
            break;
        case 6:
            //TODO: check the existence of a value
            break;
        case 7:
            //TODO: Access/replace the value in a CDataframe cell using its row and column number
            break;
        case 8:
            //TODO: Display column names
    }
}

