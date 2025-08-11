#include <stdio.h>
#include <stdlib.h>
#include "setup.h"

#define addressOf(x) (&x)
#define valueAt(x) (*x)

/*
The function sets up the starting grid
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored,
*/
char** SetUpGrid(int* num_rows, int* num_columns){
char** grid = (char**)malloc(valueAt(num_rows)*sizeof(char*));
for(int i = 0; i<valueAt(num_rows); i++){
    grid[i] = (char*)malloc(valueAt(num_columns)*sizeof(char));
    for(int j = 0; j<valueAt(num_columns); j++){
        grid[i][j] = '*';
    }
}
return grid;
}

/*
The function prints the current grid
It takes the following parameters:
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
**grid = The address of the grid used to play connect-n
*/
void PrintGrid(int* num_rows, int* num_columns, char** grid){
    for(int i = valueAt(num_rows)-1; i>=0; --i){
        printf("%d ", i);
        for(int j = 0; j<valueAt(num_columns); j++){
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    
    printf("  ");
    for(int j=0; j<valueAt(num_columns); j++){
        printf("%d ", j);
    }
}