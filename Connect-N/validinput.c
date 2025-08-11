#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "validinput.h"

/*
The function checks if the command line input is valid or not
It takes the following parameters:
rows = The number of rows in the grid, columns = The number of columns in the grid
pieces = The number of pieces needed to win
*/
void CommandLineValidInput(int rows, int columns, int pieces){
    if(!(rows>0 && columns>0 && pieces>0)){
        printf("Invalid arguments\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
}

/*
The function checks if the input given by the user is valid or not
It takes the following parameters:
num_args_needed = The number of arguments to read from the user, num_args_read = The number of arguments read from the user
*/
bool isValidInput(const int num_args_needed, const int num_args_read){
    bool format_is_correct = num_args_read == num_args_needed;
    char character;
    do{
        scanf("%c", &character);
        if(!isspace(character)){
            format_is_correct = false;
        }
    }while(character != '\n');
    return format_is_correct;
}