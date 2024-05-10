//
// Created by sohukia on 3/30/2024.
//

#include "CDataFrame.h"
#include "../Column/Column.h"
#include <stdlib.h>
#include <stdio.h>

#include "../List/List.h"

DATAFRAME *create_dataframe(const ENUM_TYPE *types, const int size) {
    DATAFRAME *dataframe = (DATAFRAME*) malloc(sizeof(DATAFRAME));
    if(dataframe == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    dataframe->head = NULL;
    dataframe->tail = NULL;
    for (int i = 0; i < size; i++) {
        Column *column = create_column(types[i], "column");
        insert_list_node(dataframe, column);
    }
    return dataframe;
}

void print_dataframe(const DATAFRAME *dataframe) {
    if(dataframe == NULL) {
        printf("Data frame is NULL!\n");
        return;
    }

    const ListNode *current = dataframe->head;
    while(current != NULL) {
        print_column(current->column);
        current = current->next;
    }
}

void delete_dataframe(DATAFRAME **dataframe) {
    if(dataframe == NULL || *dataframe == NULL) {
        printf("Data frame is NULL!\n");
        return;
    }

    delete_list(*dataframe);
    free(*dataframe);
    *dataframe = NULL;
}