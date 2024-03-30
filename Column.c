#include "Column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256

Column *create_column(TYPE type, char *title)
{
  Column *to_create = (Column *)malloc(sizeof(Column));
  if (to_create == NULL) return NULL;

  to_create->index = NULL;
  #include <string.h> // Include the appropriate header file

  to_create->title = strdup(title);
  if (to_create->title == NULL) // failed to create a column
  {
    free(to_create);
    return NULL;
  }
  to_create->max_size = REALLOC_SIZE;
  to_create->size = 0;
  to_create->datatype = type;
  to_create->data = NULL;

  return to_create;
}

int insert_value(Column *column, void *value)
{
  // check if we can insert
  if (column->size >= column->max_size) return 0;

  // allocate memory
  COLUMN_TYPE *new_value = (COLUMN_TYPE *)malloc(sizeof(COLUMN_TYPE));
  if (new_value == NULL) return 0; // failed to allocate memory


  switch (column->datatype)
  {
    case UINT:
      new_value->uint_value = *(unsigned int *)value;
      break;
    case INT:
      new_value->int_value = *(int *)value;
      break;
    case CHAR:
      new_value->char_value = *(char *)value;
      break;
    case FLOAT:
      new_value->float_value = *(float *)value;
      break;
    case DOUBLE:
      new_value->double_value = *(double *)value;
      break;
    case STRING:
      new_value->string_value = strdup((char *)value);
      if (new_value->string_value == NULL) // failed to allocate string memory
      {
        free(new_value);
        return 0;
      }
      break;
    case STRUCT:
      new_value->struct_value = value;
      break;
    default: // failed to allocate memory for new value
      free(new_value);
      break;
  }

  column->data[column->size] = new_value;
  column->size++;

  return 1;

}

void convert_value (Column *column, unsigned long long int i, char *str, int size)
{
  int j;
  switch(column->datatype)
  {
    case UINT: 
      j = snprintf(str, size, "%u\n", ((unsigned int*)column->data)[i]);
      break;
    case INT:
      j = snprintf(str, size, "%d\n", ((int*)column->data)[i]);
      break;  
    case CHAR: 
      j = snprintf(str, size, "%c\n", ((char*)column->data)[i]);
      break; 
    case FLOAT: 
      j = snprintf(str, size, "%f\n", ((float*)column->data)[i]);
      break;
    case DOUBLE:
      j = snprintf(str, size, "%lf\n", ((double*)column->data)[i]);
      break;
    case STRING:
      j = snprintf(str, size, "%s\n", ((char**)column->data)[i]);
      break;    
    default:
      return;
  }
}