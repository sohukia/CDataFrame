#include <stdio.h>
#include <string.h>

#include "source/CDataFrame/CDataFrame.h"
#include "source/Column/Column.h"
#include "source/Menu/menu.h"
#include "source/types.h"

int main() {
    // Create an empty DataFrame
    DataFrame df = create_empty_dataframe();

    // Start the menu
    menu(&df);

    // Free the DataFrame when done
    delete_dataframe(&df);

    return 0;
}