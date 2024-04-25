//
// Created by denni on 25/04/2024.
//

#ifndef CDATAFRAME_NODE_H
#define CDATAFRAME_NODE_H
#include <stdio.h>
#include <stdlib.h>

typedef  struct node {
    void *data; //pointer to a column
    struct node *prev;
    struct node *next;
} NODE;

typedef struct list {
    struct node *head;
    struct node *tail;
} LIST;

typedef enum {INT, CHAR, FLOAT}ENUM_TYPE;

typedef struct {
    ENUM_TYPE type;
    void *data;
    int size;
}CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size) {
    CDATAFRAME *cdf = (CDATAFRAME*) malloc(sizeof(CDATAFRAME));
    if(!cdf) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    cdf->type = *cdftype;
    cdf->size = size;

    // Allocate memory based on the type
    switch(*cdftype) {
        case INT:
            cdf->data = malloc(sizeof(int) * size);
            break;
        case CHAR:
            cdf->data = malloc(sizeof(char) * size);
            break;
            // Add more cases as needed
        default:
            printf("Invalid type!\n");
            free(cdf);
            return NULL;
    }

    if(!cdf->data) {
        printf("Memory allocation failed!\n");
        free(cdf);
        return NULL;
    }

    return cdf;
}

#endif //CDATAFRAME_NODE_H
