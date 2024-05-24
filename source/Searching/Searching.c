//
// Created by sohukia on 4/5/2024.
//

#include "Searching.h"
#include <stdio.h>
#include <string.h>

int count_occurrences(const Column *column, void *value)
{
    int count = 0;

    if (column == NULL || value == NULL)
    {
        printf("Error: invalid argument\n");
        return -1;
    }

    for (int i = 0; i < column->size; i++)
    {
        switch (column->datatype)
        {
            case UINT:
                if (column->data[i].value.uint_value == *(unsigned int *) value)
                {
                    count++;
                }
                break;
            case INT:
                if (column->data[i].value.int_value == *(int *) value)
                {
                    count++;
                }
                break;
            case CHAR:
                if (column->data[i].value.char_value == *(char *) value)
                {
                    count++;
                }
                break;
            case FLOAT:
                if (column->data[i].value.float_value == *(float *) value)
                {
                    count++;
                }
                break;
            case DOUBLE:
                if (column->data[i].value.double_value == *(double *) value)
                {
                    count++;
                }
                break;
            case STRING:
                if (strcmp(column->data[i].value.string_value, (char *) value) == 0)
                {
                    count++;
                }
                break;
            default:
                break;
        }
    }
    return count;
}

int get_position(const Column *column, void *value)
{
    int pos = 0;
    if (column == NULL || value == NULL)
    {
        printf("Error: invalid argument\n");
        return -1;
    }

    for (int i=0; i < column->size; i++ )
    {
        switch(column->datatype)
        {
            case UINT:
                if (column->data[i].value.uint_value == *(unsigned int *) value)
                {
                    pos = i;
                }
                break;
            case INT:
                if (column->data[i].value.int_value == *(int *) value)
                {
                    pos = i;
                }
                break;
            case CHAR:
                if (column->data[i].value.char_value == *(char *) value)
                {
                    pos = i;
                }
                break;
            case FLOAT:
                if (column->data[i].value.float_value == *(float *) value)
                {
                    pos = i;
                }
                break;
            case DOUBLE:
                if (column->data[i].value.int_value == *(double *) value)
                {
                    pos = i;
                }
                break;
            case STRING:
                if (strcmp(column->data[i].value.string_value, (char *) value) == 0)
                {
                    pos = i;
                }
                break;
            default:
                break;
        }
    }
    return pos;
}

int count_greater_than(const Column *column, void *value, const int size)
{
    if (column == NULL || value == NULL)
    {
        printf("Error: invalid argument\n");
        return -1;
    }

    int count = 0;

    for (int i = 0; i < column->size; i++)
    {
        switch (column->datatype)
        {
            case UINT:
                if (sizeof(unsigned int) != size)
                {
                    printf("Error: value has wrong size\n");
                    return -1;
                }
                if (column->data[i].value.uint_value > *(unsigned int *) value)
                {
                    count++;
                }
                break;
            case INT:
                if (sizeof(int) != size)
                {
                    printf("Error: value has wrong size\n");
                    return -1;
                }
                if (column->data[i].value.int_value > *(int *) value)
                {
                    count++;
                }
                break;
            case CHAR:
                if (sizeof(char) != size)
                {
                    printf("Error: value has wrong size\n");
                    return -1;
                }
                if (column->data[i].value.char_value > *(char *) value)
                {
                    count++;
                }
                break;
            case FLOAT:
                if (sizeof(float) != size)
                {
                    printf("Error: value has wrong size\n");
                    return -1;
                }
                if (column->data[i].value.float_value > *(float *) value)
                {
                    count++;
                }
                break;
            case DOUBLE:
                if (sizeof(double) != size)
                {
                    printf("Error: value has wrong size\n");
                    return -1;
                }
                if (column->data[i].value.double_value > *(double *) value)
                {
                    count++;
                }
                break;
            case STRING:
                if (size < 0)
                {
                    printf("Error: invalid size\n");
                    return -1;
                }
                if (strcmp(column->data[i].value.string_value, (char *) value) > 0)
                {
                    count++;
                }
                break;
            default:
                break;
        }
    }

    return count;
}

int count_less_than_recursive(const Column *column, void *value, const int size, int i)
{
    if (i >= column->size)
    {
        return 0;
    }

    switch (column->datatype)
    {
        case UINT:
            if (sizeof(unsigned int) != size)
            {
                printf("Error: value has wrong size\n");
                return -1;
            }
            if (column->data[i].value.uint_value < *(unsigned int *) value)
            {
                return 1 + count_less_than_recursive(column, value, size, i + 1);
            }
            break;
        case INT:
            if (sizeof(int) != size)
            {
                printf("Error: value has wrong size\n");
                return -1;
            }
            if (column->data[i].value.int_value < *(int *) value)
            {
                return 1 + count_less_than_recursive(column, value, size, i + 1);
            }
            break;
        case CHAR:
            if (sizeof(char) != size)
            {
                printf("Error: value has wrong size\n");
                return -1;
            }
            if (column->data[i].value.char_value < *(char *) value)
            {
                return 1 + count_less_than_recursive(column, value, size, i + 1);
            }
            break;
        case FLOAT:
            if (sizeof(float) != size)
            {
                printf("Error: value has wrong size\n");
                return -1;
            }
            if (column->data[i].value.float_value < *(float *) value)
            {
                return 1 + count_less_than_recursive(column, value, size, i + 1);
            }
            break;
        case DOUBLE:
            if (sizeof(double) != size)
            {
                printf("Error: value has wrong size\n");
                return -1;
            }
            if (column->data[i].value.double_value < *(double *) value)
            {
                return 1 + count_less_than_recursive(column, value, size, i + 1);
            }
            break;
        case STRING:
            if (size < 0)
            {
                printf("Error: invalid size\n");
                return -1;
            }
            if (strcmp(column->data[i].value.string_value, (char *) value) < 0)
            {
                return 1 + count_less_than_recursive(column, value, size, i + 1);
            }
            break;
        default:
            break;
    }

    return count_less_than_recursive(column, value, size, i + 1);
}

int count_less_than(const Column *column, void *value, const int size)
{
    if (column == NULL || value == NULL)
    {
        printf("Error: invalid argument\n");
        return -1;
    }

    return count_less_than_recursive(column, value, size, 0);
}

Node *search_by_name(const DataFrame *df, const char *title) {
    Node *current = df->columns.head;
    while (current != NULL)
    {
        if (strcmp(current->data->title, title) == 0)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int get_dataframe_size(const DataFrame *df) {
    int size = 0;
    const Node *current = df->columns.head;
    while (current != NULL)
    {
        size++;
        current = current->next;
    }
    return size;
}

int get_dataframe_max_rows(const DataFrame *df) {
    int max_rows = 0;
    const Node *current = df->columns.head;
    while (current != NULL)
    {
        if (current->data->size > max_rows)
        {
            max_rows = current->data->size;
        }
        current = current->next;
    }
    return max_rows;
}

Column *get_column(const DataFrame *df, const int index) {
    if (index < 0)
    {
        printf("Error: invalid index\n");
        return NULL;
    }

    const Node *current = df->columns.head;
    for (int i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            printf("Error: index out of bounds\n");
            return NULL;
        }
        current = current->next;
    }
    return current->data;
}

DataType get_column_type(const DataFrame *df, const int index) {
    if (index < 0)
    {
        printf("Error: invalid index\n");
        return -1;
    }

    const Node *current = df->columns.head;
    for (int i = 0; i < index; i++)
    {
        if (current == NULL)
        {
            printf("Error: index out of bounds\n");
            return -1;
        }
        current = current->next;
    }
    return current->data->datatype;
}