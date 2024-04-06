//
// Created by sohukia on 3/30/2024.
//

#ifndef CDATAFRAME_COLUMN_H
#define CDATAFRAME_COLUMN_H

#define REALLOC_SIZE 256
#define ASC 0
#define DESC 1

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


/**
 * @brief Constructor
 * @param : type of the column
 * @param : column title
 * @return : pointer to the newly created column
 */
Column *create_column(DataType type, char *title);

/**
 * @brief Insert value in a column
 * @param : pointer to a column
 * @param : value to add
 * @return : 1 if value added 0 otherwise
 */
int insert_value(Column *column, void *value);

/**
 * @brief  Free the space allocated by a column
 * @param : Pointer to the column
 */
void delete_column(Column **column);

/**
 * @brief : Convert a structure into a string
 * @param : Pointer to the structure
 * @return : String representation of the structure
 */
char *convert_struct(COLUMN_TYPE *struct_value);

/**
 * @brief Convert a value into a string
 * @param : Pointer to the column
 * @param : Position of the value in the data array
 * @param : The string in which the value will be written
 * @param : Maximum size of the string
 */
void convert_value(Column *column, unsigned long long int i, char *str, int size);

/**
 * @brief Print a column's content
 * @param : Pointer to the column
 */
void print_column(Column *column);

#endif //CDATAFRAME_COLUMN_H
