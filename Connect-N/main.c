/* The following program plays Connect-n between 2 players*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "commandline.h"
#include "setup.h"
#include "game.h"


int main(int argc, char** argv){
    int rows;
    int columns;
    int pieces;

    CheckNumArgs(argc, argv, &(rows), &(columns), &(pieces));
    
    char** grid = SetUpGrid(&rows, &columns);
    PrintGrid(&rows, &columns, grid);

    PlayGame(&rows, &columns, &pieces, grid);
    free(*grid);
    free(grid);
    grid = NULL;

    return 0;
}