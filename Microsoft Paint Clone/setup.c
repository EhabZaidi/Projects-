#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "setup.h"

/*
The following function checks whether the input is valid or not
It takes the following variables as parameters:
num_args_needed = The number of arguments to be read, num_args_read = The actual number of arguments read
should_be_last_value_one_line = True or false depeding on if the input needs to be the last value on the line or not
It return true or false
*/
bool isValidInput(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line){
    bool format_is_correct = num_args_read == num_args_needed;
    if(should_be_last_value_on_line){
        char should_be_newline = ' ';
        scanf("%c", &should_be_newline);
        format_is_correct = format_is_correct && should_be_newline == '\n';
    }
    return format_is_correct;  
}

/*
The following function recieves the command line values
It takes the following values as parameters:
rows = The address of the number of rows of the canvas, columns = The address of the number of columns of the canvas
argv = The values on the command line
It does not return anything
*/
void GetCommandLineValues(int* rows, int* columns, char** argv){
    sscanf(argv[1], "%d", rows);
    sscanf(argv[2], "%d", columns);

    if(*rows<0){
        printf("The number of rows is less than 1.\n");
        printf("Making default board of 10 X 10.\n");
        *rows = 10;
        *columns = 10;
    }
    if(*columns<0){
        printf("The number of columns is less than 1.\n");
        printf("Making default board of 10 X 10.\n");
        *rows = 10;
        *columns = 10;
    }
}

/*
The following function sets up the canvas
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, rows = The address of the number of rows of the canvas 
columns = The address of the number of columns of the canvas
It does not return anything
*/
void SetUpCanvas(int* rows, int* columns, Grid* canvas){
    canvas->rows = *rows;
    canvas->columns = *columns;

    canvas->grid = (char**)malloc(canvas->rows * sizeof(char*));
    for(int i = 0; i<canvas->rows; i++){
        canvas->grid[i] = (char*)malloc(canvas->columns* sizeof(char));
        for(int j = 0; j<canvas->columns; j++){
            canvas->grid[i][j] = '*';
        }
    }
}

/*
The following function prints the canvas to the user
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void PrintCanvas(Grid* canvas){
    for(int i = canvas->rows-1; i>=0; i--){
        printf("%d  ", i);
        for(int j = 0; j<canvas->columns; j++){
            printf("%c  ", canvas->grid[i][j]);
        }
        printf("\n");
    }

    printf("   ");
    for(int j = 0; j<canvas->columns;j++){
        printf("%d  ", j);
    }
    printf("\n");
}