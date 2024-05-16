//
// Created by denni on 16/05/2024.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "../CDataFrame/CDataFrame.h"


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
    printf("Select an option between 1 and 3: \n");
    printf("\t1. Display your whole Dataframe\n");
    printf("\t2. Display a part of the Dataframe rows\n");
    printf("\t3. Display a part of the Dataframe columns\n");
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