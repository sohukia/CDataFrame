//
// Created by sohukia on 4/5/2024.
//

#include "Searching.h"
#include <stdio.h>
#include <string.h>

int count_occurrences(Column *column, void *value)
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
                if (column->data[i]->value.uint_value == *(unsigned int *) value)
                {
                    count++;
                }
                break;
            case INT:
                if (column->data[i]->value.int_value == *(int *) value)
                {
                    count++;
                }
                break;
            case CHAR:
                if (column->data[i]->value.char_value == *(char *) value)
                {
                    count++;
                }
                break;
            case FLOAT:
                if (column->data[i]->value.float_value == *(float *) value)
                {
                    count++;
                }
                break;
            case DOUBLE:
                if (column->data[i]->value.double_value == *(double *) value)
                {
                    count++;
                }
                break;
            case STRING:
                if (strcmp(column->data[i]->value.string_value, (char *) value) == 0)
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

int get_position(Column *column, void *value)
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
                if (column->data[i]->value.uint_value == *(unsigned int *) value)
                {
                    pos = i;
                }
                break;
            case INT:
                if (column->data[i]->value.int_value == *(int *) value)
                {
                    pos = i;
                }
                break;
            case CHAR:
                if (column->data[i]->value.char_value == *(char *) value)
                {
                    pos = i;
                }
                break;
            case FLOAT:
                if (column->data[i]->value.float_value == *(float *) value)
                {
                    pos = i;
                }
                break;
            case DOUBLE:
                if (column->data[i]->value.int_value == *(double *) value)
                {
                    pos = i;
                }
                break;
            case STRING:
                if (strcmp(column->data[i]->value.string_value, (char *) value) == 0)
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

int count_greater_than(Column *column, void *value, int size)
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
                if (column->data[i]->value.uint_value > *(unsigned int *) value)
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
                if (column->data[i]->value.int_value > *(int *) value)
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
                if (column->data[i]->value.char_value > *(char *) value)
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
                if (column->data[i]->value.float_value > *(float *) value)
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
                if (column->data[i]->value.double_value > *(double *) value)
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
                if (strcmp(column->data[i]->value.string_value, (char *) value) > 0)
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

int count_less_than(Column *column, void *value, int size)
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
                if (column->data[i]->value.uint_value < *(unsigned int *) value)
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
                if (column->data[i]->value.int_value < *(int *) value)
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
                if (column->data[i]->value.char_value < *(char *) value)
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
                if (column->data[i]->value.float_value < *(float *) value)
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
                if (column->data[i]->value.double_value < *(double *) value)
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
                if (strcmp(column->data[i]->value.string_value, (char *) value) < 0)
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

int count_equal_to(Column *column, void *value, int size)
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
                if (column->data[i]->value.uint_value == *(unsigned int *) value)
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
                if (column->data[i]->value.int_value == *(int *) value)
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
                if (column->data[i]->value.char_value == *(char *) value)
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
                if (column->data[i]->value.float_value == *(float *) value)
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
                if (column->data[i]->value.double_value == *(double *) value)
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
                if (strcmp(column->data[i]->value.string_value, (char *) value) == 0)
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
