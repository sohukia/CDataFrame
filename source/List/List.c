//
// Created by denni on 25/04/2024.
//

#include "List.h"
#include "../Column/Column.h"

ListNode *create_list_node(Column *column) {
    ListNode *node = (ListNode*) malloc(sizeof(ListNode));
    if(node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    node->column = column;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void insert_list_node(List *list, Column *column) {
    ListNode *node = create_list_node(column);
    if(node == NULL) return;

    if(list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }

    list->size++;
}

void insert_head(List *list, Column *column) {
    ListNode *node = create_list_node(column);
    if(node == NULL) return;

    if(list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }

    list->size++;
}

void insert_after(List *list, ListNode *node, Column *column) {
    if(node == NULL) {
        printf("Node is NULL!\n");
        return;
    }

    ListNode *new_node = create_list_node(column);
    if(new_node == NULL) return;

    new_node->next = node->next;
    node->next = new_node;

    list->size++;
}

void delete_list_node(List *list, ListNode *node) {
    if(node) {
        if(node->prev) {
            node->prev->next = node->next;
        } else {
            list->head = node->next;
        }
        delete_column(&node->column);
        free(node);
        list->size--;
    }
}

void delete_list(List *list) {
    ListNode *current = list->head;

    while(list->size > 0 && current != NULL) {
        ListNode *next = current->next;
        delete_list_node(list, current);
        current = next;
    }

    list->head = NULL;
    free(list);
}