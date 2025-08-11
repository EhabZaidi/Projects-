#include <stdio.h>
#include <stdbool.h>
#include "write.h"
#include "commands.h"
#include "setup.h"

/*
The following function paints on the canvas
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints
It does not return anything
*/
void Perform_Write(Grid* canvas){
    Position position;
    int num_args_read_1 = scanf(" %d", &position.start_row);
    int num_args_read_2 = scanf(" %d", &position.start_column);
    int num_args_read_3 = scanf(" %d", &position.end_row);
    int num_args_read_4 = scanf(" %d", &position.end_column);
    if(!isValidInput(1, num_args_read_1, false) || !isValidInput(1, num_args_read_2, false) || !isValidInput(1, num_args_read_3, false) || !isValidInput(1, num_args_read_4, false) || position.start_row <0 || position.end_row<0 || position.start_column<0|| position.end_column<0){
        printf("Improper draw command.\n");
        return;
    }
    Check_Line(canvas, position);
}

/*
The following function checks whether to paint a horizontal, vertical or diagonal line
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, position = The address of the user-defined type that stores the start and end positions to draw
It does not return anything
*/
void Check_Line(Grid* canvas, Position position){
    if(Check_Horizontal(position)){
        PaintHorizontal(canvas, position);
    }
    else if(Check_Vertical(position)){
        PaintVertical(canvas, position);
    }
    else if(Check_Left_Diagonal(position)){
        PaintLeftDiagonal(canvas, position);
    }
    else if(Check_Right_Diagonal(position)){
        PaintRightDiagonal(canvas, position);
    }
    else{
        printf("Improper draw command.\n");
    }
}

/*
The following function checks whether to paint a horizontal line
It takes the following values as parameters:
position = The address of the user-defined type that stores the start and end positions to draw
It return either true or false
*/
bool Check_Horizontal(Position position){
    if(position.start_row == position.end_row){
        return true;
    }
    return false;
}

/*
The following function paints a horizontal line
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, position = The address of the user-defined type that stores the start and end positions to draw
It does not return anything
*/
void PaintHorizontal(Grid* canvas, Position position){
    if(position.start_column>position.end_column){
        for(int i = position.start_column; i >=position.end_column; i--){
            if (canvas->grid[position.start_row][i] != '*' && canvas->grid[position.start_row][i] != '-'){
                canvas->grid[position.start_row][i] = '+';
            }
            else{
                canvas->grid[position.start_row][i] = '-';
            }
        }
    }
    else if(position.start_column<position.end_column){
        for(int i = position.start_column; i <=position.end_column; i++){
            if (canvas->grid[position.start_row][i] != '*' && canvas->grid[position.start_row][i] != '-'){
                canvas->grid[position.start_row][i] = '+';
            }
            else{
                canvas->grid[position.start_row][i] = '-';
            }
        }
    }
    else{
        if(canvas->grid[position.start_row][position.start_column] != '*' && canvas->grid[position.start_row][position.start_column] != '-'){
            canvas->grid[position.start_row][position.start_column] = '+';
        }
        else{
            canvas->grid[position.start_row][position.start_column] = '-';
        }
    }
PrintCanvas(canvas);

}

/*
The following function checks whether to paint a vertical line
It takes the following values as parameters:
position = The address of the user-defined type that stores the start and end positions to draw
It return either true or false
*/
bool Check_Vertical(Position position){
    if(position.start_column == position.end_column && position.start_row != position.end_row){
        return true;
    }
    return false;
}

/*
The following function paints a vertical line
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, position = The address of the user-defined type that stores the start and end positions to draw
It does not return anything
*/

void PaintVertical(Grid* canvas, Position position){
    if(position.start_row>position.end_row){
        for(int i = position.start_row; i>=position.end_row; i--){
            if(canvas->grid[i][position.start_column] != '*' && canvas->grid[i][position.start_column] != '|'){
                canvas->grid[i][position.start_column] = '+';
            }
            else{
                canvas->grid[i][position.start_column] = '|';
            }
        }
    }
    else if(position.start_row<position.end_row){
        for(int i = position.start_row; i<=position.end_row; i++){
            if(canvas->grid[i][position.start_column] != '*' && canvas->grid[i][position.start_column] != '|'){
                canvas->grid[i][position.start_column] = '+';
            }
            else{
                canvas->grid[i][position.start_column] = '|';
            }
        }
    }
    PrintCanvas(canvas);
}

/*
The following function checks whether to paint a left diagonal
It takes the following values as parameters:
position = The address of the user-defined type that stores the start and end positions to draw
It return either true or false
*/
bool Check_Left_Diagonal(Position position){
    if((position.start_row-position.end_row) == (position.start_column - position.end_column)){
        return true;
    }
    return false;
}

/*
The following function paints a left diagonal
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, position = The address of the user-defined type that stores the start and end positions to draw
It does not return anything
*/
void PaintLeftDiagonal(Grid* canvas, Position position){
    if(position.start_row>position.end_row && position.start_column>position.end_column){
        int j = position.start_column;
        for(int i = position.start_row; i>=position.end_row; i--){
            if(canvas->grid[i][j] != '*' && canvas->grid[i][j] != '/'){
                canvas->grid[i][j] = '+';
            }
            else{
                canvas->grid[i][j] = '/';
            }
            j--;
        }
    }
    else if(position.start_row<position.end_row && position.start_column<position.end_column){
        int j = position.start_column;
        for(int i = position.start_row; i<=position.end_row; i++){
            if(canvas->grid[i][j] != '*' && canvas->grid[i][j] != '/'){
                canvas->grid[i][j] = '+';
            }
            else{
                canvas->grid[i][j] = '/';
            }
            j++;
        }
    }
    PrintCanvas(canvas);
}

/*
The following function checks whether to paint a right diagonal
It takes the following values as parameters:
position = The address of the user-defined type that stores the start and end positions to draw
It return either true or false
*/
bool Check_Right_Diagonal(Position position){
    if((position.start_row-position.end_row) == (-(position.start_column - position.end_column))){
        return true;
    }
    return false;
}

/*
The following function paints a right diagonal
It takes the following values as parameters:
canvas = The address of the user-defined datat type which holds the canvas on which the user paints, position = The address of the user-defined type that stores the start and end positions to draw
It does not return anything
*/
void PaintRightDiagonal(Grid* canvas, Position position){
    if(position.start_row>position.end_row && position.start_column<position.end_column){
        int j = position.start_column;
        for(int i = position.start_row; i>=position.end_row; i--){
            if(canvas->grid[i][j] != '*' && canvas->grid[i][j] != '\\'){
                canvas->grid[i][j] = '+';
            }
            else{
                canvas->grid[i][j] = '\\';
            }
            j++;
        }
    }
    else if(position.start_row<position.end_row && position.start_column>position.end_column){
        int j = position.start_column;
        for(int i = position.start_row; i<=position.end_row; i++){
            if(canvas->grid[i][j] != '*' && canvas->grid[i][j] != '\\'){
                canvas->grid[i][j] = '+';
            }
            else{
                canvas->grid[i][j] = '\\';
            }
            j--;
        }
    }
    PrintCanvas(canvas);
}