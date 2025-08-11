#include <stdio.h>
#include <stdlib.h>
#include "commandline.h"
#include "validinput.h"

#define addressOf(x) (&x)
#define valueAt(x) (*x)

/*
The function gets input from the command line
It takes the following parameters:
**args = The address where the arguments from the command line are stored, *num_rows = The address of where the number of rows is stored 
*num_columns = The address of where the number of columns is stored, *num_pieces = The address of where the number of pieces needed to win is stored
*/
void GetCommandLineInput(char** args, int* num_rows, int* num_columns, int* num_pieces){ 
    sscanf(args[1], "%d", num_rows);
    sscanf(args[2], "%d", num_columns);
    sscanf(args[3], "%d", num_pieces);
    CommandLineValidInput(valueAt(num_rows), valueAt(num_columns), valueAt(num_pieces));
}

/*
The function checks if there are a right amount of arguments in the command line
It takes the following parameters:
num_args = The number of arguments read from the command line, **args = The address where the arguments from the command line are stored, 
*num_rows = The address of where the number of rows is stored, *num_columns = The address of where the number of columns is stored
*num_pieces = The address of where the number of pieces needed to win is stored
*/
void CheckNumArgs(int num_args, char** args, int* rows, int* columns, int* num_pieces){
    if(num_args < 4){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    else if(num_args>4){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    else{
        GetCommandLineInput(args, rows, columns, num_pieces);
    }
}