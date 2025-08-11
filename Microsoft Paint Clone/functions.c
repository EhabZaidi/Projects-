#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "commands.h"
#include "setup.h"

/*
The following function prints the help statements for the user
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Help(Grid* canvas){
  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
  PrintCanvas(canvas);
}

/*
The following function quits the program
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Quit(Grid* canvas){
    Free_Grid(canvas);
    exit(0);
}

/*
The following function frees the 2D array
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Free_Grid(Grid* canvas){
    for(int i = 0; i<canvas->rows; i++){
            free(canvas->grid[i]);
    }
    free(canvas->grid);
}

/*
The following function erases a certain character
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Erase(Grid* canvas){
    int row, col;
    int num_args_read_1 = scanf(" %d", &row);
    int num_args_read_2 = scanf(" %d", &col);
    if(!isValidInput(1, num_args_read_1, false)|| !isValidInput(1, num_args_read_2, false) || row<0 || col<0){
        printf("Improper erase command.\n");
        return;
    }
    canvas->grid[row][col] = '*';
    PrintCanvas(canvas);
}

/*
The following function resizes the grid
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Resize(Grid* canvas){
    int num_rows, num_cols;
    int num_args_read_1 = scanf(" %d", &num_rows);
    int num_args_read_2 = scanf(" %d", &num_cols);
    if(!isValidInput(1, num_args_read_1, false) || !isValidInput(1, num_args_read_2, false) ||num_rows<0 || num_cols<0){
        printf("Improper resize command.\n");
        return;
    }
    canvas->grid = (char**)realloc(canvas->grid, num_rows*sizeof(char*));
    for(int i = 0; i<num_rows; i++){
        canvas->grid[i] = (char*)realloc(canvas->grid[i], num_cols*sizeof(char*));
    }
    if(canvas->rows<num_rows){
        for(int i = canvas->rows; i<num_rows; i++){
            for(int j = 0; j<canvas->columns; j++){
                canvas->grid[i][j] = '*';
            }
        }
    }
    canvas->rows = num_rows;
    if(canvas->columns<num_cols){
        for(int i = 0; i<canvas->rows; i++){
            for(int j = canvas->columns; j<num_cols; j++){
                canvas->grid[i][j] = '*';
            }
        }
    }
    canvas->columns = num_cols;
    PrintCanvas(canvas);
}

/*
The following function adds either a row or column
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Add(Grid* canvas){
    char c;
    int pos;
    int num_args_read_1 = scanf(" %c", &c);
    int num_args_read_2 = scanf(" %d", &pos);
    if(!isValidInput(1, num_args_read_1, false) || !isValidInput(1, num_args_read_2, false) ||pos<0 || pos>canvas->rows || pos>canvas->columns){
        printf("Improper add command.\n");
        return;
    }
    if(c == 'r'){
        Add_Row(canvas, pos);
    }
    else if(c == 'c'){
        Add_Column(canvas, pos);
    }
    else{
        printf("Improper add command.\n");
        return;
    }
    PrintCanvas(canvas);
}

/*
The following function adds a row
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, pos = The position of the row to add
It does not return anything
*/
void Add_Row(Grid* canvas, int pos){
   canvas->rows = canvas->rows + 1;
    canvas->grid = (char**)realloc(canvas->grid,canvas->rows*sizeof(char*));

    for ( int i = canvas->rows - 1 ; i > pos ; i-- ){
      canvas->grid[i] = canvas->grid[i-1]; 
    }

    canvas->grid[pos] = (char*)malloc(canvas->columns*sizeof(char));
    for ( int j = 0; j < canvas->columns; j++ ){
      canvas->grid[pos][j] = '*';
    }
  }

/*
The following function adds a column to the canvas
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, pos = The position of the column to add
It does not return anything
*/
void Add_Column(Grid* canvas, int pos){
    canvas->columns++;
    for(int i = 0; i<canvas->rows;i++){
        canvas->grid[i] = (char*)realloc(canvas->grid[i], canvas->columns+1*sizeof(char));
        for(int j = canvas->columns-1; j>=pos; j--){
            if(j == pos){
                canvas->grid[i][pos] = '*';
            }
            else{
                canvas->grid[i][j] = canvas->grid[i][j-1];
            }
        }
    }
}

/*
The following function deletes a row or column
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Delete(Grid* canvas){
    char c;
    int pos;
    int num_args_read_1 = scanf(" %c", &c);
    int num_args_read_2 = scanf(" %d", &pos);
    if(!isValidInput(1, num_args_read_1, false) || !isValidInput(1, num_args_read_2, false) || pos<0 || pos>canvas->rows || pos>canvas->columns){
        printf("Improper delete command.\n");
        return;
    }
    if(c == 'r'){
        Delete_Row(canvas, pos);
    }
    else if(c == 'c'){
        Delete_Column(canvas, pos);
    }
    else{
        printf("Improper delete command.\n");
    }
    PrintCanvas(canvas);
}

/*
The following function deletes a row
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, pos = The position of the row to delete
It does not return anything
*/
void Delete_Row(Grid* canvas, int pos){
    for(int i = pos; i<canvas->rows-1; i++){
        for(int j = 0; j<canvas->columns; j++){
            canvas->grid[i][j] = canvas->grid[i+1][j];
        }
    }

    canvas->grid = (char**)realloc(canvas->grid, (--canvas->rows)*sizeof(char*));
}

/*
The following function deletes a column
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, pos = The position of the column to delete
It does not return anything
*/
void Delete_Column(Grid* canvas, int pos){
    for(int i = 0; i<canvas->rows; i++){
        for(int j = pos; j<canvas->columns-1; j++){
            canvas->grid[i][j] = canvas->grid[i][j+1];
        }
        canvas->grid[i] = (char*)realloc(canvas->grid[i], (canvas->columns-1)*sizeof(char));
    }
    canvas->columns -= 1;
}

/*
The following function saves the current canvas as a file
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Save(Grid* canvas){
    char file_name[1000];
    int num_args_read = scanf(" %s", file_name);
    if(!isValidInput(1, num_args_read, false)){
        printf("Improper save command or file could not be created.\n");
        return;
    }
    FILE* file = fopen(file_name, "w");

    fprintf(file, "%d %d\n", canvas->rows, canvas->columns);

    for(int i = 0; i<canvas->rows; i++){
        for(int j = 0; j<canvas->columns; j++){
            fprintf(file, "%c ",canvas->grid[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    PrintCanvas(canvas);
}

/*
The following function loads the canvas that was saved as a file
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Load(Grid* canvas){
    char load_file[1000];
    int num_args_read = scanf(" %s", load_file);
     if(!isValidInput(1, num_args_read, false)){
        printf("Improper load command or file could not be created.\n");
        return;
    }
    FILE* file = fopen(load_file, "r");
    fscanf(file, "%d %d", &canvas->rows, &canvas->columns);

    for(int i =0; i<canvas->rows; i++){
        for(int j = 0; j<canvas->columns; j++){
            fscanf(file, " %c", &canvas->grid[i][j]);
        }
    }
    fclose(file);
    PrintCanvas(canvas);
}