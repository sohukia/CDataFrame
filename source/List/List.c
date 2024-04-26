//
// Created by denni on 25/04/2024.
//

#include "List.h"
#include "../Column/Column.h"

ListNode *create_list_node(Column *column) {
    ListNode *node = (ListNode*) malloc(sizeof(ListNode));
    if(!node) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    node->column = column;
    node->next = NULL;

    return node;
}

void insert_list_node(ListNode **tail, Column *column) {
    ListNode *node = create_list_node(column);
    if(!node) {
        return;
    }

    if(*tail == NULL) {
        *tail = node;
        return;
    }

    ListNode *temp = *tail;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;
}

void insert_head(ListNode **head, Column *column) {
    ListNode *node = create_list_node(column);
    if(!node) {
        return;
    }

    node->next = *head;
    *head = node;
}

void delete_list_node(ListNode *node) {
    if(node) {
        delete_column(&node->column);
        free(node);
    }
}

void delete_list(ListNode **head) {
    ListNode *temp;
    while(*head) {
        temp = *head;
        *head = (*head)->next;
        delete_list_node(temp);
    }
}