//
// Created by sohukia on 4/7/2024.
//

#ifndef CDATAFRAME_TYPES_H
#define CDATAFRAME_TYPES_H

typedef enum
{
    NULLVAL = 1, UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCT
} DataType;

typedef union
{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
} Value;

typedef struct
{
    DataType datatype;
    Value value;
} COLUMN_TYPE;

struct column
{
    unsigned long long *index;
    // index validity 0 - no index, -1 - index is invalid, 1 - index is valid
    int valid_index;
    // sorting direction 0 - ascending, 1 - descending
    int sort_direction;

    char *title;
    unsigned int max_size;
    unsigned int size;
    DataType datatype;
    COLUMN_TYPE **data;
};
typedef struct column Column;


// Double linked list implementation

typedef struct list_node_
{
    Column *column;
    struct list_node_ *prev;
    struct list_node_ *next;
} ListNode;

typedef struct
{
    ListNode *head;
    ListNode *tail;
    unsigned int size;
} List;

typedef List DATAFRAME;

typedef DataType ENUM_TYPE;

#endif //CDATAFRAME_TYPES_H
