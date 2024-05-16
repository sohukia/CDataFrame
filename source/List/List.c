//
// Created by denni on 25/04/2024.
//

#include "List.h"
#include "../Column/Column.h"

List create_list() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

void insert_in_list(List *list, Column *column) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = column;
    newNode->next = NULL;
    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void delete_node(List *list, Node *node) {
    if (node == NULL) return;
    if (node == list->head) {
        list->head = node->next;
    }
    if (node == list->tail) {
        list->tail = node->prev;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    free_column(node->data);
    free(node);
}

void free_list(List *list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free_column(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
}

void print_list(const List *list) {
    const Node* current = list->head;
    while (current != NULL) {
        printf("%s\n", current->data->title);
        current = current->next;
    }
}