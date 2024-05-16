//
// Created by denni on 25/04/2024.
//

#ifndef CDATAFRAME_LIST_H
#define CDATAFRAME_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "../types.h"

/**
 * @brief create a new doubly linked list
 */
List create_list();

/**
 * @brief Inserts a node into a linked list
 * @param list: the list in which to insert the node
 * @param column: the column to insert
 */
void insert_in_list(List *list, Column *column);

/**
 * @brief deletes a node from a linked list
 * @param list: the list from which to delete the node
 * @param node: the node to delete
 */
void delete_node(List *list, Node *node);

/**
 * @brief deletes a linked list and frees all associated memory
 * @param list: the list to delete
 */
void free_list(List *list);

/**
 * @brief prints the contents of a linked list
 */
void print_list(const List *list);

#endif //CDATAFRAME_LIST_H
