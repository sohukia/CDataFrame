//
// Created by denni on 25/04/2024.
//

#ifndef CDATAFRAME_LIST_H
#define CDATAFRAME_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "../types.h"

//
// Creation
//

/**
 * @brief A node in a linked list
 * @param column: the column bound to the node
 * @return a node with a column in it
 */
ListNode *create_list_node(Column *column);

/**
 * @brief Inserts a node into a linked list
 * @param list: the list in which to insert the node
 * @param column: the column to insert
 */
void insert_list_node(List *list, Column *column);

/**
 * @brief Inserts a node at the head of a linked list
 * @param list: the list in which to insert the node
 * @param column: the column to insert
 */
void insert_head(List *list, Column *column);

/**
 * @brief Inserts a node after a given node
 * @param list: the list in which to insert the node
 * @param node: the node to insert after
 * @param column: the column to insert
 */
void insert_after(List *list, ListNode *node, Column *column);



//
// Deletion
//
/**
 * @brief Deletes a node from a linked list
 * @param list: the list from which to delete the node
 * @param node: the node to delete
 */
void delete_list_node(List *list, ListNode *node);

/**
 * @brief Deletes a linked list
 * @param list: the list to delete
 */
void delete_list(List *list);

#endif //CDATAFRAME_LIST_H
