//
// Created by sohukia on 4/7/2024.
//

#ifndef CDATAFRAME_TYPES_H
#define CDATAFRAME_TYPES_H

typedef enum
{
    NULLVAL = 0, UINT, INT, CHAR, FLOAT, DOUBLE, STRING
} DataType;

typedef union
{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
} Value;

typedef struct
{
    DataType datatype;
    Value value;
} COLUMN_TYPE;

struct column
{
    unsigned long long index;

    char *title;
    unsigned int max_size;
    unsigned int size;
    DataType datatype;
    COLUMN_TYPE *data;
};
typedef struct column Column;

// Double linked list implementation
typedef struct Node_ {
    Column* data;
    struct Node_* next;
    struct Node_* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} List;

typedef struct {
    List columns;
} DataFrame;

typedef DataType ENUM_TYPE;

#endif //CDATAFRAME_TYPES_H
