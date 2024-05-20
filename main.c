#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "source/CDataFrame/CDataFrame.h"
#include "source/Column/Column.h"
#include "source/Menu/menu.h"
#include "source/types.h"
#include "source/Sorting/Sorting.h"
#include "source/Searching/Searching.h"

int main() {
    // Créer un DataFrame vide
    DataFrame df = create_empty_dataframe();

    // Ajouter des colonnes au DataFrame
    Column *col1 = create_column("Colonne 1", 5, UINT);
    Column *col2 = create_column("Colonne 2", 5, FLOAT);
    Column *col3 = create_column("Colonne 3", 5, STRING);
    insert_column(&df, col1);
    insert_column(&df, col2);
    insert_column(&df, col3);

    // Ajouter des données aux colonnes
    COLUMN_TYPE *data1 = malloc(sizeof(COLUMN_TYPE));
    data1->datatype = UINT;
    data1->value.uint_value = 10;
    add_data(col1, data1);
    COLUMN_TYPE *data2 = malloc(sizeof(COLUMN_TYPE));
    data2->datatype = FLOAT;
    data2->value.float_value = 3.14;
    add_data(col2, data2);
    COLUMN_TYPE *data3 = malloc(sizeof(COLUMN_TYPE));
    data3->datatype = STRING;
    data3->value.string_value = strdup("Hello, World!");
    add_data(col3, data3);

    // Ajouter une deuxième ligne de données
    COLUMN_TYPE *data4 = malloc(sizeof(COLUMN_TYPE));
    data4->datatype = UINT;
    data4->value.uint_value = 20;
    add_data(col1, data4);
    COLUMN_TYPE *data5 = malloc(sizeof(COLUMN_TYPE));
    data5->datatype = FLOAT;
    data5->value.float_value = 2.71;
    add_data(col2, data5);
    COLUMN_TYPE *data6 = malloc(sizeof(COLUMN_TYPE));
    data6->datatype = STRING;
    data6->value.string_value = strdup("Bonjour, Monde!");
    add_data(col3, data6);

    // Ajouter une troisième ligne de données
    COLUMN_TYPE *data7 = malloc(sizeof(COLUMN_TYPE));
    data7->datatype = UINT;
    data7->value.uint_value = 30;
    add_data(col1, data7);
    COLUMN_TYPE *data8 = malloc(sizeof(COLUMN_TYPE));
    data8->datatype = FLOAT;
    data8->value.float_value = 1.41;
    add_data(col2, data8);
    COLUMN_TYPE *data9 = malloc(sizeof(COLUMN_TYPE));
    data9->datatype = STRING;
    data9->value.string_value = strdup("Hola, Mundo!");
    add_data(col3, data9);

    // Ajouter une quatrième ligne de données
    COLUMN_TYPE *data10 = malloc(sizeof(COLUMN_TYPE));
    data10->datatype = UINT;
    data10->value.uint_value = 40;
    add_data(col1, data10);
    COLUMN_TYPE *data11 = malloc(sizeof(COLUMN_TYPE));
    data11->datatype = FLOAT;
    data11->value.float_value = 0.71;
    add_data(col2, data11);
    COLUMN_TYPE *data12 = malloc(sizeof(COLUMN_TYPE));
    data12->datatype = STRING;
    data12->value.string_value = strdup("Ciao, Mondo!");
    add_data(col3, data12);

    // Ajouter une cinquième ligne de données
    COLUMN_TYPE *data13 = malloc(sizeof(COLUMN_TYPE));
    data13->datatype = UINT;
    data13->value.uint_value = 50;
    add_data(col1, data13);
    COLUMN_TYPE *data14 = malloc(sizeof(COLUMN_TYPE));
    data14->datatype = FLOAT;
    data14->value.float_value = 1.71;
    add_data(col2, data14);
    COLUMN_TYPE *data15 = malloc(sizeof(COLUMN_TYPE));
    data15->datatype = STRING;
    data15->value.string_value = strdup("Hello, Universe!");
    add_data(col3, data15);

    // Afficher le DataFrame
    print_dataframe(&df);

    // Trier une colonne du DataFrame
    COLUMN_TYPE **arr = malloc(sizeof(COLUMN_TYPE *) * col1->max_size);
    for (int i = 0; i < col1->max_size; i++) {
        arr[i] = &(col1->data[i]);
    }
    quicksort(arr, UINT, 0, col1->max_size - 1);
    free(arr);

    // Rechercher une valeur dans une colonne du DataFrame
    unsigned int value = 10;
    int count = count_occurrences(col1, &value);
    printf("La valeur %u apparait %d fois dans la colonne 1.\n", value, count);

    // Libérer la mémoire allouée
    delete_dataframe(&df);
    free(data1);
    free(data2);
    free(data3);
    free(data4);
    free(data5);
    free(data6);
    free(data7);
    free(data8);
    free(data9);
    free(data10);
    free(data11);
    free(data12);
    free(data13);
    free(data14);
    free(data15);
}