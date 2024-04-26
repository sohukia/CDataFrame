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
 * @param tail: the tail of the list
 * @param column: the column to insert
 */
void insert_list_node(ListNode **tail, Column *column);

/**
 * @brief Inserts a node at the head of a linked list
 * @param head: the head of the list
 * @param column: the column to insert
 */
void insert_head(ListNode **head, Column *column);

void insert_after(ListNode *node, Column *column);



//
// Deletion
//
/**
 * @brief Deletes a node from a linked list
 * @param node: the node to delete
 */
void delete_list_node(ListNode *node);

/**
 * @brief Deletes a linked list
 * @param head: the head of the list
 */
void delete_list(ListNode **head);

#endif //CDATAFRAME_LIST_H
