/*The following program makes the user paint on a canvas*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "setup.h"
#include "commands.h"

int main(int argc, char** argv){
    int rows, columns;
    Grid canvas;
    if(argc==3){
    GetCommandLineValues(&rows, &columns, argv);
    }
    else if(argc!= 1){
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        printf("Making default board of 10 X 10.\n");
        rows = 10;
        columns = 10;
    }
    else{
        rows = 10;
        columns = 10;
    }
    SetUpCanvas(&rows, &columns, &canvas);
    PrintCanvas(&canvas);

    Paint(&canvas);


    return 0;
}